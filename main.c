#include <stdio.h>
#include "grafos.h"

int main() {

    char **frase;
    frase = (char**) malloc(5 * sizeof(char*));
    for(int i = 0; i < 5; i++){
        frase[i] = (char*) malloc(50 * sizeof(char));
        scanf("%s", frase[i]);
    }

    GRAFO* grafo = grafoCria();
    verticeInsere(grafo, ":ini");
    verticeInsere(grafo, ":fim");

    for (int i = 0; i < 5; ++i) {
        verticeInsere(grafo, frase[i]);
    }

    for (int i = 0; i < 5; ++i) {
        int j = (i+1);
        if(i == 0) arestaInsere(grafo, verticeBusca(grafo,":ini"), verticeBusca(grafo, frase[i]));
        if(j == 5) arestaInsere(grafo, verticeBusca(grafo,frase[i]), verticeBusca(grafo, ":fim"));
        else {
            arestaInsere(grafo, verticeBusca(grafo, frase[i]), verticeBusca(grafo, frase[j]));
        }
    }

    grafoPrint(grafo);

    grafoApaga(grafo);


    for(int i = 0; i < 5; i++){
        free(frase[i]);
    }
    free(frase);

    return 0;
}