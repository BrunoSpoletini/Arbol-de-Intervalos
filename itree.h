#ifndef __ITREE_H__
#define __ITREE_H__

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _intervalo{
  double inicio;
  double final;
}intervalo;


typedef struct _iNodo{
  intervalo *intervalo;
  double maximo;
  int altura;
  struct _iNodo *izq;
  struct _iNodo *der;
} iNodo;

typedef iNodo *iTree;

typedef void (*funcionVisitante) (iTree nodo);

// Crea un arbol de intervalos vacio
iTree itree_crear();

// Destruye un arbol de intervalos
void itree_destruir(iTree nodo);

// Inserta un intervalo en un arbol de intervalos
iTree itree_insertar(iTree raiz, intervalo dato);

// Elimina un intervalo de un arbol de intervalos
iTree itree_eliminar(iTree raiz, intervalo dato);

// Determina si un intervalo se interseca con alguno de los intervalos del arbol y, en caso afirmativo,
// retorna un apuntador al nodo correspondiente.
iTree itree_intersecar(iTree raiz, intervalo intersecar);

// Recorrido primero en profundidad del arbol de intervalos
void itree_recorrer_dfs(iTree raiz, funcionVisitante func);

// Recorrido primero a lo ancho del arbol de intervalos
void itree_recorrer_bfs(iTree raiz, funcionVisitante func);


//----------Funciones auxiliares------------//
// Devuelve un nodo de tipo iTree que contiene al intervalo dato
iTree llenar_nodo(intervalo dato);

// Actualiza la altura de un nodo dado
void actualizar_altura(iTree nodo);

// Devuelve la altura de un nodo, o -1 en caso de que reciba NULL
int altura(iTree nodo);

// Recibe un nodo, y corrige el desbalance de las ramas
iTree balancear(iTree nodo);

// Imprime por pantalla la información de los nodos de la altura dada
void imprimirPorNivel(iTree nodo, int nivel, funcionVisitante func);

// Recibe un nodo e imprime el intervalo que este contiene
void imprimir_intervalo(iTree nodo);

// Actualiza el valor maximo de un nodo dado
void actualizar_maximo (iTree nodo);

// Realiza una rotacion hacia la izquierda con respecto al nodo recibido
iTree rotar_izq(iTree nodoPadre);

// Realiza una rotacion hacia la derecha con respecto al nodo recibido
iTree rotar_der(iTree nodoPadre);

int intersecar(intervalo datoNodo, intervalo datoRecibido);


#endif /* __ITREE_H__ */
