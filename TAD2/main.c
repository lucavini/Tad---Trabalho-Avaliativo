#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include "TAD2.h"

void main(){
    Imagem *imagem,*copia;;
    int opc;
    do{
        opc = menu();
        switch(opc){
            case 1:
                imagem = CriarImagem(imagem);
            break;

            case 2:
                imagem = CarregarImagem("teste.txt");
            break;
        
            case 3:
                salvarImagem(imagem,"teste.txt");
            break;

            case 4:
                copia = Copiar(imagem);
            break;

            case 5:
                salvarImagem(copia,"Copiada.txt");
            break;

            case 6:
                MostrarImagem(imagem);
            break;
        }
         
    }while(opc != 0);
    
}




