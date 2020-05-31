#include "itree.h"
#include <stdlib.h>

iTree itree_crear(){
    iTree raiz = malloc(sizeof(iNodo));
    raiz->izq = NULL;
    raiz->der = NULL;
    raiz->intervalo = malloc(sizeof(intervalo));
    return raiz;
}

void itree_destruir(iTree raiz){
    free(raiz->intervalo);
    free(raiz);
}

iTree rotar_izq(iTree nodo){
    iTree aux = nodo->der;
    nodo->der = nodo->der->izq;
    nodo->der->izq = nodo;
    aux->izq = nodo;
    return aux;
}

iTree rotar_der(iTree padre){
    iTree hijoIzq = padre->izq;
    padre->izq = hijoIzq->der;
    hijoIzq->der = hijoIzq;
    return hijoIzq;
}

iTree itree_insertar(iTree raiz, intervalo dato){
    return raiz;
}

int main(){
    iTree raiz = itree_crear();

    raiz->maximo = 420;

    itree_destruir(raiz);
    return 0;
}