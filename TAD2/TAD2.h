

typedef struct pixel Pixel;
typedef struct imagem Imagem;

struct pixel {
    int x, y, valor_pixel;
};

struct imagem {
    int altura, largura;
    Pixel *pixels_imagem;//variar de 0 ate 255
};

int menu();
Imagem *CriarImagem(Imagem *imagem);
Imagem *CarregarImagem(char *caminho); 
void salvarImagem(Imagem *imagem, char *caminho);
void MostrarImagem(Imagem *imagem);
Imagem *Copiar(Imagem *imagem);


