#ifndef __GRAFICO_H__
#define __GRAFICO_H__

#include "Arquivo.h"
#include "DCT.h"
#include "gl_canvas2d.h"

class Grafico{
    Arquivo *arq;
    int largura, altura, iniX, iniY, meioY, distX, showSamples, showReconst, showDif, qtd, recEdif;
    float escala;
    signed short *samples, *reconstruidos;

public:
    Grafico(int a, int l, int x, int y);
    void abreArquivo(char *nome);
    void desenhaGrafico();
    void desenhaSamples();
    void desenhaReconstruidos();
    void desenhaDiferencas();
    void ajustarTamanho(int l, int a, int y);
    void enableSamples(int x);
    void enableReconst(int x);
    void enableDif(int x);
    void aplicaDCTeIDCT();
    void enableReceDif(int x);
    void salvar();
};

#endif
