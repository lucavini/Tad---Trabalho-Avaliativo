#include <stdlib.h>

typedef struct pixel Pixel;
typedef struct imagem Imagem;

int menuImagem();
void dimencoes(Imagem *img, int *alt, int *lar);
int **alocarMatriz(int lin, int col);
void preencherMatriz(int **imagem, int lin, int col, Imagem *img);
void mostrarMatriz(int **imagem, int lin, int col);
int **lerImagem(Imagem *img, int *alt, int *lar);
void salvarImagem(int **imagem, int lin, int col);
void distanciaEuclidiana();
void distanciaManhattan();
int filtroMedia(int **imagem, int tam);
int filtroMediana(int **imagem, int tam);
void kernelMedia(int **matrizMedia, int **matriz, int lin, int col);
void kernelMediana(int **matrizMediana, int **matriz, int lin, int col);
void quicksort(int values[], int began, int end);

// void filtroMediana();