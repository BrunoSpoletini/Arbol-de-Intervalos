#include "itree.h"
#include <math.h>
#include <stdlib.h>

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
                nodo = rotar_der(nodo);
            }
            else{ //desequilibrio doble
                nodo->izq = rotar_izq(nodo->izq);
                nodo = rotar_der(nodo);
            }
        }
        else if (altura (nodo->der) - altura (nodo->izq) == 2)
            { // desequilibrio hacia la derecha! 
            if (altura (nodo->der->der) >= altura (nodo->der->izq))
                // desequilibrio simple
                nodo = rotar_izq(nodo);
            else{ //desequilibrio doble
                nodo->der = rotar_der(nodo->der);
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


void itree_recorrer_dfs(iTree nodo){
    if(nodo != NULL){
        itree_recorrer_dfs(nodo->izq);
        printf("[%.2f, %.2f]  %.2f\n",nodo->intervalo->inicio, nodo->intervalo->final, nodo->maximo);
        itree_recorrer_dfs(nodo->der);
    }
}

void imprimirPorNivel(iTree nodo, int nivel){
    if(nodo == NULL)
        return;
    if(nivel == 0){
        printf("%.2f ",nodo->intervalo->inicio);
    }
    else if(nivel > 0){
        imprimirPorNivel(nodo->izq, nivel-1);
        imprimirPorNivel(nodo->der, nivel-1);
    } 
} 

void itree_recorrer_bfs(iTree nodo){ 
    int i; 
    for (i = 0; i <= (nodo->altura); i++){
        imprimirPorNivel(nodo, i);
    }
    printf("\n");
}