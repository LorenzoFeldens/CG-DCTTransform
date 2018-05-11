/**
*   Checkbox.cpp
*
*   Arquivo que controla o desenho dos checkboxes.
**/

#include "Checkbox.h"

Checkbox::Checkbox(int x, int y, char text[], int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
    lado = 10;
    posX = x;
    posY = y;
    texto = text;
    checado = 1;
}

void Checkbox::desenha(){
    int endX,endY;
    endX = posX+lado;
    endY = posY-lado;

    color(r,g,b);
    rect(posX, posY, endX, endY);
    text(endX+5, endY, texto);

    if(checado == 1){
        line(posX, posY, endX, endY);
        line(posX, endY, endX, posY);
    }
}

void Checkbox::ajustaPosY(int y){
    posY = y;
}

int Checkbox::isArea(int x, int y){
    int endX,endY;
    endX = posX+lado;
    endY = posY-lado;

    if(x>=posX && x<=endX &&
       y<=posY && y>=endY)
       return 1;
    return 0;
}

void Checkbox::check(int x){
    checado = x;
}

int Checkbox::isChecked(){
    return checado;
}
