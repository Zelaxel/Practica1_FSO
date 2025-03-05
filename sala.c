#include <stdio.h>
#include <stdlib.h>

int* Sala_Teatro = NULL;
int capacidad_total = 0;

int reservar_asiento(int id_persona){
	if(Sala_Teatro==NULL) return -1;
	for(int i=0; i<capacidad_total; i++){
		if(Sala_Teatro[i] > -1){
			Sala_Teatro[i] = id_persona;
			return i;
		}
	}
	return -1;
}

int libera_asiento(int id_asiento){
	if(Sala_Teatro==NULL) return -1;
	if(id_asiento < capacidad_total && 0 <= id_asiento){
		int id_persona = Sala_Teatro[id_asiento];
		Sala_Teatro[id_asiento]=-1;
		return id_persona;
	}
	return -1;
}

int estado_asiento(int id_asiento){
	if(Sala_Teatro==NULL) return -1;
	if(Sala_Teatro[id_asiento] > -1) return 0;
	return -1;
}

int asientos_ocupados(){
    if(Sala_Teatro == NULL){
        return -1;
    }
    int ocupados = 0;
    for(int i=0; i<capacidad_total; i++){
        if(Sala_Teatro[i] == -1){
            ocupados++;
        }
    }
    return ocupados;
}

int asientos_libres(){
	if(Sala_Teatro==NULL) return -1;
	return capacidad_total - asientos_ocupados();
}

int capacidad_sala(){
    if(Sala_Teatro == NULL){
        return -1;
    }
    return capacidad_total
}

int crear_sala(int capacidad){
    if(Sala_Teatro != NULL){
        return -1;
    }
    capacidad_total = capacidad;
    Sala_Teatro = malloc(capacidad*sizeof(int));
    for(int i=0; i<capacidad; i++){
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
