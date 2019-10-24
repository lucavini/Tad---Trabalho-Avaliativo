#include <stdio.h>
#include <stdlib.h>
#include "tad1.h"

void menu(Docente *docentes,int contDocentes,Discente *discentes,int contDiscentes){
    int esc,op;

    do{
        esc = menuPrincipal();
        switch (esc){
            case 1:
                system("clear || cls");
                do{
                    op = menuDocente();
                    switch (op){
                        case 1:
                            system("clear || cls");
                            docentes = cadastrarDocente(docentes, &contDocentes);
                            continue;
                        case 2:
                            system("clear || cls");
                            mostrarDocentes(docentes, contDocentes);
                            continue;
                        case 3:
                            system("clear || cls");
                            BuscarDocente(docentes, contDocentes);
                            continue;
                        case 4:
                            system("clear || cls");
                            alterarDocente(docentes, contDocentes);
                            continue;
                        case 5:
                            system("clear || cls");
                            removerDocente(docentes, &contDocentes);
                            continue;
                        case 6:
                            system("clear || cls");
                            discentes = cadastrarDiscente(discentes, &contDiscentes);
                            continue;
                        case 7:
                            system("clear || cls");
                            mostrarDiscentes(discentes, contDiscentes);
                            continue;
                        case 0:
                            system("clear || cls");
                            menu(docentes,contDocentes,discentes,contDiscentes);
                            break;
                        }
                }while(op != 0);
                break;
            // case 2:
            //     system("clear || cls");
            //     menuDiscente();
            case 0:
                exit(1);
        }
    }while(esc != 0);
}


void main(){
    Docente *docentes = NULL;
    int contDocentes = 0;

    Discente *discentes = NULL;
    int contDiscentes = 0;

    menu(docentes,contDocentes,discentes,contDiscentes);
}