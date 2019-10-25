#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tad1.h"

struct pessoa{
    char *nome;
    int idade, ID; //identificador
    int matricula; //deve ser gerada automaticamente
};

struct docente{
    Pessoa info_docente;
    int qtd_orientacoes_graduacao, qtd_orientacoes_pos_graduacao;
};

struct discente{
    Pessoa info_discente;
    int nivel; // 1- graduacao ou 2 - posgraduacao
    char *nome_curso;
    int senha, ID_orientador, ID_coorientador;
};
//---------------------------------------------------------------------------------------- MENU PRINCIPAL
int menuPrincipal(){
    int op;
    printf("------- Menu Principal------\n");
    printf("1 - Docentes\n");
    printf("2 - Discentes\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d",&op);
    return op;
}
//---------------------------------------------------------------------------------------- MENU DOCENTE
int menuDocente(){
    int op;
    printf("------- Menu Docente ------\n");
    printf("1  - Cadastrar Docentes\n");
    printf("2  - Mostrar Docentes\n");
    printf("3  - Buscar Docente\n");
    printf("4  - Alterar Docente\n");
    printf("5  - Remover Docente\n");
    printf("6  - Cadastrar Discente\n");
    printf("7  - Mostrar Discente\n");
    printf("8  - Buscar Discente\n");
    printf("9  - Alterar Discente\n");
    printf("10 - Remover Discente\n");
    printf("11 - Listar não orientados\n");
    printf("0 - Votar ao menu principal\n");
    printf("Escolha uma opção: ");
    scanf("%d",&op);
    return op;
}
//---------------------------------------------------------------------------------------- MENU DICENTE
// int menuDiscente(){
//     int op;
//                                  *************O BAGUIO LA DA IMAGEM************ 
//     scanf("%d",&op);
//     return op;
// }
//---------------------------------------------------------------------------------------- DOCENTE
Docente *cadastrarDocente(Docente *docentes, int *cont){
    int i = 0;
    docentes = (Docente*)realloc(docentes,sizeof(Docente)*(*cont + 1));

    printf("Digite o nome do professor orientador: ");
    setbuf(stdin,NULL);
    docentes[*cont].info_docente.nome = (char *)malloc(sizeof(char)*20);
    scanf("%[^\n]",docentes[*cont].info_docente.nome);
    printf("Digite a idade do professor orientador: ");
    scanf("%d", &docentes[*cont].info_docente.idade);

    docentes[*cont].info_docente.ID = rand() % 10000;

    srand(time(NULL));
    docentes[*cont].info_docente.matricula = rand()%10000;

    docentes[*cont].qtd_orientacoes_graduacao = 0;
    docentes[*cont].qtd_orientacoes_pos_graduacao = 0;

    (*cont)++;
    return docentes;
}

void mostrarDocentes(Docente *docentes, int cont){
    printf("--------- Lista de Docentes ---------\n");
    for(int i = 0; i<cont; i++){
        printf("------ Professor %d ------\n",i+1);
        printf("Nome: %s\n",docentes[i].info_docente.nome);
        printf("Idade: %d\n",docentes[i].info_docente.idade);
        printf("ID: %d\n",docentes[i].info_docente.ID);
        printf("Matricula: %d\n",docentes[i].info_docente.matricula);
        printf("Quantidade orientados graduandos: %d\n",docentes[i].qtd_orientacoes_graduacao);
        printf("Quantidade orientados pos-graduandos: %d\n", docentes[i].qtd_orientacoes_pos_graduacao);
    }
}


int BuscarDocente(Docente *docentes, int cont, int id){
    int i;
    for(i = 0; i<cont; i++){
       
        if (docentes[i].info_docente.ID ==  id){
            printf("-----------------------------\n");
            printf("Nome: %s\n", docentes[i].info_docente.nome);
            printf("Idade: %d\n",docentes[i].info_docente.idade);
            printf("ID: %d\n",docentes[i].info_docente.ID);
            printf("Matricula: %d\n",docentes[i].info_docente.matricula);
            printf("Quantidade orientados graduandos: %d\n",docentes[i].qtd_orientacoes_graduacao);
            printf("Quantidade orientados pos-graduandos: %d\n", docentes[i].qtd_orientacoes_pos_graduacao);
            return i;
        }
    }
    if(i == cont)
        printf("Docente não encontrado\n");
    return -1;
}

