#include "itree.h"
ITree itree_crear() {
  return NULL;
}

void itree_destruir(ITree nodo) {
  if (nodo != NULL) {
    itree_destruir(nodo->izq);
    itree_destruir(nodo->der);
    free(nodo->intervalo);
    free(nodo);
  }
}

int altura(ITree nodo) {
  if (nodo == NULL)
    return -1;
  else
    return nodo->altura;
}

void actualizar_altura(ITree nodo) {
  if (nodo != NULL)
    nodo->altura = MAX(altura(nodo->izq), altura(nodo->der)) + 1;
}

void actualizar_maximo(ITree nodo) {
  if (nodo != NULL) {
    if (nodo->izq == NULL || nodo->der == NULL) {
      ITree aux = nodo->izq ? nodo->izq : nodo->der;
      if (aux == NULL)
        nodo->maximo = nodo->intervalo->final;
      else
        nodo->maximo = MAX(nodo->intervalo->final, aux->maximo);
    } else
      nodo->maximo =
          MAX(nodo->intervalo->final,
              MAX(nodo->izq->maximo, nodo->der->maximo));
  }
}


ITree llenar_nodo(Intervalo dato) {
  ITree nodo = malloc(sizeof(INodo));

  nodo->izq = NULL;
  nodo->der = NULL;
  nodo->intervalo = llenar_intervalo(dato);
  nodo->maximo = dato.final;
  nodo->altura = 0;

  return nodo;
}

void liberar_nodo(ITree nodo) {
  free(nodo->intervalo);
  free(nodo);
}

ITree rotar_izq(ITree padre) {
  ITree hijoDer = padre->der;
  padre->der = hijoDer->izq;
  hijoDer->izq = padre;

  actualizar_altura(padre);
  actualizar_maximo(padre);
  actualizar_altura(hijoDer);
  actualizar_maximo(hijoDer);

  return hijoDer;
}

ITree rotar_der(ITree padre) {
  ITree hijoIzq = padre->izq;
  padre->izq = hijoIzq->der;
  hijoIzq->der = padre;

  actualizar_altura(padre);
  actualizar_maximo(padre);
  actualizar_altura(hijoIzq);
  actualizar_maximo(hijoIzq);

  return hijoIzq;
}

ITree balancear(ITree nodo) {
  if (nodo != NULL) {
    if ((altura(nodo->der) - altura(nodo->izq)) == -2) {        // desequilibrio hacia la izquierda
      if (altura(nodo->izq->izq) >= altura(nodo->izq->der))     // desequilibrio simple
        nodo = rotar_der(nodo);
      else {                    // desequilibrio doble
        nodo->izq = rotar_izq(nodo->izq);
        nodo = rotar_der(nodo);
      }
    } else if (altura(nodo->der) - altura(nodo->izq) == 2) {    // desequilibrio hacia la derecha
      if (altura(nodo->der->der) >= altura(nodo->der->izq))     // desequilibrio simple
        nodo = rotar_izq(nodo);
      else {                    // desequilibrio doble
        nodo->der = rotar_der(nodo->der);
        nodo = rotar_izq(nodo);
      }
    }
  }
  return nodo;
}


ITree itree_insertar(ITree nodo, Intervalo dato) {

  if (nodo == NULL)
    nodo = llenar_nodo(dato);

  else {
    if (nodo->maximo < dato.final)
      nodo->maximo = dato.final;

    if (dato.inicio < nodo->intervalo->inicio
        || (dato.inicio == nodo->intervalo->inicio
            && dato.final < nodo->intervalo->final))
      nodo->izq = itree_insertar(nodo->izq, dato);

    else if (dato.inicio > nodo->intervalo->inicio
             || (dato.inicio == nodo->intervalo->inicio
                 && dato.final > nodo->intervalo->final))
      nodo->der = itree_insertar(nodo->der, dato);

    else                        // Ya existe ese nodo
      return nodo;

    actualizar_altura(nodo);
    nodo = balancear(nodo);
  }

  return nodo;
}


ITree buscar_sucesor(ITree nodo) {
  ITree aux = nodo;

  for (; aux->izq != NULL; aux = aux->izq);

  return aux;
}

ITree itree_eliminar(ITree nodo, Intervalo dato) {
  if (nodo == NULL)
    return nodo;

  if (dato.inicio < nodo->intervalo->inicio
      || (dato.inicio == nodo->intervalo->inicio
          && dato.final < nodo->intervalo->final))
    nodo->izq = itree_eliminar(nodo->izq, dato);

  else if (dato.inicio > nodo->intervalo->inicio
           || (dato.inicio == nodo->intervalo->inicio
               && dato.final > nodo->intervalo->final))
    nodo->der = itree_eliminar(nodo->der, dato);

  else {
    if (nodo->izq == NULL || nodo->der == NULL) {
      ITree aux = nodo->izq ? nodo->izq : nodo->der;
      liberar_nodo(nodo);
      nodo = aux;

    } else {
      ITree aux = buscar_sucesor(nodo->der);
      *(nodo->intervalo) = *(aux->intervalo);
      nodo->der = itree_eliminar(nodo->der, *(aux->intervalo));
    }
  }

  actualizar_altura(nodo);
  actualizar_maximo(nodo);

  return balancear(nodo);
}


ITree itree_intersecar(ITree nodo, Intervalo dato) {
  if (nodo == NULL || dato.inicio > nodo->maximo)
    return NULL;

  if (intersecar(*(nodo->intervalo), dato))
    return nodo;

  if (nodo->izq != NULL && dato.inicio <= nodo->izq->maximo
      && dato.inicio >= nodo->intervalo->inicio)
    return itree_intersecar(nodo->izq, dato);

  if (dato.inicio < nodo->intervalo->inicio
      || (dato.inicio == nodo->intervalo->inicio
          && dato.final < nodo->intervalo->final))
    return itree_intersecar(nodo->izq, dato);

  if (dato.inicio > nodo->intervalo->inicio
      || (dato.inicio == nodo->intervalo->inicio
          && dato.final > nodo->intervalo->final))
    return itree_intersecar(nodo->der, dato);

  return NULL;
}

void imprimir_intervalo(ITree nodo) {
  printf("[%.2f, %.2f]", nodo->intervalo->inicio, nodo->intervalo->final);
}

void itree_recorrer_dfs(ITree nodo, FuncionVisitante func) {    // In-Order
  if (nodo != NULL) {
    itree_recorrer_dfs(nodo->izq, func);
    func(nodo);
    itree_recorrer_dfs(nodo->der, func);
  }
}

void imprimir_por_nivel(ITree nodo, int nivel, FuncionVisitante func) {
  if (nodo != NULL) {
    if (nivel == 0)
      func(nodo);

    else if (nivel > 0) {
      imprimir_por_nivel(nodo->izq, nivel - 1, func);
      imprimir_por_nivel(nodo->der, nivel - 1, func);
    }
  }
}

void itree_recorrer_bfs(ITree nodo, FuncionVisitante func) {
  if (nodo != NULL) {
    for (int i = 0; i <= (nodo->altura); i++) {
      imprimir_por_nivel(nodo, i, func);
    }
  }
}
