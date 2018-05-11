/**
*   Grafico.cpp
*
*   Arquivo responsável pelo desenho e controle de dados
*   do gráfico.
*   - A função 'desenhaGráfico' cria o gráfico com tamanho
*   que varia de acordo com a janela.
*   - AS funções 'desenhaSamples', 'desenhaReconstruidos' e
*   'desenhaDiferencas' são executadas somente quando há dados
*   e os checkboxes estão habilitados.
**/

#include "Grafico.h"

Grafico::Grafico(int l, int a, int x, int y){
    largura = l;
    altura = a;
    iniX = x;
    iniY = y;
    meioY = iniY-altura/2;
    distX = 0;
    escala = (altura-10)/200.0;
    qtd = 0;

    recEdif = 0;
    showSamples=1;
    showReconst=0;
    showDif=0;

    arq = NULL;
    samples = NULL;
    reconstruidos = NULL;
}

void Grafico::abreArquivo(char *nome){
    arq = new Arquivo(nome);
    qtd = arq->getQuantidade();

    if(qtd>0){
        distX = (largura-10)/qtd;
    }

    samples = arq->getSamples();

    reconstruidos = (signed short*) malloc(qtd*sizeof(signed short));
    for(int i=0; i<qtd; i++)
        reconstruidos[i] = samples[i];

    desenhaGrafico();
}

void Grafico::desenhaGrafico(){
    color(224,224,224);
    rectFill(iniX,iniY,largura+iniX,iniY-altura);

    color(0,0,0);
    rect(iniX,iniY,largura+iniX,iniY-altura);
    line(iniX,meioY, largura+iniX, meioY);

    if(showSamples == 1)
        desenhaSamples();
    if(showReconst == 1 && recEdif == 1)
        desenhaReconstruidos();
    if(showDif == 1 && recEdif == 1)
        desenhaDiferencas();
}

void Grafico::desenhaSamples(){
    color(255,0,0);
    for(int i=0; i<qtd; i++){
        circleFill(iniX+5+(i+0.5)*distX, meioY+samples[i]*escala, 3, 15);
    }
}

void Grafico::desenhaReconstruidos(){
    color(204,204,0);
    for(int i=0; i<qtd; i++){
        circleFill(iniX+5+(i+0.5)*distX, meioY+reconstruidos[i]*escala, 3, 15);
    }
}

void Grafico::desenhaDiferencas(){
    color(0,153,76);
    for(int i=0; i<qtd; i++){
        circleFill(iniX+5+(i+0.5)*distX, meioY+(samples[i]-reconstruidos[i])*escala, 3, 15);
    }
}

void Grafico::ajustarTamanho(int l, int a, int y){
    largura = l;
    altura = a;
    iniY = y;
    meioY = iniY-altura/2;
    escala = (altura-10)/200.0;

    if(qtd>0){
        distX = (largura)/qtd;
    }

    desenhaGrafico();
}

void Grafico::enableSamples(int x){
    showSamples = x;
}

void Grafico::enableReconst(int x){
    showReconst = x;
}

void Grafico::enableDif(int x){
    showDif = x;
}

void Grafico::aplicaDCTeIDCT(){
    DCT dct = DCT(qtd, reconstruidos);
    reconstruidos = dct.aplicaDCTeIDCT();
    showReconst = 1;
    showDif = 1;
}

void Grafico::enableReceDif(int x){
    recEdif = x;
}

void Grafico::salvar(){
    arq->salvar(reconstruidos);
}
