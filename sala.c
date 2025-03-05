#include <stdio.h>
#include <stdlib.h>

int* sala_teatro = NULL;
int capacidad_total = 0;

int reserva_asiento(int id_persona){
	if(sala_teatro==NULL || id_persona < 1) return -1;
	for(int i=0; i<capacidad_total; i++){
		if(sala_teatro[i] == -1){
			sala_teatro[i] = id_persona;
			return i;
		}
	}
	return -1;
}

int libera_asiento(int id_asiento){
	if(sala_teatro==NULL || id_asiento >= capacidad_total || id_asiento < 0) return -1;

	int id_persona = sala_teatro[id_asiento];
	sala_teatro[id_asiento]=-1;
	return id_persona;

}

int estado_asiento(int id_asiento){
	if(sala_teatro==NULL || id_asiento >= capacidad_total || id_asiento < 0) return -1;
	if(sala_teatro[id_asiento] > -1) return 0;
	return -1;
}

int asientos_ocupados(){
    if(sala_teatro == NULL){
        return -1;
    }
    int ocupados = 0;
    for(int i=0; i<capacidad_total; i++){
        if(sala_teatro[i] == -1){
            ocupados++;
        }
    }
    return ocupados;
}

int asientos_libres(){
	if(sala_teatro==NULL) return -1;
	return capacidad_total - asientos_ocupados();
}

int capacidad_sala(){
    if(sala_teatro == NULL){
        return -1;
    }
    return capacidad_total;
}

int crea_sala(int capacidad){
    if(sala_teatro != NULL || capacidad < 1){
        return -1;
    }
    capacidad_total = capacidad;
    sala_teatro = (int*)malloc(capacidad*sizeof(int));
    for(int i=0; i<capacidad; i++){
        sala_teatro[i] = -1;
    }
    return capacidad;
}

int elimina_sala(){
    if(sala_teatro == NULL){
        return -1;
    }
    free(sala_teatro);
    return 0;
}

int capacidad(){
	return capacidad_total;
}