void alterarDocente(Docente *docentes, int cont){
    char nome[20];
    int id;
    printf("Digite o nome do docente que deseja buscar: ");
    scanf("%[^\n]", nome);

    for (int i = 0; i < cont; i++){
        if (!strcmp(nome, docentes[i].info_docente.nome)){
            id = BuscarDocente(docentes, cont, docentes[i].info_docente.ID);
            break;
        }
    }

    if (id == -1) {
        printf("Docente não encontrado\n");
    }else{
        printf("Digite o nome do professor orientador: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", docentes[id].info_docente.nome);
        printf("Digite a idade do professor orientador: ");
        scanf("%d", &docentes[id].info_docente.idade);
    }
    
}

void removerDocente(Docente *docentes, int *cont){
    int id,i;
    char nome[30];
    printf("Digite o nome do docente que deseja buscar: ");
    scanf("%[^\n]",nome);

    for(i = 0; i< *cont; i++){
        if(!strcmp(nome,docentes[i].info_docente.nome)){
            id = BuscarDocente(docentes, (*cont), docentes[i].info_docente.ID);
            break;
        }
    }

    if (i != -1){
        docentes[i].info_docente.ID = docentes[(*cont) - 1].info_docente.ID;
        docentes[i].info_docente.idade = docentes[(*cont) - 1].info_docente.idade;
        docentes[i].info_docente.matricula = docentes[(*cont) - 1].info_docente.matricula;
        docentes[i].info_docente.nome = docentes[(*cont) - 1].info_docente.nome;
        docentes[i].qtd_orientacoes_graduacao = docentes[(*cont) - 1].qtd_orientacoes_graduacao;
        docentes[i].qtd_orientacoes_pos_graduacao = docentes[(*cont) - 1].qtd_orientacoes_pos_graduacao;
        (*cont) -= 1;
    }

}

//---------------------------------------------------------------------------------------- DISCENTE
Discente *cadastrarDiscente(Discente *discentes, int *cont){
    int i = 0;
    discentes = (Discente*)realloc(discentes,sizeof(Discente)*(*cont + 1));

    printf("Digite o nome do aluno: ");
    setbuf(stdin,NULL);
    discentes[*cont].info_discente.nome = (char *)malloc(sizeof(char)*60);
    scanf("%[^\n]",discentes[*cont].info_discente.nome);
    printf("Digite a idade do aluno: ");
    scanf("%d", &discentes[*cont].info_discente.idade);
    printf("Informe o nível do aluno(1 - graduando | 2 - Pós-graduando): ");
    do{
        scanf("%d", &discentes[*cont].nivel);
    }while( (discentes[*cont].nivel != 1) && (discentes[*cont].nivel != 2) );

    printf("Curso do aluno: ");
    setbuf(stdin,NULL);
    discentes[*cont].nome_curso = (char *)malloc(sizeof(char)*20);
    scanf("%[^\n]",discentes[*cont].nome_curso);

    discentes[*cont].info_discente.ID = rand() % 10000;

    srand(time(NULL));
    
    discentes[*cont].info_discente.matricula = rand()%10000;

    printf("Digite a senha: ");
    scanf("%d",&discentes[*cont].senha);

    discentes[*cont].ID_orientador = -1;
    discentes[*cont].ID_coorientador = -1;

    (*cont)++;
    return discentes;
    
}

void mostrarDiscentes(Discente *discentes, int cont){
    printf("--------- Lista de Discentes ---------\n");
    for(int i = 0; i<cont; i++){
        printf("---------- Aluno %d -----------\n",i+1);
        printf("Nome: %s\n",discentes[i].info_discente.nome);
        printf("Idade: %d\n",discentes[i].info_discente.idade);
        printf("ID: %d\n",discentes[i].info_discente.ID);
        printf("Matricula: %d\n",discentes[i].info_discente.matricula);
        if (discentes[i].nivel == 1){
            printf("Nivel: Graduando\n");
        }else{
            printf("Nivel: Pós-graduando\n");

        }
        printf("Curso: %s\n",discentes[i].nome_curso);
    }
}

