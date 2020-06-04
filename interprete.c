#include "itree.h"
#include <stdio.h>
#include <string.h>

int main(){

    char entrada[50], comando[10];
    intervalo intervaloAux;

    iTree raiz = itree_crear(), nodo;

    printf("Ingrese i para insertar, e para eliminar, ? para intersecar, dfs, bfs, salir \n");

    while(strcmp(gets(entrada),"salir\0") != 0) {
        sscanf(entrada, "%s [%lf,%lf] \n", comando, &intervaloAux.inicio, &intervaloAux.final);
        printf("%s [%.2f, %.2f] dato   \n",comando, intervaloAux.inicio, intervaloAux.final);

        if (strcmp(comando,"i") == 0)
            raiz = itree_insertar(raiz, intervaloAux);

        else if (strcmp(comando,"e") == 0)
            raiz = itree_eliminar(raiz, intervaloAux);

        else if (strcmp(comando,"?") == 0){
            nodo = itree_intersecar(raiz, intervaloAux);
            if (nodo == NULL)
                printf("No\n");
            else {
                printf ("Si, ");
                imprimir_intervalo(nodo);
                printf ("\n");
            }
        }

        else if (strcmp(comando,"dfs") == 0){
            itree_recorrer_dfs(raiz, imprimir_intervalo);
            printf("\n");
        }

        else if (strcmp(comando,"bfs") == 0){
            itree_recorrer_bfs(raiz, imprimir_intervalo);
            printf("\n");
        }

        else
            printf("Comando no reconocido, intente de nuevo \n");
    }

    itree_destruir(raiz);

    return 0;
}