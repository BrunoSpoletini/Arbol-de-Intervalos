#include "itree.h"
#include <stdlib.h>

iTree itree_crear(){
    iTree raiz = malloc(sizeof(iNodo));
    raiz->izq = NULL;
    raiz->der = NULL;
    raiz->intervalo = malloc(sizeof(intervalo));
    return raiz;
}

void itree_destruir(iTree nodo){
    if (nodo != NULL){
        itree_destruir(nodo->izq);
        itree_destruir(nodo->der);
        free(nodo->intervalo);
        free(nodo);
    }
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
    intervalo* nuevoIntervalo = malloc(sizeof(intervalo));
    nuevoIntervalo->inicio = dato.inicio;
    nuevoIntervalo->final = dato.final;

    iTree nuevoNodo = malloc(sizeof(iTree));
    nuevoNodo->intervalo = nuevoIntervalo;
    
    return raiz;
}

int main(){
    iTree raiz = itree_crear();

    raiz->maximo = 420;

    itree_destruir(raiz);
    return 0;
}