//
// Created by Chase Balmos on 11/26/2018.
//

#ifndef GROUPPROJECT_PIXEL_H
#define GROUPPROJECT_PIXEL_H

class Pixels{
private:
    int r;
    int g;
    int b;
public:
    Pixels();
    Pixels(int, int, int);
    void setr(int);
    void setg(int);
    void setb(int);
    int getr();
    int getg();
    int getb();
};

#endif //GROUPPROJECT_PIXEL_H
