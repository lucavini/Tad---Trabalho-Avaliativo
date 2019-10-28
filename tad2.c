#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    printf("---------------------=\n");
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

void distanciaEuclidiana(){
    Pixel A,B;
    printf("Digite os valores x e y do ponto A: ");
    scanf("%d %d", &A.x, &A.y);

    printf("Digite os valores x e y do ponto B: ");
    scanf("%d %d", &B.x, &B.y);
    float dis;
    dis = sqrt( pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    printf("%.2f\n",dis);
}

void distanciaManhattan(){
    Pixel A, B;
    printf("Digite os valores x e y do ponto A: ");
    scanf("%d %d", &A.x, &A.y);

    printf("Digite os valores x e y do ponto B: ");
    scanf("%d %d", &B.x, &B.y);
    float dis;
    dis = (A.x - B.x) + (A.y - B.y);
    printf("%.2f\n",dis);
}

void kernelMedia(int **matrizMedia, int **matriz, int lin, int col){
    int tam;

    printf("Defina o tamanho do kernel: ");
    scanf("%d",&tam);

    int **kernel = (int**)calloc(sizeof(int*),tam); //aloca o kernel 3x3
    for(int i = 0; i<tam; i++)
        kernel[i] = (int*)calloc(sizeof(int),tam);

    for(int i = 0; i<lin; i++){
        for(int j = 0; j<col; j++){
            int aux1 = 0;

            for(int k = i; aux1<tam; k++){
                int aux2 = 0;
                for(int l = j; aux2<tam; l++){
                    kernel[aux1][aux2] = matriz[k%lin][l%col];
                    aux2++;
                }
                aux1++;
            }
            matrizMedia[(i+1)%lin][(j+1)%col] = filtroMedia(kernel, tam);

        }
    }
    salvarImagem(matrizMedia, lin, col);
}


void kernelMediana(int **matrizMediana, int **matriz, int lin, int col){
    int tam;

    printf("Defina o tamanho do kernel: ");
    scanf("%d",&tam);

    int **kernel = (int**)calloc(sizeof(int*),tam); //aloca o kernel 3x3
    for(int i = 0; i<tam; i++)
        kernel[i] = (int*)calloc(sizeof(int),tam);

    for(int i = 0; i<lin; i++){
        for(int j = 0; j<col; j++){
            int aux1 = 0;

            for(int k = i; aux1<tam; k++){
                int aux2 = 0;
                for(int l = j; aux2<tam; l++){
                    kernel[aux1][aux2] = matriz[k%lin][l%col];
                    aux2++;
                }
                aux1++;
            }
            matrizMediana[(i+1)%lin][(j+1)%col] = filtroMediana(kernel, tam);

        }
    }
    salvarImagem(matrizMediana, lin, col);
}


int filtroMedia(int **imagem, int tam){
    int tamKernel = tam * tam;
    int soma = 0;

    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++)
            soma = soma + imagem[i][j];
    }

    return soma/tamKernel;
}

int filtroMediana(int **imagem, int tam){

    int *v = (int*) malloc(sizeof(int)*(tam*tam));
    int cont = 0;
    int aux1, aux2;
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            v[cont] = imagem[i][j];
            cont++;
        }
    }

    quicksort(v,0,tam*tam);

    for (int i = 0; i < tam*tam; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    if((tam*tam)%2 == 0){
        aux1 = (tam*tam)/2;
        aux2 = ((tam*tam)/2)+1;

        printf("%d\n", (v[aux1] + v[aux2])/2);

        return (v[aux1] + v[aux2])/2;
    }else{
        return v[tam/2];
    }
}

void quicksort(int values[], int began, int end){
    int i, j, pivo, aux;
    i = began;
    j = end-1;
    pivo = values[(began + end) / 2];
    while(i <= j)
    {
        while(values[i] < pivo && i < end)
        {
            i++;
        }
        while(values[j] > pivo && j > began)
        {
            j--;
        }
        if(i <= j)
        {
            aux = values[i];
            values[i] = values[j];
            values[j] = aux;
            i++;
            j--;
        }
    }
    if(j > began)
        quicksort(values, began, j+1);
    if(i < end)
        quicksort(values, i, end);
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
    printf("9 - Filtro de média\n");
    printf("10 - Filtro de mediana\n");
    printf("0 - Voltar ao menu principal\n");
    printf("-------------------\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}