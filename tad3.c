#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tad2.h"
#include "tad3.h"
#define tamK 3

int maiorValor(int **matriz, int lin, int col){
    int maior = matriz[0][0];
    for(int i = 0; i<lin; i++){
        for(int j = 0; j<col; j++){
            if(matriz[i][j] > maior)
                maior = matriz[i][j];
        }
    }
    return maior;
}

int menorValor(int **matriz, int lin, int col){
    int menor = matriz[0][0];
    for(int i = 0; i<lin; i++){
        for(int j = 0; j<col; j++){
            if(matriz[i][j] < menor)
                menor = matriz[i][j];
        }
    }
    return menor;
}

void LBP(int **matriz, int lin, int col){

    int **kernel = (int**)calloc(sizeof(int*),tamK); //aloca o kernel 3x3
    for(int i = 0; i<tamK; i++)
        kernel[i] = (int*)calloc(sizeof(int),tamK);

    for(int i = 0; i<lin; i++){
        for(int j = 0; j<col; j++){
            int aux1 = 0;

            for(int k = i; aux1<tamK; k++){
                int aux2 = 0;
                for(int l = j; aux2<tamK; l++){
                    kernel[aux1][aux2] = matriz[k%lin][l%col];
                    aux2++;
                }
                aux1++;
            }
            matriz[(i+1)%lin][(j+1)%col] = processaKernel(kernel, tamK);

        }
    }
}

int processaKernel(int **kernel, int tam){
    int vc = kernel[1][1];
    char binarioString[8];
    int bin, dec = 0, i;
    int cont = 0;

    for(int i = 0; i<tam; i++){
        if(kernel[0][i] < vc){
            binarioString[cont] = '0';
            cont++;
        }else{
            binarioString[cont] = '1';
            cont++;
        }
    }

    if(kernel[1][2] < vc){
        binarioString[cont] = '0';
        cont++;
    }else{
        binarioString[cont] = '1';
        cont++;
    }

    for(int i = tam-1; i>=0; i--){
        if(kernel[2][i] < vc){
            binarioString[cont] = '0';
            cont++;
        }else{
            binarioString[cont] = '1';
            cont++;
        }
    }


    if(kernel[1][0] < vc){
        binarioString[cont] = '0';
        cont++;
    }else{
        binarioString[cont] = '1';
        cont++;
    }

    bin = atoi(binarioString);
    // printf("numero binario: %d\n",bin);

    for (i = 0; bin > 0; i++)
    {
        dec = dec + pow(2, i) * (bin % 10);
        bin = bin / 10;
    }
    // printf("pixel central, %d\n",dec);
    return dec;
}

void mostrar(int **matriz, int lin, int col){
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
}

