/**
*   Arquivo.cpp
*
*   Arquivo que controla o carregar e salvar
*   do arquivo contendo as amostras.
**/

#include "Arquivo.h"


Arquivo::Arquivo(char *no){
    nome=no;
    arq = fopen(nome, "rb");
    if (arq == NULL){
        printf("Problemas na abertura do arquivo\n");
        return;
    }

    uint32_t n;

    fread(&n, sizeof(n), 1, arq);
    qtd = (int) n;

    samples = (signed short*) malloc(n*sizeof(signed short));
    for (int i=0; i<n; i++){
        fread(&samples[i], sizeof(signed short), 1, arq);
    }
    fclose(arq);
}

int Arquivo::getQuantidade(){
    return qtd;
}

signed short* Arquivo::getSamples(){
    return samples;
}

void Arquivo::salvar(signed short *newV){
    arq = fopen(nome, "wb");
    if (arq == NULL){
        printf("Problemas na abertura do arquivo\n");
        return;
    }

    uint32_t n = (uint32_t) qtd;

    fwrite(&n,sizeof(n),1,arq);

    //fread(&n, sizeof(n), 1, arq);
    //qtd = (int) n;

    //samples = (signed short*) malloc(n*sizeof(signed short));
    for (int i=0; i<n; i++){
        fwrite(&newV[i],sizeof(signed short),1,arq);
        //fread(&samples[i], sizeof(signed short), 1, arq);
    }
    fclose(arq);
}
