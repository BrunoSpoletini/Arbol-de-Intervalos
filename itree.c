#include "itree.h"
#include <math.h>
#include <stdlib.h>

// :DUDAS:
// en la estructura del arbol, poner el intervalo como un puntero a intervalo
// "intervalo *intervalo" ó "intervalo intervalo"?, cada uno tiene sus beneficios


iTree itree_crear(){
    return NULL;
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
    hijoIzq->der = padre;
    return hijoIzq;
}

int altura(iTree nodo){
    if(nodo == NULL)
        return -1;
    else
        return nodo->altura;
}

void actualizar_altura(iTree nodo){
    if(nodo != NULL){
        nodo->altura = fmax(altura(nodo->izq), altura(nodo->der)) + 1;
    }
}

iTree llenar_nodo(intervalo dato){
    iTree nodo = malloc(sizeof(iNodo));
    nodo->izq = NULL;
    nodo->der = NULL;
    nodo->intervalo = malloc(sizeof(intervalo));

    intervalo* nuevoIntervalo = malloc(sizeof(intervalo));
    nuevoIntervalo->inicio = dato.inicio;
    nuevoIntervalo->final = dato.final;
    nodo->intervalo = nuevoIntervalo;
    nodo->maximo = dato.final;
    nodo->altura = 0;
    return nodo;
}

iTree balancear(iTree nodo){
    if(nodo != NULL){
        if((altura(nodo->der) - altura(nodo->izq)) == -2){
             // desequilibrio hacia la izquierda!
            if (altura(nodo->izq->izq) >= altura(nodo->izq->der)){
                // desequilibrio simple
                ///////nodo = rotar_izq(nodo);
                nodo = rotar_der(nodo);
            }
            else{ //desequilibrio doble
                //////nodo->izq = rotar_der(nodo->izq);
                //////nodo = rotar_izq(nodo);
                nodo = rotar_der(nodo);
            }
        }
        else if (altura (nodo->der) - altura (nodo->izq) == 2)
            { // desequilibrio hacia la derecha! 
            if (altura (nodo->der->der) >= altura (nodo->der->izq))
                // desequilibrio simple
                //////nodo = rotar_der(nodo);
                nodo = rotar_izq(nodo);
            else{ //desequilibrio doble
                /////nodo->der = rotar_izq(nodo->der);
                /////nodo = rotar_der(nodo);
                nodo->izq = rotar_der(nodo->izq);
                nodo = rotar_izq(nodo);
            }
        }
    }
    return nodo;
}


iTree itree_insertar(iTree nodo, intervalo dato){
    if(nodo == NULL){
        nodo = llenar_nodo(dato); 
    }
    else{
        if(nodo->maximo < dato.final)
            nodo->maximo = dato.final;
        if((dato.inicio) < (nodo->intervalo->inicio))
            nodo->izq = itree_insertar(nodo->izq, dato);
        else
            nodo->der = itree_insertar(nodo->der, dato);
        nodo = balancear(nodo);
        actualizar_altura(nodo);
    }
    
    return nodo;
}

int main(){
    iTree raiz = itree_crear();

    intervalo dato = {1, 100};

    raiz = itree_insertar(raiz, dato);

    intervalo dato2 = {2, 200};
    
    raiz = itree_insertar(raiz, dato2);

    intervalo dato3 = {3, 200};
    
    //printf("%f\n", raiz->intervalo->inicio);

    raiz = itree_insertar(raiz, dato3);

    intervalo dato4 = {4, 200};

    intervalo dato5 = {5, 200};
    raiz = itree_insertar(raiz, dato4);
    raiz = itree_insertar(raiz, dato5);


    printf("%f\n", raiz->der->intervalo->inicio);
    

    itree_destruir(raiz);
    return 0;
}