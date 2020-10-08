#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "arrayEmployees.h"
#include "utnInputs.h"
#define ELEMENTS 10


int main(void) {
	setbuf(stdout, NULL);

	char salir='n';
	int id=1000;
	int todoOk=0;

	Employee arrayEmployees[ELEMENTS];

	todoOk = initEmployees(arrayEmployees, ELEMENTS);

	//hardcodeo de empleados, max 10
	//id = id + hardcodearEmpleados(arrayEmployees, ELEMENTS, 10);

	if(todoOk==0)
	{

		do{
			switch(menu()){
				case 1:
					if(highEmployee(arrayEmployees, ELEMENTS, id)==0){
						id++;
						printf("\nEmpleado dado de alta correctamente!");

					}else{
						printf("\nError! (no fue dado de alta ningun empleado)");
					}
					break;

				case 2:
					if(loadedVector(arrayEmployees,ELEMENTS)){
						modifyEmployee(arrayEmployees, ELEMENTS);
					}else{
						printf("\nSe debe cargar primero algun empleado");
					}
					break;

				case 3:
					if(loadedVector(arrayEmployees,ELEMENTS)){
						lowEmployee(arrayEmployees, ELEMENTS);
					}else{
						printf("\nSe debe cargar primero algun empleado");
					}
					break;

				case 4:
					if(loadedVector(arrayEmployees,ELEMENTS)){
						menuInformes(arrayEmployees, ELEMENTS);
					}else{
						printf("\nSe debe cargar primero algun empleado");
					}
					break;

				case 5:
					printf("\nConfirma que desea salir del sistema? (s/n): ");
					__fpurge(stdin);
					scanf("%c", &salir);
					break;

				default:
					printf("\nOPCION INVALIDA");
			}

			__fpurge(stdin);
			getchar();
		}while(salir!='s');
	}else
	{
		system("clear");
		printf("\nERROR AL INICIAR EL ARRAY\n\n");
		getchar();
	}

	return EXIT_SUCCESS;
}


