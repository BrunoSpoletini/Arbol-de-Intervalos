#include "itree.h"
#include <stdio.h>
#include <string.h>


int main(){

    char entrada[50], comando[10];
    int salir = 0;
    //double inicio, final;
    intervalo intervaloAux;

    iTree raiz = itree_crear();

    printf("Ingrese i para insertar, e para eliminar, ? para intersecar, dfs, bfs, salir \n");
    do{
        gets(entrada);
        sscanf(entrada, "%s [%lf,%lf] \n", comando, &intervaloAux.inicio, &intervaloAux.final);

        if (strcmp(comando,"i") == 0){
            raiz = itree_insertar(raiz, intervaloAux);
            printf("Inserto \n");
        }

        else if (strcmp(comando,"e") == 0)
            raiz = itree_eliminar(raiz, intervaloAux);
/*/
        else if (strcmp(comando,"?") == 0)
            itree_intersecar(raiz, intervaloAux);

        else if (strcmp(comando,"dfs") == 0)
            itree_recorrer_dfs(raiz);

        else if (strcmp(comando,"bfs") == 0)
            itree_recorrer_bfs(raiz);
/*/
        else if (strcmp(comando,"o") == 0)
            inorder(raiz);
/*/
        else if (strcmp(comando,"raiz") == 0){
            printf("[%lf, %lf]  max = %lf \n", raiz->intervalo->inicio, raiz->intervalo->final, raiz->maximo);
        }
        /*/

        else if (strcmp(comando,"salir") == 0)
            salir = 1;

        else
            printf("Comando no reconocido intente denuevo \n");
        
        //printf("entrada: %s\n",entrada);
        //printf("comando: %s\n",comando);
        //printf("inicio: %lf\n",inicio);
        //printf("final: %lf\n",final);
    } while (salir == 0);

    itree_destruir(raiz);

    return 0;
}