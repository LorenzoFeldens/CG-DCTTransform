#ifndef __DCT_H__
#define __DCT_H__

#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

class DCT{
    int qtd;
    signed short *samples;
    signed short *aux;

public:
    DCT(int n, signed short *v);
    signed short* aplicaDCTeIDCT();
    void aplicaDCT();
    void aplicaIDCT();
};

#endif
