#include <stdlib.h>

typedef struct pessoa Pessoa;
typedef struct docente Docente;
typedef struct discente Discente;

int menu();
//---------------------------------------------------------------------------------------- DOCENTE
Docente *cadastrarDocente(Docente *docentes, int *contDocentes);
void mostrarDocentes(Docente *docentes, int cont);
int BuscarDocente(Docente *docentes, int cont);
void alterarDocente(Docente *docentes, int cont);
void removerDocente(Docente *docentes, int *cont);
//---------------------------------------------------------------------------------------- DISCENTE
Discente *cadastrarDicente(Discente *discentes, int *contDiscentes);

