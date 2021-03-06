#include "intervalo.h"
#include <stdlib.h>

Intervalo *llenar_intervalo(Intervalo dato) {
  Intervalo *nuevoIntervalo = malloc(sizeof(Intervalo));
  nuevoIntervalo->inicio = dato.inicio;
  nuevoIntervalo->final = dato.final;

  return nuevoIntervalo;
}

int intervalo_valido(Intervalo dato) {
  if (dato.inicio > dato.final)
    return 0;
  return 1;
}

int intersecar(Intervalo primero, Intervalo segundo) {
  return !(primero.final < segundo.inicio || primero.inicio > segundo.final);
}
