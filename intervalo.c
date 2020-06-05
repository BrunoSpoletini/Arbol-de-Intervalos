#include "intervalo.h"
#include <stdlib.h>

int intersecar(intervalo primero, intervalo segundo) {
    return !(primero.final < segundo.inicio || primero.inicio > segundo.final);
}

int intervalo_valido(intervalo dato){
    if (dato.inicio > dato.final)
        return 0;
    return 1;
}

intervalo* llenar_intervalo(intervalo dato){
    intervalo* nuevoIntervalo = malloc(sizeof(intervalo));
    nuevoIntervalo->inicio = dato.inicio;
    nuevoIntervalo->final = dato.final;
    return nuevoIntervalo;
}