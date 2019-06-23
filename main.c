#include <stdio.h>
#include "grafos.h"
#define MAX 500

void printIntro(){
    printf("Trabalho Final da Materia de Grafos, 2019\n");
    printf("Feito Por\n");
    printf("\t- Maurilio M. Meireles\n");
    printf("\t- Luiz G. S. Vieira\n\n");
    printf("Corretor Automatico\n");
}

int main() {

    GRAFO* g = grafoCria();
    verticeInsere(g, ":ini");
    verticeInsere(g, ":fim");

    char **frase = (char**) malloc(sizeof(char*));

    printIntro();


    FILE * dicionario;
    dicionario = fopen("Others/arquivo.txt","r"); // Nome padrao
    if (dicionario ==  NULL)
    {
        return 1;
    }
    char primeiraPalavra[MAX] = "\0";
    char auxProx[MAX] = "\0";
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
            verticeInsere(g, primeiraPalavra);
            verticeInsere(g, auxProx);
            origem = verticeBusca(g, primeiraPalavra);
            destino = verticeBusca(g, auxProx);
            arestaInsere(g, origem, destino);
        }
        else
        {
            strcpy(auxProx,"\0"); //Reset implicito
        }
    }

    grafoPrint(g);

    Djokstra(g, verticeBusca(g,":ini"), verticeBusca(g,":fim"));

    free(frase);

    grafoApaga(g);

    return 0;
}
