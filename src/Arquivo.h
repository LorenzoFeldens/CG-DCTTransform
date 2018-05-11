#ifndef __ARQUIVO_H__
#define __ARQUIVO_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


class Arquivo{
    FILE *arq;
    char* nome;
    int qtd;
    signed short *samples;

public:
    Arquivo(char *no);
    int getQuantidade();
    signed short* getSamples();
    void salvar(signed short *newV);
};

#endif
