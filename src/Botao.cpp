/**
*   Botao.cpp
*
*   Arquivo que controla o desenho dos botões.
**/

#include "Botao.h"

Botao::Botao(int x, int y, char text[]){
     altura = 25;
     largura = 90;
     posX = x;
     posY = y;
     texto = text;
     r = 157;
     g = 157;
     b = 157;
  }

void Botao::desenha(){
    int endX,endY;
    endX = posX+largura;
    endY = posY-altura;

    color(r,g,b);
    rectFill(posX+1, posY-1, endX-1, endY+1);
    color(0,0,0);
    rect(posX, posY, endX, endY);
    text(posX+5, posY-15, texto);
}

void Botao::ajustaPosY(int y){
    posY = y;
}

int Botao::isArea(int x, int y){
    int endX,endY;
    endX = posX+largura;
    endY = posY-altura;

    if(x>=posX && x<=endX &&
       y<=posY && y>=endY)
       return 1;
    return 0;
}
