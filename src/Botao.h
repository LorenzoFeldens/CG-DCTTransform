#ifndef __BOTAO_H__
#define __BOTAO_H__

#include "gl_canvas2d.h"

class Botao{
    int altura, largura, posX, posY;
    char* texto;
    float r, g, b; //cor

public:
    Botao(int x, int y, char text[]);
    void desenha();
    void ajustaPosY(int y);
    int isArea(int x, int y);
};

#endif

