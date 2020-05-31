#include "itree.h"
#include <stdlib.h>

// :DUDAS:
// en la estructura del arbol, poner el intervalo como un puntero a intervalo
// "intervalo *intervalo" ó "intervalo intervalo"?, cada uno tiene sus beneficios


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

iTree rotar_izq(iTree padre){
    iTree hijoDer = padre->der;
    padre->der = hijoDer->izq;
    hijoDer->izq = padre;
    return hijoDer;
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
    // se podra poner como nuevoIntervalo = dato ? Probar cuando el resto ande

    iTree nuevoNodo = itree_crear();
    nuevoNodo->intervalo = nuevoIntervalo;

    while(raiz != NULL){
        if(raiz->maximo < nuevoNodo->intervalo->final)
            raiz->maximo = nuevoNodo->intervalo->final;
        if((nuevoNodo->intervalo->inicio) < (raiz->intervalo->inicio)){
            raiz = raiz->izq;
        }
        else{
            raiz = raiz->der;
        }
    }

    raiz = nuevoNodo;
    
    return raiz;
}

int main(){
    iTree raiz = itree_crear();

    raiz->maximo = 420;

    itree_destruir(raiz);
    return 0;
}