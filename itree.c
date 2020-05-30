#include "itree.h"
#include <stdlib.h>

iTree itree_crear(){
    iTree raiz = malloc(sizeof(iNodo));
    raiz->ant = NULL;
    raiz->sig = NULL;
    raiz->intervalo = malloc(sizeof(intervalo));
    return raiz;
}

void itree_destruir(iTree raiz){
    free(raiz->intervalo);
    free(raiz);
}

iTree itree_insertar(iTree raiz, intervalo dato){

}

int main(){
    iTree raiz = itree_crear();

    raiz->maximo = 420;

    itree_destruir(raiz);
    return 0;
}