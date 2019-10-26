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