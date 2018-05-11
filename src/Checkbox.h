#ifndef __CHECKBOX_H__
#define __CHECKBOX_H__

#include "gl_canvas2d.h"

class Checkbox{
    int lado, posX, posY, checado, r, g, b;
    char* texto;

public:
    Checkbox(int x, int y, char text[], int red, int green, int blue);
    void desenha();
    void ajustaPosY(int y);
    int isArea(int x, int y);
    void check(int x);
    int isChecked();
};

#endif
