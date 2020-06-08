#ifndef __ITREE_H__
#define __ITREE_H__

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "intervalo.h"
#define MAX(a,b) (((a)>(b))?(a):(b))


typedef struct _INodo{
  Intervalo *intervalo;
  double maximo;
  int altura;
  struct _INodo *izq;
  struct _INodo *der;
} INodo;

typedef INodo *ITree;

typedef void (*FuncionVisitante) (ITree nodo);

// Crea un arbol de intervalos vacio.
ITree itree_crear();

// Destruye un arbol de intervalos.
void itree_destruir(ITree nodo);

// Inserta un intervalo en un arbol de intervalos.
ITree itree_insertar(ITree raiz, Intervalo dato);

// Elimina un intervalo de un arbol de intervalos.
ITree itree_eliminar(ITree raiz, Intervalo dato);

// Determina si un intervalo se interseca con alguno de los intervalos del arbol y, en caso afirmativo,
// retorna un apuntador al nodo correspondiente.
ITree itree_intersecar(ITree raiz, Intervalo intersecar);

// Recorrido primero en profundidad del arbol de intervalos.
void itree_recorrer_dfs(ITree raiz, FuncionVisitante func);

// Recorrido primero a lo ancho del arbol de intervalos.
void itree_recorrer_bfs(ITree raiz, FuncionVisitante func);


//----------Funciones auxiliares------------//
// Devuelve la altura de un nodo, o -1 en caso de que reciba NULL.
int altura(ITree nodo);

// Actualiza la altura de un nodo dado.
void actualizar_altura(ITree nodo);

// Actualiza el valor maximo de un nodo dado teniendo en cuenta los valores maximos de sus hijos.
void actualizar_maximo (ITree nodo);

// Devuelve un nodo de tipo iTree que contiene al intervalo dato.
ITree llenar_nodo(Intervalo dato);

// Libera el espacio ocupado en memoria por el nodo y su respectivo intervalo.
void liberar_nodo(ITree nodo);

// Realiza una rotacion hacia la izquierda con respecto al nodo recibido.
ITree rotar_izq(ITree nodoPadre);

// Realiza una rotacion hacia la derecha con respecto al nodo recibido.
ITree rotar_der(ITree nodoPadre);

// Recibe un nodo, y corrige el desbalance de las ramas.
ITree balancear(ITree nodo);

// Imprime por pantalla la información de los nodos de la altura dada.
void imprimir_por_nivel(ITree nodo, int nivel, FuncionVisitante func);

// Recibe un nodo e imprime el intervalo que este contiene.
void imprimir_intervalo(ITree nodo);

#endif /* __ITREE_H__ */
