#include <stdio.h>
#include <stdlib.h>
#include "tad1.h"
#include "tad2.h"

void menu(Docente *docentes,int contDocentes,Discente *discentes,int contDiscentes, Imagem *img, int **image);

void main(){
    Docente *docentes = NULL;
    int contDocentes = 0;

    Discente *discentes = NULL;
    int contDiscentes = 0;

    Imagem *img;
    int **image;

    menu(docentes,contDocentes,discentes,contDiscentes,img,image);
}

void menu(Docente *docentes,int contDocentes,Discente *discentes,int contDiscentes,Imagem *img, int **image){
    int esc,op1,op2;
    int id;
    int alt,lar;
    int matricula, senha;
    do{
        esc = menuPrincipal();
        switch (esc){
            case 1:  
                //menu Docente
                system("clear || cls");
                do{
                    op1 = menuDocente();
                    switch (op1){
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
                            printf("Digite o id do docente que deseja buscar: ");
                            scanf("%d", &id);
                            BuscarDocente(docentes, contDocentes, id);
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
                        case 8:
                            system("clear || cls");
                            printf("Digite o id do discente que deseja buscar: ");
                            scanf("%d",&id);
                            BuscarDiscente(discentes, contDiscentes, id);
                            break;
                        case 9:
                            system("clear || cls");
                            alterarDiscente(discentes, contDiscentes);
                            break;
                        case 10:
                            system("clear || cls");
                            removerDiscente(discentes, &contDiscentes);
                            break;
                        case 11:
                            system("clear || cls");
                            listarNaoOrientados(discentes,contDiscentes);
                            break;
                        case 12:
                            system("clear || cls");
                            alocarOrientador(discentes,&contDiscentes,docentes,&contDocentes);
                            break;

                        case 13: 
                            //Menu para processar imagem
                            printf("Digite a matricula do docente: ");
                            int mat;
                            scanf("%d",&mat);

                            while(!verificaDocente(docentes, contDocentes, mat)){
                                printf("Matricula não encontrada\n");
                                scanf("%d", &mat);
                            }

                            system("cls || clear");
                            printf("Docente encontrado\n");
                            do{
                                op2 = menuImagem();
                                switch (op2){
                                    case 1:
                                        system("cls || clear");
                                        dimencoes(img,&alt,&lar);
                                        image = alocarMatriz(alt, lar);
                                        preencherMatriz(image, alt, lar,img);
                                        break;
                                    case 2:
                                        system("cls || clear");
                                        image = lerImagem(img,&alt,&lar);
                                        break;
                                    case 3:
                                        system("cls || clear");
                                        salvarImagem(image,alt,lar);
                                        break;
                                    case 4:
                                        system("cls || clear");
                                        mostrarMatriz(image, alt, lar);
                                        break;
                                }
                            }while(op2 != 0);
                        case 0:
                            system("clear || cls");
                            menu(docentes, contDocentes, discentes, contDiscentes, img, image);
                            break;
                    }
                }while(op1 != 0);
                break;
            case 2:
                //menu discente
                printf("Digite a matricula e senha: ");
                scanf("%d%d", &matricula, &senha);
                while(!menuDiscente(discentes, contDiscentes, matricula, senha)){
                    printf("Discente não encontrado\n");
                    scanf("%d%d", &matricula, &senha);
                }

                system("cls || clear");
                printf("Discente encontrado\n");
                do{
                    op2 = menuImagem();
                    switch (op2){
                        case 1:
                            system("cls || clear");
                            dimencoes(img, &alt, &lar);
                            image = alocarMatriz(alt, lar);
                            preencherMatriz(image, alt, lar, img);
                            break;
                        case 2:
                            system("cls || clear");
                            image = lerImagem(img, &alt, &lar);
                            break;
                        case 3:
                            system("cls || clear");
                            salvarImagem(image, alt, lar);
                            break;
                        case 4:
                            system("cls || clear");
                            mostrarMatriz(image, alt, lar);
                            break;
                    }
                }while (op2 != 0);
                break;
            case 0:
                exit(1);
        }
    }while(esc != 0);
}