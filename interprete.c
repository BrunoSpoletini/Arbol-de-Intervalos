#include "itree.h"
#include <stdio.h>
#include <string.h>
#define MAX_LINEA 1001

void leer_entrada(iTree raiz){
    char comando, entrada[MAX_LINEA];
    iTree nodo;
    intervalo intervaloAux;
    int largoEntrada;

    while(strcmp(entrada, "salir\0") != 0) {

        fgets(entrada, sizeof(entrada), stdin);

        largoEntrada = strlen(entrada)-1;
        if (largoEntrada > 0)
            entrada[largoEntrada] = '\0';

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
            if (sscanf(entrada, "%c [%lf,%lf] \n", &comando, &intervaloAux.inicio, &intervaloAux.final) == 3){

                if (intervalo_valido(intervaloAux)) {
                    if (entrada[0] == 'i' && entrada[1] == ' ' && entrada[2] == '[')
                        raiz = itree_insertar(raiz, intervaloAux);

                    else if (entrada[0] == 'e' && entrada[1] == ' ' && entrada[2] == '[')
                        raiz = itree_eliminar(raiz, intervaloAux);

                    else if (entrada[0] == '?' && entrada[1] == ' ' && entrada[2] == '['){
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
                    printf("Intervalo invalido\n");                              
            } else
                printf("Entrada invalida\n");
        } else
            printf("Largo de la entrada incorrecto\n");
    }
}

int main(){
    iTree raiz = itree_crear();

    printf("Ingrese i para insertar, e para eliminar, ? para intersecar, dfs, bfs, salir \n");

    leer_entrada (raiz);

    itree_destruir(raiz);

    return 0;
}