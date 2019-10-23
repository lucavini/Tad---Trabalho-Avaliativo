#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD2.h"

int menu(){
    printf("\n1 CriarImagem");
    printf("\n2 Carregar Imagem");
    printf("\n3 SalvaImagem");
	printf("\n4 Criar Copia");
	printf("\n5 Salvar Copia");
	printf("\n6 MostraImagem");
    printf("\n0 Sair\n");
    
	int opc;
    scanf("%d", &opc);
    return opc;
}

Imagem *CriarImagem(Imagem *imagem){
	imagem = (Imagem*)calloc(sizeof(Imagem),1);
    printf("\nAltura e largura da imagem");
	scanf("%d %d", &imagem->altura, &imagem->largura);
    imagem->pixels_imagem = (Pixel*)calloc(sizeof(Pixel),(imagem->altura*imagem->largura));

    int j = 0;
	Pixel *aux = imagem->pixels_imagem;

	for(int i = 0; i < imagem->altura*imagem->largura; i++){
    	imagem->pixels_imagem->valor_pixel = (rand()%256);
        imagem->pixels_imagem->x = i;
        imagem->pixels_imagem->y = j;
		
		imagem->pixels_imagem++;
        j++;

    }

	imagem->pixels_imagem = aux;


	return imagem;
}

void salvarImagem(Imagem *imagem, char *caminho){
	FILE *arquivo;
	int i, j;
	arquivo = fopen(caminho, "w");
	
	if(arquivo == NULL){
		fprintf(stderr,"Erro na abertura de arquivo!\n");
        exit(1);  
	}else{
		Pixel *aux = imagem->pixels_imagem;

		for(i = 0; i < imagem->altura; i++){
			for(j = 0; j < imagem->largura; j++){
				fprintf(arquivo, "%d ", imagem->pixels_imagem->valor_pixel);
				imagem->pixels_imagem++;
			}
			fprintf(arquivo, "\n");
		}
		imagem->pixels_imagem = aux;
		printf("Imagem salva com sucesso!\n");
	}
	fclose(arquivo);
}

Imagem *CarregarImagem(char *caminho){
	FILE *arquivo;
	int i = 0, j = 0, aux, tam = 0, linhas=0;
	Imagem *imagem = (Imagem*)calloc(sizeof(Imagem),1);
	arquivo = fopen(caminho, "r");

	if(arquivo == NULL){
		fprintf(stderr,"Erro na abertura de arquivo!\n");
        exit(1);  
	}else{
		while(!feof(arquivo)){
			char c = fgetc(arquivo);
			if(c == ' ') i++;
			else if (c == '\n') j++;
		}
	}

	i = i/j; fseek(arquivo, 0, SEEK_SET);

	//printf("///%d-----%d", j,i);
	Pixel *inicio;

	imagem->pixels_imagem = (Pixel*)realloc(NULL, sizeof(Pixel)*i);
	inicio = imagem->pixels_imagem;

	for(int x=0; x<j; x++){
		for(int y=0; y<j; y++){
			fscanf(arquivo, "%d", &aux);

			imagem->pixels_imagem->valor_pixel = aux;
			imagem->pixels_imagem->x = x;
			imagem->pixels_imagem->y = y;
		
			//printf("%d ", aux);

			imagem->pixels_imagem++;
		}
	//4	printf("\n");		
	}

	imagem->pixels_imagem = inicio;
		
	printf("\nImagem lida com sucesso!\n");
	fclose(arquivo);

	return imagem;
}

void MostrarImagem(Imagem *imagem){
	printf("\n");
	Pixel *aux = imagem->pixels_imagem;
	for(int i = 0; i < imagem->altura; i++){
		for(int j = 0; j < imagem->largura; j++){
			printf("%d ", imagem->pixels_imagem->valor_pixel);
			imagem->pixels_imagem++;
		}
		printf("\n");
	}
	imagem->pixels_imagem = aux;
}


Imagem *Copiar(Imagem *imagem){
	
	Imagem *copia = (Imagem*)realloc(NULL, sizeof(Imagem)*1);
	
	copia->pixels_imagem = (Pixel*)realloc(NULL, sizeof(Pixel)*(imagem->altura*imagem->largura));
	Pixel *inicio = copia->pixels_imagem;
	
	copia->altura = imagem->altura;
	copia->largura = imagem->largura;

	for(int i=0; i < copia->altura; i++){
		for(int j=0; j < copia->largura; j++){
			
			copia->pixels_imagem->valor_pixel = imagem->pixels_imagem->valor_pixel;
			copia->pixels_imagem->x = i;
			copia->pixels_imagem->y = j;
			
			copia->pixels_imagem++;
		}
	}
	copia->pixels_imagem = inicio;
	
	if(copia){
		printf("\nImagem copiada com sucesso");
	}

	return copia;
}
