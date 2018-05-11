/**
*   Main.cpp
*
*   Arquivo principal responsável pela chamada das criações da Canvas e
*   todos os componentes gráficos desenvolvidos.
*   - A função 'render' realiza a exibição em tempo real.
*   - A função 'redimensionar' realiza a atualização de valores atualizados
*   pelo redimensionamento.
*   - A função 'mouse' controla os cliques sobre botões e checkboxes.
**/

#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include "gl_canvas2d.h"

#include "Botao.h"
#include "Grafico.h"
#include "Checkbox.h"

Botao *b1 = NULL;
Botao *b2 = NULL;
Botao *b3 = NULL;
Botao *b4 = NULL;
Checkbox *c1 = NULL;
Checkbox *c2 = NULL;
Checkbox *c3 = NULL;
Grafico *g = NULL;

void render(){
    clear(255,255,255);
    b1->desenha();
    b2->desenha();
    b3->desenha();
    c1->desenha();
    c2->desenha();
    c3->desenha();
    g->desenhaGrafico();
}

void redimensionar(int l, int a){
    g->ajustarTamanho(l-20,a-55, getAlturaTela()-45);
    b1->ajustaPosY(getAlturaTela()-10);
    b2->ajustaPosY(getAlturaTela()-10);
    b3->ajustaPosY(getAlturaTela()-10);
    c1->ajustaPosY(getAlturaTela()-10);
    c2->ajustaPosY(getAlturaTela()-25);
    c3->ajustaPosY(getAlturaTela()-10);
}


void keyboard(int key){

}

void keyboardUp(int key){

}

void mouse(int button, int state, int wheel, int direction, int x, int y){
    if(button == 0 && state == 0){
        if(b1->isArea(x,y)==1){
            g->abreArquivo("samples.dct");
            g->enableReconst(0);
            g->enableDif(0);
            g->enableReceDif(0);
        }
        if(b2->isArea(x,y)==1){
            g->salvar();
        }
        if(b3->isArea(x,y)==1){
            g->aplicaDCTeIDCT();
            g->enableReceDif(1);
        }
        if(c1->isArea(x,y)==1){
            int x=1;
            if(c1->isChecked()==1)
                x=0;

            g->enableSamples(x);
            c1->check(x);
        }
        if(c2->isArea(x,y)==1){
            int x=1;
            if(c2->isChecked()==1)
                x=0;
            g->enableReconst(x);
            c2->check(x);
        }
        if(c3->isArea(x,y)==1){
            int x=1;
            if(c3->isChecked()==1)
                x=0;
            g->enableDif(x);
            c3->check(x);
        }
    }
}

int main(void){
   initCanvas(620,455, "Transformada Discreta de Cosseno - Lorenzo Feldens");

   b1 = new Botao(10,getAlturaTela()-10, "Carregar");
   b2 = new Botao(110,getAlturaTela()-10, "Salvar");
   b3 = new Botao(210,getAlturaTela()-10, "Aplicar");
   c1 = new Checkbox(310,getAlturaTela()-10, "Originais", 255, 0, 0);
   c2 = new Checkbox(310,getAlturaTela()-25, "Reconstruidos", 204, 204, 0);
   c3 = new Checkbox(470,getAlturaTela()-10, "Diferencas", 0, 153, 76);
   g = new Grafico(600,400,10,getAlturaTela()-45);

   runCanvas();
}


