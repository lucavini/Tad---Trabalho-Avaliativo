#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tad2.h"

struct pixel{
    int x, y, valor_pixel;
};

struct imagem{
    int altura, largura;
    Pixel *pixels_imagem; //variar de 0 ate 255
};

void dimencoes(Imagem *img, int *alt, int *lar){
    printf("Digite a altura e largura da imagem: \n");
    scanf("%d%d",&img->altura,&img->largura);
    *alt = img->altura;
    *lar = img->largura;
    img->pixels_imagem = (Pixel*)malloc(sizeof(Pixel)*(img->altura*img->largura));
}

int **alocarMatriz(int lin, int col){
    int **matriz = (int**)calloc(sizeof(int*),lin);
    for(int i = 0; i<lin; i++){
        matriz[i] = (int*)calloc(sizeof(int),col);
    }
    return matriz;
}

void preencherMatriz(int **imagem, int lin, int col, Imagem *img){
    int k = 0;
    srand(time(NULL));
    for(int i = 0; i<lin; i++){
        for(int j = 0; j<col; j++){
            imagem[i][j] = rand()%256;
            img->pixels_imagem[k].x = i;
            img->pixels_imagem[k].y = j;
            img->pixels_imagem[k].valor_pixel = imagem[i][j];
        }
    }
}

void mostrarMatriz(int **imagem, int lin, int col){
    for(int i = 0; i<lin; i++){
        for(int j = 0; j<col; j++){
            printf("%5d",imagem[i][j]);
        }
        printf("\n");
    }
}

int  **lerImagem(Imagem *img, int *alt, int *lar){
    printf("Informe o nome do arquivo: ");
    char arquivo[20];
    scanf("%s",arquivo);
    FILE *file;
    file = fopen(arquivo, "r");

    fscanf(file, "%d %d", &img->altura, &img->largura);
    *alt = img->altura;
    *lar = img->largura;
    int **imagem = alocarMatriz(img->altura, img->largura);

    for(int i = 0; i<img->altura; i++){
        for(int j = 0; j< img->largura; j++){
            fscanf(file, "%d", &imagem[i][j]);
        }
    }

    fclose(file);
    return imagem;
}

void salvarImagem(int **imagem, int lin, int col){
    printf("Informe o nome do arquivo para salvar imagem: ");
    char arquivo[20];
    scanf("%s",arquivo);
    FILE *file;
    file = fopen(arquivo,"w");

    for(int i = 0; i<lin; i++){
        for(int j = 0; j<col; j++){
            fprintf(file,"%d ",imagem[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int menuImagem(){
    int opcao;
    printf("\n-------MENU IMAGEM--------\n");
    printf("1 - Criar imagem\n");
    printf("2 - carregar imagem \n");
    printf("3 - salvar imagem\n");
    printf("4 - mostrar pixels da imagem\n");
    printf("5 - maior e menor valores da matriz\n");
    printf("6 - calcular distancia Euclidiana\n");
    printf("7 - calcular distancia Manhattan\n");
    printf("8 - Local Binary Pattern (LBP)\n");
    printf("-------------------\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}