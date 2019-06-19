#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

#define MAX 500


int main() {

    GRAFO* grafo = grafoCria();

    char buffer[500]; // Máximo de 500 chars por frase
    FILE * dicionario;
    dicionario = fopen("corrupcao.txt","r"); // Nome padrao
    if (dicionario ==  NULL)
    {
        return 1;
    }
    char primeiraPalavra[MAX] = "\0";
    char auxProx[MAX] = "\0";
    int i = 0;
    int j = 0;
    char c;
    int origem, destino;
    while (c != EOF)
    {
        if (strcmp(auxProx, "\0") == 0) // Se não houver próxima, é porque é a primeira da frase
        {
            fscanf(dicionario,"%s",primeiraPalavra);
        }
        else
        {
            strcpy(primeiraPalavra,auxProx);
        }
        c = fgetc(dicionario);
        if (c != 0xD) // Número binário para compatibilidade com Linux
        {
            fscanf(dicionario,"%s",auxProx);
            /* Implementar a busca antes para evitar as mensagens de erro*/
            verticeInsere(grafo, primeiraPalavra);
            verticeInsere(grafo, auxProx);
            origem = verticeBusca(grafo, primeiraPalavra);
            destino = verticeBusca(grafo, auxProx);
            arestaInsere(grafo, origem, destino);
            printf("%s %s\n",primeiraPalavra,auxProx);
        }
        else
        {
            strcpy(auxProx,"\0"); //Reset implicito
        }
    }

    grafoPrint(grafo);
    grafoApaga(grafo);
    return 0;
}