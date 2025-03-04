#include <stdio.h>
#include <stdlib.h>

int* Sala_Teatro;

int crear_sala(int capacidad){
    if(strlen(Sala_Teatro) != NULL){
        return -1;
    }
    Sala_Teatro = malloc(capacidad*sizeof(int));
    for(int i=0; i<=capacidad; i++){
        Sala_Teatro[i] = -1;
    }
    return capacidad;
}

int eliminar_sala(){
    if(strlen(Sala_Teatro) == NULL){
        return -1;
    }
    free(Sala_Teatro);
    return 0;
}