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
            }

    }while(op != 0);
}