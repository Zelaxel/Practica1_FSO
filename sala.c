#include <stdio.h>
#include <stdlib.h>

int* sala_teatro = NULL;
int capacidad_total = 0;

int reserva_asiento(int id_persona){
	//Falla si la sala no esta creada o si el id de la persona no es valido.
	if(sala_teatro==NULL || id_persona < 1) return -1; 

	//Busca un espacio libre.
	for(int i=0; i<capacidad_total; i++){
		if(sala_teatro[i] == -1){
			sala_teatro[i] = id_persona;
			return i;
		}
	}
	return -1; //No hay espacio libre.
}

int libera_asiento(int id_asiento){
	//Falla si la sala no esta creada o si el id del asiento se sale del espacio.
	if(sala_teatro==NULL || id_asiento >= capacidad_total || id_asiento < 0) return -1;

	//Hay asiento por lo que lo libera.
	int id_persona = sala_teatro[id_asiento];
	sala_teatro[id_asiento]=-1;
	return id_persona;

}

int estado_asiento(int id_asiento){
	//Falla si la sala no esta creada o si el id del asiento se sale del espacio.
	if(sala_teatro==NULL || id_asiento >= capacidad_total || id_asiento < 0) return -1;
	
	//El asiento esta vacío.
	if(sala_teatro[id_asiento] == -1) return 0;
	
	//Devuelve la persona que reservó el asiento.
	return sala_teatro[id_asiento];
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
	//Falla si la sala no esta creada.
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
    sala_teatro=NULL;
    return 0;
}

