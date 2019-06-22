#include <stdio.h>
#include "grafos.h"

#define MAX_PALAVRAS 10

int main() {

    GRAFO* g = grafoCria();
    verticeInsere(g, ":ini");
    verticeInsere(g, ":fim");

    char **frase = (char**) malloc(sizeof(char*));

    for (int rept = 0; rept < 3; rept++) {
        int qtdPalavra = 0;
        char palavra[50];

        char letra;
        int posLetra = 0;
        do{

            letra =(char) getchar();
            if (letra == ' ' || letra == '\n'){
                if (posLetra != 0) {
                    palavra[posLetra] = '\0';
                    printf("[%s]\n", palavra);
                    posLetra = 0;

                    qtdPalavra++;
                    frase = realloc(frase, qtdPalavra * sizeof(char*));
                    frase[qtdPalavra-1] =(char*) malloc(50 * sizeof(char));
                    strcpy(frase[qtdPalavra-1], palavra);
                }
            } else{
                palavra[posLetra] = letra;
                posLetra++;
            }

        }while (letra != '\n');

        for(int i = 0; i < qtdPalavra; i++){
            verticeInsere(g, frase[i]);
        }

        for(int i = 0; i < qtdPalavra; i++){
            int j = i+1;
            if(i == 0) arestaInsere(g, verticeBusca(g,":ini"), verticeBusca(g,frase[i]));
            if( j == qtdPalavra) arestaInsere(g, verticeBusca(g, frase[i]), verticeBusca(g, ":fim"));
            else arestaInsere(g, verticeBusca(g,frase[i]), verticeBusca(g, frase[j]));

            free(frase[i]);
        }
    }

    grafoPrint(g);

    Djokstra(g, verticeBusca(g,":ini"), verticeBusca(g,":fim"));

    free(frase);

    grafoApaga(g);

    return 0;
}