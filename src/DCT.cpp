/**
*   DCT.cpp
*
*   Arquivo com as funções DCT e IDCT que são aplicadas
*   sobre o vetor de amostras.
**/

#include "DCT.h"

DCT::DCT(int n, signed short *v){
    qtd = n;
    samples = v;
    aux = (signed short*) malloc(qtd*sizeof(signed short));
}

void DCT::aplicaDCT(){
    int i, j;
    float mat[qtd][qtd];

    for(i=0; i<qtd; i++)
        mat[0][i] = 1.0/sqrt(qtd) * samples[i];

    for(i=1; i<qtd; i++)
        for(j=0; j<qtd; j++)
            mat[i][j] = sqrt(2.0/qtd) * cos(i*PI/(2.0*qtd)*(2.0*j+1)) * samples[j];

    for(i=0; i<qtd; i++)
        aux[i] = 0;

    for(i=0; i<qtd; i++)
        for(j=0; j<qtd; j++)
            aux[i]+=mat[i][j];
}

void DCT::aplicaIDCT(){
    int i,j;
    float mat[qtd][qtd];

    for(i=0; i<qtd; i++)
        mat[0][i] = sqrt(1.0/qtd) * aux[0] * cos(0);

    for(i=1; i<qtd; i++)
        for(j=0; j<qtd; j++)
            mat[i][j] = sqrt(2.0/qtd) * aux[i] * cos(i*(2*j+1)*PI/(2.0*qtd));

    for(i=0; i<qtd; i++)
        samples[i]=0;


    for(i=0; i<qtd; i++)
        for(j=0; j<qtd; j++)
            samples[i] += mat[j][i];
}

signed short* DCT::aplicaDCTeIDCT(){
    aplicaDCT();
    aplicaIDCT();
    return samples;
}
