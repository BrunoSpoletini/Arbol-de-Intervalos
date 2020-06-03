#include "itree.h"
#include <stdio.h>
#include <string.h>

int main(){

    char entrada[50], comando[10];
    int salir = 0;
    intervalo intervaloAux;

    iTree raiz = itree_crear();

    printf("Ingrese i para insertar, e para eliminar, ? para intersecar, dfs, bfs, salir \n");

    /*/
    do{
        gets(entrada);
        sscanf(entrada, "%s [%lf,%lf] \n", comando, &intervaloAux.inicio, &intervaloAux.final);

        if (strcmp(comando,"i") == 0)
            raiz = itree_insertar(raiz, intervaloAux);
        

    //    else if (strcmp(comando,"e") == 0)
     //       itree_eliminar(raiz, intervaloAux);

     //   else if (strcmp(comando,"?") == 0)
     //       itree_intersecar(raiz, intervaloAux);

        else if (strcmp(comando,"dfs") == 0)
            itree_recorrer_dfs(raiz);

        else if (strcmp(comando,"bfs") == 0)
            itree_recorrer_bfs(raiz);

        else if (strcmp(comando,"salir") == 0)
            salir = 1;

        else
            printf("Comando no reconocido intente denuevo \n");
        
        //printf("entrada: %s\n",entrada);
        //printf("comando: %s\n",comando);
        //printf("inicio: %lf\n",inicio);
        //printf("final: %lf\n",final);
    } while (salir == 0);/**/

/*/    intervaloAux.final = 100;
    intervaloAux.inicio = 10;
    raiz = itree_insertar(raiz, intervaloAux);

    intervaloAux.inicio = 5;
    raiz = itree_insertar(raiz, intervaloAux);

    intervaloAux.inicio = 15;
    raiz = itree_insertar(raiz, intervaloAux);

    intervaloAux.inicio = 3;
    raiz = itree_insertar(raiz, intervaloAux);

    intervaloAux.inicio = 6;
    raiz = itree_insertar(raiz, intervaloAux);

    intervaloAux.inicio = 14;
    raiz = itree_insertar(raiz, intervaloAux);

    intervaloAux.inicio = 16;
    raiz = itree_insertar(raiz, intervaloAux);

    intervaloAux.inicio = 2;
    raiz = itree_insertar(raiz, intervaloAux);

    intervaloAux.inicio = 4;
    raiz = itree_insertar(raiz, intervaloAux);
/*/

    while(salir == 0){
        intervaloAux.inicio = 0, intervaloAux.final = 0;
        gets(entrada);
        sscanf(entrada, "%s [%lf,%lf] \n", comando, &intervaloAux.inicio, &intervaloAux.final);
        //printf("[%.2f, %.2f] dato   \n",intervaloAux.inicio, intervaloAux.final); checkear [1, 1ffsadfas222]

        if (strcmp(comando,"i") == 0)
            raiz = itree_insertar(raiz, intervaloAux);

        else if (strcmp(comando,"e") == 0)
            raiz = itree_eliminar(raiz, intervaloAux);

        else if (strcmp(comando,"?") == 0){
            if(itree_intersecar(raiz, intervaloAux) != NULL)
                printf("Si\n");
            else
                printf("No\n");
        }

        else if (strcmp(comando,"dfs") == 0){
            itree_recorrer_dfs(raiz, imprimir_intervalo);
            printf("\n");
        }

        else if (strcmp(comando,"bfs") == 0)
            itree_recorrer_bfs(raiz, imprimir_intervalo);

        else if (strcmp(comando,"salir") == 0)
            salir = 1;
        else
            printf("Comando no reconocido, intente de nuevo \n");
    }

    itree_destruir(raiz);

    return 0;
}