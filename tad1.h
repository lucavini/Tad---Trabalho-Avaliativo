#include <stdlib.h>

typedef struct pessoa Pessoa;
typedef struct docente Docente;
typedef struct discente Discente;

int menuPrincipal();
int menuDocente();
void menuDiscente();
//---------------------------------------------------------------------------------------- DOCENTE
int verificaDocente(Docente *docentes, int qtd, int matricula);
Docente *cadastrarDocente(Docente *docentes, int *contDocentes);
void mostrarDocentes(Docente *docentes, int cont);
int BuscarDocente(Docente *docentes, int cont, int id);
void alterarDocente(Docente *docentes, int cont);
void removerDocente(Docente *docentes, int *cont);
//---------------------------------------------------------------------------------------- DISCENTE
Discente *cadastrarDiscente(Discente *discentes, int *contDiscentes);
void mostrarDiscentes(Discente *discentes, int cont);
int BuscarDiscente(Discente *discentes, int cont, int id);
void alterarDiscente(Discente *discentes, int cont);
void removerDiscente(Discente *discentes, int *cont);
void listarNaoOrientados(Discente *discentes, int qtd);

void alocarOrientador(Discente *discentes, int *cont, Docente *docentes, int *contDocentes);