int BuscarDiscente(Discente *discentes, int cont, int ID){
    int i;
    for(i = 0; i<cont; i++){
        if ( discentes[i].info_discente.ID == ID ){
            printf("-----------------------------\n");
            printf("Nome: %s\n",discentes[i].info_discente.nome);
            printf("idade: %d\n", discentes[i].info_discente.idade);
            printf("ID: %d\n", discentes[i].info_discente.ID);
            printf("Matricula: %d\n", discentes[i].info_discente.matricula);
            if(discentes[i].nivel == 1)
                printf("Nivel: Graduação\n");
            else
                printf("Nivel: pos-graduação\n");
            printf("Nome do curso: %s\n",discentes[i].nome_curso);
            return i;
        }
    }
    if(i == cont)
        printf("Discente não encontrado\n");
    return -1;
}

void alterarDiscente(Discente *discentes, int cont){
    int id;
    char nome[30];
    printf("Digite o nome do aluno que deseja buscar: ");
    scanf("%[^\n]",nome);
    for(int i = 0; i<cont; i++){
        if(!strcmp(nome,discentes[i].info_discente.nome)){
            id = BuscarDiscente(discentes, cont, discentes[i].info_discente.ID);
            break;
        }
    }

    if (id == -1) {
        printf("Discente não encontrado\n");
    }else{
        printf("Digite o nome do Aluno: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", discentes[id].info_discente.nome);
        printf("Digite a idade do aluno: ");
        scanf("%d", &discentes[id].info_discente.idade);
        printf("Digite o nivel do aluno: ");
        scanf("%d", &discentes[id].nivel);
        printf("Digite o nome do curso: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", discentes[id].nome_curso);
        printf("Digite a senha: ");
        scanf("%d", &discentes[id].senha);
    }
    
}

void removerDiscente(Discente *discentes, int *cont){
    int id;
    char nome[30];
    printf("Digite o nome do aluno que deseja buscar: ");
    scanf("%[^\n]",nome);

    for(int i = 0; i<*cont; i++){
        if(!strcmp(nome,discentes[i].info_discente.nome)){
            id = BuscarDiscente(discentes, (*cont), discentes[i].info_discente.ID);
            break;
        }
    }

    if (id != -1){
        discentes[id].info_discente.ID = discentes[(*cont) - 1].info_discente.ID;
        discentes[id].info_discente.nome = discentes[(*cont) - 1].info_discente.nome;
        discentes[id].info_discente.idade = discentes[(*cont) - 1].info_discente.idade;
        discentes[id].info_discente.matricula = discentes[(*cont) - 1].info_discente.matricula;
        discentes[id].nivel = discentes[(*cont) - 1].nivel;
        discentes[id].nome_curso = discentes[(*cont) - 1].nome_curso;
        discentes[id].senha = discentes[(*cont) - 1].senha;
        (*cont) -= 1;
    }

}

void listarNaoOrientados(Discente *discentes, int qtd){
    for(int i = 0; i<qtd; i++){
        printf("------ Discentes sem orientador ------\n");
        if(discentes[i].ID_orientador == -1){
            BuscarDiscente(discentes, qtd, discentes[i].info_discente.ID);
        }
    }
}

void alocarOrientador(Discente *discentes, int *qtdDiscentes, Docente *docentes, int *qtdDocentes){
    int id, i, j;
    listarNaoOrientados(discentes, (*qtdDiscentes));

    printf("-------------------------------------------\n");
    printf("Digite o id do Aluno que deseja alocar: ");
    scanf("%d",&id);

    for (i = 0; i < *qtdDiscentes; i++)
        if (discentes[i].info_discente.ID == id)
            break;

    printf("-------------------------------------------\n");
    printf("Orientadores disponiveis: ");

    for(j = 0; j<*qtdDocentes; j++){
        if (discentes[i].nivel == 1)
            if(docentes[j].qtd_orientacoes_graduacao < 4)
                BuscarDocente(docentes, (*qtdDocentes), docentes[j].info_docente.ID);

        else
            if(docentes[j].qtd_orientacoes_pos_graduacao < 6)
                BuscarDocente(docentes, (*qtdDocentes), docentes[j].info_docente.ID);
    }

}