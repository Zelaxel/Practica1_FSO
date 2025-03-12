#include <assert.h>
#include <stdio.h>
#include "sala.h"
#include "sala.c"

#define DebeSerCierto(x)	assert(x)
#define DebeSerFalso(x)		assert(!(x))

void INICIO_TEST (const char* titulo_test)
{
  printf("********** batería de pruebas para %s: ", titulo_test); 
 	// fflush fuerza que se imprima el mensaje anterior
	// sin necesidad de utilizar un salto de línea
	fflush(stdout);
}

void FIN_TEST (const char* titulo_test)
{
  printf ("********** hecho\n");
}

void test_NoHaySala()
{	
	#define CAPACIDAD 500
	#define ID_1 1500

	INICIO_TEST("No hay sala");
	DebeSerCierto(reserva_asiento(ID_1)==-1);
	DebeSerCierto(libera_asiento(ID_1)==-1);
	DebeSerCierto(estado_asiento(ID_1)==-1);
	DebeSerCierto(asientos_ocupados()==-1);
	DebeSerCierto(asientos_libres()==-1);
	DebeSerCierto(capacidad_sala()==-1);
	DebeSerCierto(elimina_sala()==-1);
	DebeSerCierto(crea_sala(CAPACIDAD)==CAPACIDAD);
	DebeSerCierto(crea_sala(CAPACIDAD)==-1);
	DebeSerCierto(elimina_sala()==0);
	FIN_TEST("No hay sala");
}

void test_ReservaBasica()
{
	int mi_asiento;
	#define CAPACIDAD 500
	#define ID_1 1500

	INICIO_TEST("Reserva básica");
	crea_sala(CAPACIDAD);
	DebeSerCierto(capacidad_sala()==CAPACIDAD);
	DebeSerCierto((mi_asiento=reserva_asiento(ID_1))>=0);
	DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD);
	DebeSerCierto(estado_asiento(mi_asiento)>0);
	DebeSerCierto(libera_asiento(mi_asiento)==ID_1);
	DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD);
	elimina_sala();
	FIN_TEST("Reserva básica");
}

void test_liberaAsiento()
{
	int mi_asiento;

	#define CAPACIDAD 500
	#define ID_1 1500
	#define ID_2 1600

	INICIO_TEST("Libera asiento");
	crea_sala(CAPACIDAD);
	DebeSerCierto(capacidad_sala()==CAPACIDAD);
	DebeSerCierto(asientos_libres()==500);
	DebeSerCierto(asientos_ocupados()==0);
	
	// Persona 1 reserva asiento.
	mi_asiento=reserva_asiento(ID_1);
	DebeSerCierto(estado_asiento(mi_asiento)==ID_1);
	DebeSerCierto(asientos_libres()==499);
	DebeSerCierto(asientos_ocupados()==1);
	DebeSerCierto(libera_asiento(mi_asiento)==ID_1);
	DebeSerCierto(estado_asiento(mi_asiento)==0);
	DebeSerCierto(asientos_libres()==500);
	DebeSerCierto(asientos_ocupados()==0);
	
	// Persona 2 reserva el mismo asiento.
	DebeSerCierto(reserva_asiento(ID_2) == mi_asiento);
	DebeSerCierto(estado_asiento(mi_asiento)==ID_2);
	DebeSerCierto(asientos_libres()==499);
	DebeSerCierto(asientos_ocupados()==1);
	DebeSerCierto(libera_asiento(mi_asiento)==ID_2);
	DebeSerCierto(estado_asiento(mi_asiento)==0);
	DebeSerCierto(asientos_libres()==500);
	DebeSerCierto(asientos_ocupados()==0);
	elimina_sala();
	
	FIN_TEST("Libera asiento");
}

void ejecuta_tests ()
{
	test_ReservaBasica();
	// Añadir nuevos tests 
	test_NoHaySala();
	test_liberaAsiento();
}

int main()
{
	puts("Iniciando tests...");
	
	ejecuta_tests();
	
	puts("Batería de test completa.");
}
