#include "itree.h"
#include <stdio.h>
#include <string.h>
#define MAX_LINEA 1001

int main(){

    char entrada[MAX_LINEA], comando[10];
    intervalo intervaloAux;
    int largoEntrada;

    iTree raiz = itree_crear(), nodo;

    printf("Ingrese i para insertar, e para eliminar, ? para intersecar, dfs, bfs, salir \n");

    while(strcmp(gets(entrada),"salir\0") != 0) {

        largoEntrada = strlen(entrada);

        if (largoEntrada == 3){

            if (strcmp(entrada,"dfs") == 0){
                itree_recorrer_dfs(raiz, imprimir_intervalo);
                printf("\n");
            }

            else if (strcmp(entrada,"bfs") == 0){
                itree_recorrer_bfs(raiz, imprimir_intervalo);
                printf("\n");
            }
        }

        else if (largoEntrada >= 7){
            if (sscanf(entrada, "%s [%lf,%lf] \n", comando, &intervaloAux.inicio, &intervaloAux.final) == 3){
                if (entrada[0] == 'i' && entrada[1] == ' ')
                    raiz = itree_insertar(raiz, intervaloAux);

                else if (entrada[0] == 'e' && entrada[1] == ' ')
                    raiz = itree_eliminar(raiz, intervaloAux);

                else if (entrada[0] == '?' && entrada[1] == ' '){
                    nodo = itree_intersecar(raiz, intervaloAux);
                    if (nodo == NULL)
                        printf("No\n");
                    else {
                        printf ("Si, ");
                        imprimir_intervalo(nodo);
                        printf ("\n");
                    }
                } else
                    printf("Comando no reconocido\n");
                
            } else
                printf("Cantidad de argumentos incorrectos\n");
        } else
            printf("Largo de la entrada incorrecto\n");
    }

    itree_destruir(raiz);

    return 0;
}