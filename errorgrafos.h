//
// Created by Maurilio on 14/06/2019.
//

#ifndef GRAFOPROJETO_ERRORGRAFOS_H
#define GRAFOPROJETO_ERRORGRAFOS_H

#include <stdio.h>

#define DEBUG 1

#define _ERROR_GRAFO_NULO_ if(DEBUG){printf("[WARNING]\tO grafo acessado eh nulo!\n");}
#define _ERROR_ARESTA_NULA_ if(DEBUG){printf("[WARNING]\tA aresta acessada eh nula!\n");}
void _iteraction_end(int i);
#define  _BUSCA_FAIL_ if(DEBUG){printf("[WARNING]\tElemento nao encontrado!\n");}

#endif //GRAFOPROJETO_ERRORGRAFOS_H
