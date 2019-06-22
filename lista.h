
#ifndef GRAFOPROJETO_LISTA_H
#define GRAFOPROJETO_LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _lista LISTA;
typedef struct _no NO;

LISTA* ListaCria();
void ListaApaga(LISTA* lista);

int ListaVazia(LISTA* lista);

void ListaInsere(LISTA* lista, int id, int valor);
int ListaRemove(LISTA *lista);

#endif //GRAFOPROJETO_LISTA_H
