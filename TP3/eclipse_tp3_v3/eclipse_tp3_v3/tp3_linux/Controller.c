#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utnInputs.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno=-1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen (path,"r");
		if(pFile != NULL)
		{
			retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
		}
	}
	fclose(pFile);

    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno=-1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen (path,"rb");
		if(pFile != NULL)
		{
			retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		}
	}
	fclose(pFile);

	return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    system("clear");
	int retorno=-1;
	int idAux;
	char nombreAux[128];
	int horasTrabajadasAux;
	int sueldoAux;

	printf("\n***Alta de empleado***\n");

	retorno=utn_getNumber(&idAux, "\nIngrese el numero de id: ", "\nERROR. (Rango entre 1-10000)", 1, 10000, 3);
	if(retorno==0)
	{
		if(findEmployeeById(pArrayListEmployee, idAux)==-1)
		{
			retorno=utn_getString(nombreAux, "\nIngrese el nombre: ", "\nERROR. (max 127 caracteres): ", sizeof(nombreAux), 3);
			if(retorno==0)
			{
				retorno=utn_getNumber(&horasTrabajadasAux, "\nIngrese las horas trabajadas: ", "\nERROR. (Rango entre 0-100)", 0, 100, 3);
				if(retorno==0)
				{
					retorno=utn_getNumber(&sueldoAux, "\nIngrese el sueldo: ", "\nERROR. (Rango entre 1-1000000)", 1, 1000000, 3);
				}
			}
		}
		else
		{
			printf("\nYa existe el numero de id");
			retorno=-1;
		}

	}

	if(retorno==0)
	{
		Employee* empAux=employee_newParametrosInt(idAux, nombreAux, horasTrabajadasAux, sueldoAux);
		ll_add(pArrayListEmployee, empAux);
	}

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empAux;
	int retorno=-1;
	int idAux;
	char nombreAux[128];
	int horasTrabajadasAux;
	int sueldoAux;
	int option;
	int indiceEmployee;
	char salir='n';
	char change='n';


	system("clear");
	printf("***Modificar empleado***");
	showEmployees(pArrayListEmployee);
	printf("\n\nIngrese el Id de empleado a modificar: ");
	__fpurge(stdin);
	scanf("%d",&idAux);
	indiceEmployee = findEmployeeById(pArrayListEmployee, idAux);

	if(indiceEmployee==-1)
	{
		printf("\nNo existe el empleado con numero de Id ingresado");
	}
	else
	{
		do{
			retorno=-1;
			change='n';
			system("clear");
			printf("\n***Modificar empleado***\n");
			printf("\nID    NOMBRE          HORAS  SUELDO");
			empAux=(Employee*) ll_get(pArrayListEmployee, indiceEmployee);
			showEmployee(empAux);
			printf("\n\nQue desea modificar?");
			printf("\n1-Id");
			printf("\n2-Nombre");
			printf("\n3-Horas trabajadas");
			printf("\n4-Sueldo");
			printf("\n\n5-Salir");
			printf("\nIngrese opcion: ");
			__fpurge(stdin);
			scanf("%d",&option);

			switch(option)
			{

			case 1:
				retorno=utn_getNumber(&idAux, "\nIngrese el numero de id: ", "\nERROR. (Rango entre 1-10000)", 1, 10000, 3);

				if(retorno==0)
				{
					if(findEmployeeById(pArrayListEmployee, idAux)==-1)
					{
						printf("\nEl nuevo id ingresado es '%d', desea continuar y efectuar el cambio? (s/n): ",idAux);
						__fpurge(stdin);
						scanf("%c", &change);
						if(change =='s')
						{
							if(!employee_setId(empAux, idAux))
							{
								printf("\nSe realizo el cambio corectamente!");
							}else
							{
								printf("\nERROR al modificar el cambio!");
							}

						}
					}
					else
					{
						printf("\nYa existe el numero de id");
						printf("\nError! (no fue modificado ningun dato del empleado)");
					}

				}else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;

			case 2:
				retorno=utn_getString(nombreAux, "\nIngrese el nombre: ", "\nERROR. (max 127 caracteres): ", sizeof(nombreAux), 3);

				if(retorno==0)
				{
					printf("\nEl nuevo nombre ingresado es '%s', desea continuar y efectuar el cambio? (s/n): ",nombreAux);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						if(!employee_setNombre(empAux, nombreAux))
						{
							printf("\nSe realizo el cambio corectamente!");
						}else
						{
							printf("\nERROR al modificar el cambio!");
						}

					}
				}else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;

			case 3:
				retorno=utn_getNumber(&horasTrabajadasAux, "\nIngrese las horas trabajadas: ", "\nERROR. (Rango entre 0-100)", 0, 100, 3);

				if(retorno==0)
				{
					printf("\nLa nueva cantidad de horas trabajadas es '%d', desea continuar y efectuar el cambio? (s/n): ",horasTrabajadasAux);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						if(!employee_setHorasTrabajadas(empAux, horasTrabajadasAux))
						{
							printf("\nSe realizo el cambio corectamente!");
						}else
						{
							printf("\nERROR al modificar el cambio!");
						}

					}
				}else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;

			case 4:
				retorno=utn_getNumber(&sueldoAux, "\nIngrese el sueldo: ", "\nERROR. (Rango entre 1-1000000)", 1, 1000000, 3);
				if(retorno==0)
				{
					printf("\nEl nuevo sueldo ingresado es '%d', desea continuar y efectuar el cambio? (s/n): ",sueldoAux);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						if(!employee_setSueldo(empAux, sueldoAux))
						{
							printf("\nSe realizo el cambio corectamente!");
						}else
						{
							printf("\nERROR al modificar el cambio!");
						}

					}
				}else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
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
	}
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idAux;
	int indiceEmployee;
	char borrar;
	Employee* empAux;


	system("clear");
	printf("***Modificar empleado***");
	showEmployees(pArrayListEmployee);
	printf("\n\nIngrese el Id de empleado a modificar: ");
	__fpurge(stdin);
	scanf("%d",&idAux);
	indiceEmployee = findEmployeeById(pArrayListEmployee, idAux);

	if(indiceEmployee==-1)
	{
		printf("\nNo existe el empleado con numero de Id ingresado");
	}
	else
	{
		printf("\nID    NOMBRE          HORAS  SUELDO");
		empAux=(Employee*) ll_get(pArrayListEmployee, indiceEmployee);
		showEmployee(empAux);
		printf("\n\nConfirma la baja del empleado(s/n): ");
		__fpurge(stdin);
		scanf("%c",&borrar);

		if(borrar=='s')
		{
			ll_remove(pArrayListEmployee, indiceEmployee);
			free(empAux);
			retorno=0;
		}
		else
		{
			printf("\nLa operacion se ha cancelado ");
		}
	}
    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(pArrayListEmployee!=NULL)
	{
		showEmployees(pArrayListEmployee);
	}

	printf("\n\nPulse una tecla para continuar...");
    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int order;
	int option;
	system("clear");
	if(pArrayListEmployee!=NULL)
	{

		utn_getNumber(&option, "Como desea ordenar?\n"
							"\n1- Por id"
							"\n2- Por nombre alfabeticamente"
							"\n3- Por cantidad de horas trabajadas"
							"\n4- Por sueldo"
							"\n\nIngrese la opcion elegida: ", "\nERROR OPCION INCORRECTA (1-4)\n", 1, 4, 3);
		utn_getNumber(&order, "Ingrese orden deseado: Descendente 0 - Ascendente 1: ","\nERROR OPCION INCORRECTA (0-1)\n",0,1,3);

		switch(option)
		{
		case 1:
			printf("\nAguarde un momento, esto podria tardar un poco...");
			ll_sort(pArrayListEmployee, ordenarId, order);
			retorno=0;
			break;
		case 2:
			printf("\nAguarde un momento, esto podria tardar un poco...");
			ll_sort(pArrayListEmployee, ordenarNombre, order);
			retorno=0;
			break;
		case 3:
			printf("\nAguarde un momento, esto podria tardar un poco...");
			ll_sort(pArrayListEmployee, ordenarHorasTrabajadas, order);
			retorno=0;
			break;
		case 4:
			printf("\nAguarde un momento, esto podria tardar un poco...");
			ll_sort(pArrayListEmployee, ordenarSueldo, order);
			retorno=0;
			break;

		default:
			printf("\nOPCION INVALIDA");
			break;
		}
	}
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* empAux;
	int retorno=-1;
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;



	if(pArrayListEmployee != NULL && path != NULL)
	{
		if(ll_len(pArrayListEmployee)>0)
		{
			pFile=fopen(path,"w");
			if(pFile!=NULL)
			{
				fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
				for( int i=0; i<ll_len(pArrayListEmployee);i++)
				{
					empAux=(Employee*)ll_get(pArrayListEmployee, i);
					employee_getId(empAux, &auxId);
					employee_getNombre(empAux, auxNombre);
					employee_getHorasTrabajadas(empAux, &auxHorasTrabajadas);
					employee_getSueldo(empAux, &auxSueldo);

					fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);

				}
				fclose(pFile);
				retorno=0;
			}
		}
	}

    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* empAux;
	//int size = ll_len(pArrayListEmployee);
	int retorno = -1;

	if(pArrayListEmployee != NULL && (ll_len(pArrayListEmployee)>0))
	{
		pFile=fopen(path,"wb");
		if(pFile!=NULL)
		{
			for(int i=0;i<ll_len(pArrayListEmployee);i++)
			{
				empAux=ll_get(pArrayListEmployee, i);
				if(empAux!=NULL)
				{
					fwrite(empAux,sizeof(Employee),1,pFile);
				}
			}
			retorno=0;
			fclose(pFile);
		}
	}
    return retorno;
}

void deleteEmployeLinkedlist(LinkedList* pArrayListEmployee)
{
	Employee* empAux;
	for(int i; i<ll_len(pArrayListEmployee);i++)
	{
		empAux=ll_get(pArrayListEmployee, i);
		free(empAux);
	}
	ll_deleteLinkedList(pArrayListEmployee);
}

