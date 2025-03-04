#include <stdio.h>
#include <stdlib.h>

int* Sala_Teatro = NULL;
int capacidad_total = 0;

int asientos_ocupados(){
    if(Sala_Teatro == NULL){
        return -1;
    }
    int ocupados = 0;
    for(int i=0; i<=capacidad; i++){
        if(Sala_Teatro[i] == -1){
            ocupados++;
        }
    }
    return ocupados;
}

int capacidad_sala(){
    if(Sala_Teatro == NULL){
        return -1;
    }
    return capacidad
}

int crear_sala(int capacidad){
    if(Sala_Teatro != NULL){
        return -1;
    }
    capacidad_total = capacidad;
    Sala_Teatro = malloc(capacidad*sizeof(int));
    for(int i=0; i<=capacidad; i++){
        Sala_Teatro[i] = -1;
    }
    return capacidad;
}

int eliminar_sala(){
    if(Sala_Teatro == NULL){
        return -1;
    }
    free(Sala_Teatro);
    return 0;
}