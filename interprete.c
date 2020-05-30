#include <stdio.h>
#include <string.h>
//#include <itree.h>

int main(){

    char entrada[50], comando[10];
    int salir = 0;
    double inicio, final;

    //raiz = itree_crear();

    printf("Ingrese i para insertar, e para eliminar, ? para intersecar, dfs, bfs, salir \n");
    do{
        gets(entrada);
        sscanf(entrada, "%s [%lf,%lf] \n", comando, &inicio, &final);

        if (strcmp(comando,"i") == 0)
            //itree_insertar(raiz, dato);
            printf("insertar \n");
        else if (strcmp(comando,"e") == 0)
            //itree_eliminar(raiz, dato);
            printf("eliminar \n");
        else if (strcmp(comando,"?") == 0)
            //itree_intersecar(raiz, intersecar);
            printf("intersecar \n");
        else if (strcmp(comando,"dfs") == 0)
            //itree_recorrer_dfs(raiz);
            printf("dfs \n");
        else if (strcmp(comando,"bfs") == 0)
            //itree_recorrer_bfs(raiz);
            printf("bfs \n");
        else if (strcmp(comando,"salir") == 0){
            //itree_destruir(raiz);
            salir = 1;
        }
        else
            printf("comando no reconocido \n");
        

        printf("entrada: %s\n",entrada);
        printf("comando: %s\n",comando);
        printf("inicio: %lf\n",inicio);
        printf("final: %lf\n",final);
    } while (salir == 0);


    return 0;
}