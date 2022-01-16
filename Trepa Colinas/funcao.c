//
// Created by Hugo on 16/01/2022.
//

#include "funcao.h"


int calcula_fit(int a[], int *mat, int vert){
    int total = 0;
    int i, j;
    int zeros=0;

    for (i = 0; i < vert; i++){
        if (a[i] == 0)
        {
            for (j = 0; j < vert; j++)
                if (a[j] == 0 && *(mat+i*vert+j) == 1)
                    total++;
        }
    }
    if(total == 0){
        for(i=0;i<vert;i++){
            if(a[i] == 0){
                zeros++;
            }
        }
        return zeros;
    }
    else{
        return -total;
    }
}

