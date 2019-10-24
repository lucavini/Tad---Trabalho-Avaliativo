#include <stdio.h>
#include <stdlib.h>
#include "tad1.h"

void main(){
    Docente *docentes = NULL;
    int contDocentes = 0;

    Discente *discentes = NULL;
    int contDiscentes = 0;


    int op;
    do{
        op = menu();
        switch (op){
            case 1:
                system("clear || cls");
                docentes = cadastrarDocente(docentes, &contDocentes);
                break;
            case 2:
                system("clear || cls");
                mostrarDocentes(docentes, contDocentes);
                break;
            case 3:
                system("clear || cls");
                BuscarDocente(docentes, contDocentes);
                break;
            case 4:
                system("clear || cls");
                alterarDocente(docentes, contDocentes);
                break;
            case 5:
                system("clear || cls");
                removerDocente(docentes, &contDocentes);
                break;
            case 6:
                system("clear || cls");
                discentes = cadastrarDiscente(discentes, &contDiscentes);
                break;
            case 7:
                system("clear || cls");
                mostrarDiscentes(discentes, contDiscentes);
                break;
            case 8:
                system("clear || cls");
                BuscarDiscente(discentes, contDiscentes);
                break;
            case 9:
                system("clear || cls");
                alterarDiscente(discentes, contDiscentes);
                break;
            case 10:
                system("clear || cls");
                removerDiscente(discentes, &contDiscentes);
                break;
            }



    }while(op != 0);
}