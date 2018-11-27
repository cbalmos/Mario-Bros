
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <zconf.h>
#include "SDL_Plotter.h"
#include "pixel.h"
using namespace std;

int main(int argc, char ** argv) {
    ifstream in;
    const int windowHeight = 436;
    const int windowWidth = 673;
    SDL_Plotter g(windowHeight, windowWidth);
    bool stopped = false;
    bool colored = false;
    int xd = 0, yd = 0;
    int R, G, B;
    int mariox = 20, marioy = 22;
    bool stoptitle = true;
    int rectPosX = 300;
    int rectPosY = 300;
    int width = 10;
    int height = 10;
    Pixels mario[mariox][marioy];
    in.open("marihoe.txt");

    string buffer;
    for (int f = 0; f < mariox; f++) {
        for (int h = 0; h < marioy; h++) {
            in >> R >> G >> B;
            mario[f][h].setr(R);
            mario[f][h].setg(G);
            mario[f][h].setb(B);
        }
        getline(in, buffer);
    }
    int sizex =200,sizey =16;
    ifstream floor;
    Pixels ground[sizey][sizex];
    floor.open("floor.txt");
    for (int range =0; range < sizey; range++){
        for(int hi =0; hi < sizex; hi++){
            floor >> R >> G >> B;
            ground[range][hi].setr(R);
            ground[range][hi].setg(G);
            ground[range][hi].setb(B);
        }
        getline(floor, buffer);
    }
    int baseline = 420;
floor.close();
    while (!g.getQuit()) //loop goes forever until user puts exit
    {g.clear();
        if (g.getKey() == UP_ARROW) {
            rectPosX = max(rectPosX - 3, 0);
        } else if (g.getKey() == DOWN_ARROW) {
            rectPosX = min(rectPosX + 2, baseline - marioy);
        } else if (g.getKey() == LEFT_ARROW) {
            rectPosY = max(rectPosY - 2, 0);
        } else if (g.getKey() == RIGHT_ARROW) {
            rectPosY = min(rectPosY + 2, windowWidth - marioy);
        }
        for(int x = baseline; x < sizey + baseline; x++){
            for(int y = 0; y <sizex; y++){
                g.plotPixel(y,x, ground[x-baseline][y].getr(),
                ground[x-baseline][y].getg(),ground[x-baseline][y].getb());
            }
        }
        for(int x = baseline; x < sizey + baseline; x++){
            for(int y = sizex; y <sizex + sizex; y++){
                g.plotPixel(y,x, ground[x-baseline][y-sizex].getr(),
                            ground[x-baseline][y-sizex].getg(),ground[x-baseline][y-sizex].getb());
            }
        }
        for(int x = baseline; x < sizey + baseline; x++){
            for(int y =400; y <sizex+400; y++){
                g.plotPixel(y,x, ground[x-baseline][y-400].getr(),
                            ground[x-baseline][y-400].getg(),ground[x-baseline][y-400].getb());
            }
        }
        for(int x = baseline; x < sizey + baseline; x++){
            for(int y =520; y <sizex+520; y++){
                g.plotPixel(y,x, ground[x-baseline][y-520].getr(),
                            ground[x-baseline][y-520].getg(),ground[x-baseline][y-520].getb());
            }
        }

        for(int col = rectPosX; col < 20 + rectPosX; col++){
            for(int row = rectPosY; row < 22 + rectPosY; row++){
                g.plotPixel(row, col, mario[col-rectPosX][row-rectPosY].getr(),
          mario[col-rectPosX][row-rectPosY].getg(),mario[col-rectPosX][row-rectPosY].getb());
            }
        }
            if (g.getKey() != UP_ARROW || rectPosX != baseline - mariox) {
                rectPosX = min(rectPosX + 2, baseline - mariox);
            }
            if (g.kbhit()) {
                g.getKey();
            }

            g.update();

        }

    }
