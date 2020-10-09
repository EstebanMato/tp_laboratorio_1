#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utnInputs.h"


int initEmployees(Employee* list, int len)
{
	int retorno =-1;
	if(list != NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			list[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}

void printEmployee(Employee empleado)
{
	printf("\n%d %20s %15s %10.4f  %9d",empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
}

void printEmployees(Employee* list, int len)
{
	printf("\n**Listado de empleados**");
	printf("\nId                 Nombre        Apellido    Salario     Sector");

	for(int i=0; i<len; i++){
		if(list[i].isEmpty == 0){
			printEmployee(list[i]);
		}
	}
}

int loadedVector(Employee* list, int len)
{
	int loaded=0;

	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==0)
		{
			loaded=1;
			break;
		}
	}
	return loaded;
}

int addEmployee(Employee* list, int id, int indice, char name[], char lastName[], float salary, int sector)
{
	int retorno=-1;

	if(list != NULL)
	{
		list[indice].id=id;
		strcpy(list[indice].name , name);
		strcpy(list[indice].lastName, lastName);
		list[indice].salary=salary;
		list[indice].sector=sector;
		list[indice].isEmpty=0;
		retorno=0;
	}

	return retorno;
}

int highEmployee(Employee* list, int len, int id)
{
	int todoOk=-1;
	int indice;
	char name[51];
	char lastName[51];
	float salary;
	int sector;



	if((indice = searchFree(list, len))!=-1)
	{
		system("clear");
		printf("\n***Alta de empleado***\n");
		todoOk=utn_getString(name, "\nIngrese el nombre: ", "\nERROR. (max 10 caracteres): ", sizeof(name), 4);
		if(todoOk==0)
		{
			todoOk=utn_getString(lastName, "\nIngrese el apellido: ", "\nERROR. (max 10 caracteres): ", sizeof(lastName), 4);
			if(todoOk==0)
			{
				todoOk=utn_getFloat(&salary, "\nIngrese el salario: ", "\nERROR. (Rango entre 1 - 100000): ", 1, 100000, 4);
				if(todoOk==0)
				{

					todoOk=utn_getNumber(&sector, "\nIngrese el sector: ", "\nERROR. (Rango entre 1-10)", 1, 10, 4);
				}
			}
		}
	}
	else
	{
		printf("\nSistema de empleados completo\n");
	}




	if(todoOk==0){
		todoOk=addEmployee(list, id, indice, name, lastName, salary, sector);
	}

	return todoOk;
}

int searchFree(Employee* list, int len)
{
	int retorno = -1;

	if(list != NULL)
	{
		for(int i=0; i<len; i++)
			{
				if(list[i].isEmpty==1)
				{
					retorno=i;
					break;
				}
			}
	}

	return retorno;
}

int findEmployeeById(Employee* list, int len, int id)
{
	int indice=-1;

	for(int i=0;i<len;i++)
	{
		if (list[i].id==id && list[i].isEmpty==0)
		{
			indice=i;
		}
	}
	return indice;
}

int lowEmployee(Employee* list, int len)
{
	int retorno=-1;
	int idEmployee;

	system("clear");
	printf("\n***Baja de empleado***\n");
	printEmployees(list, len);
	printf("\n\nIngrese el Id de empleado a dar de baja: ");
	__fpurge(stdin);
	scanf("%d",&idEmployee);

	if(!(removeEmployee(list, len, idEmployee)))
	{
		printf("\nBaja exitosa!! ");
	}
	else
	{
		printf("\nERROR en la baja!! ");
	}


	return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno=-1;
	int indiceEmployee;
	char borrar;

	indiceEmployee = findEmployeeById(list, len, id);

	if(indiceEmployee==-1)
	{
		printf("\nNo existe el empleado con numero de Id ingresado");
	}
	else
	{
		printf("\nId                 Nombre        Apellido    Salario    Sector");
		printEmployee(list[indiceEmployee]);
		printf("\n\nConfirma la baja del empleado(s/n): ");
		__fpurge(stdin);
		scanf("%c",&borrar);

		if(borrar=='s')
		{
			list[indiceEmployee].isEmpty=1;
			retorno=0;
		}
		else
		{
			printf("\nLa operacion se ha cancelado ");
		}
	}

	return retorno;
}

void modifyEmployee(Employee* list, int len)
{
	int retorno=-1;
	int option;
	int idEmployee;
	int indiceEmployee;
	int sector;
	char salir='n';
	char name[51];
	char lastName[51];
	char change='n';
	float salary;



	system("clear");
	printf("***Modificar empleado***");
	printEmployees(list, len);
	printf("\n\nIngrese el Id de empleado a modificar: ");
	__fpurge(stdin);
	scanf("%d",&idEmployee);
	indiceEmployee = findEmployeeById(list, len, idEmployee);

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
			printf("\nId       Nombre   Apellido    Salario    Sector");
			printEmployee(list[indiceEmployee]);
			printf("\n\nQue desea modificar?");
			printf("\n1-Nombre");
			printf("\n2-Apellido");
			printf("\n3-Salario");
			printf("\n4-Sector");
			printf("\n\n5-Salir");
			printf("\nIngrese opcion: ");
			scanf("%d",&option);

			switch(option)
			{

			case 1:
				retorno=utn_getString(name, "\nIngrese el nuevo nombre: ", "\nERROR. (max 50 caracteres): ", sizeof(name), 3);

				if(retorno==0)
				{
					printf("\nEl nuevo nombre ingresado es '%s', desea continuar y efectuar el cambio? (s/n): ",name);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						strcpy(list[indiceEmployee].name,name);
						printf("\nSe realizo el cambio corectamente!");
					}
				}else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;

			case 2:
				retorno=utn_getString(lastName, "\nIngrese el nuevo apellido: ", "\nERROR. (max 50 caracteres): ", sizeof(lastName), 3);

				if(retorno==0)
				{
					printf("\nEl nuevo apellido ingresado es '%s', desea continuar y efectuar el cambio? (s/n): ",lastName);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						strcpy(list[indiceEmployee].lastName,lastName);
						printf("\nSe realizo el cambio corectamente!");
					}
				}else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;

			case 3:
				retorno=utn_getFloat(&salary, "\nIngrese el nuevo salario: ", "\nERROR. (Rango entre 1 - 100000): ", 1, 100000, 3);

				if(retorno==0)
				{
					printf("\nEl nuevo salario ingresado es '%f', desea continuar y efectuar el cambio? (s/n): ",salary);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						list[indiceEmployee].salary=salary;
						printf("\nSe realizo el cambio corectamente!");
					}
				}
				else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;

			case 4:
				retorno=utn_getNumber(&sector, "\nIngrese el nuevo sector: ", "\nERROR. (Rango entre 1-10)", 1, 10, 3);

				if(retorno==0)
				{
					printf("\nEl nuevo sector ingresado es '%d', desea continuar y efectuar el cambio? (s/n): ",sector);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change=='s')
					{
						list[indiceEmployee].sector=sector;
						printf("\nSe realizo el cambio corectamente!");
					}
				}
				else
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
				printf("\nOpcion invalida");
			}

			__fpurge(stdin);
			getchar();
		}while(salir!='s');
	}

}


int sortEmployees(Employee* list, int len, int order)
{
	int retorno=-1;
	int flagSwap;
	int i;
	Employee auxEmployee;

	if(list != NULL && len > 0)
	{
		if(order == 1)
		{
			retorno=0;
			do
			{
				flagSwap=0;
				for(i=0; i<len; i++)
				{
					if(list[i].isEmpty || list[i+1].isEmpty)
					{
						continue;
					}

					if(strcmp(list[i].name, list[i+1].name) > 0)
					{
						flagSwap = 1;
						auxEmployee=list[i];
						list[i]=list[i+1];
						list[i+1]=auxEmployee;
					}
					else
					{
						if(strcmp(list[i].name, list[i+1].name) == 0)
						{
							if(list[i].sector > list[i+1].sector)
							{
								flagSwap = 1;
								auxEmployee=list[i];
								list[i]=list[i+1];
								list[i+1]=auxEmployee;
							}
						}
					}
				}
				len--;
			}while(flagSwap);
		}
		else
		{
			if(order == 2)
			{
				retorno=0;
				do
				{
					flagSwap=0;
					for(i=0; i<len; i++)
					{
						if(list[i].isEmpty || list[i+1].isEmpty)
						{
							continue;
						}

						if(strcmp(list[i].name, list[i+1].name) < 0)
						{
							flagSwap = 1;
							auxEmployee=list[i];
							list[i]=list[i+1];
							list[i+1]=auxEmployee;
						}
						else
						{
							if(strcmp(list[i].name, list[i+1].name) == 0)
							{
								if(list[i].sector < list[i+1].sector)
								{
									flagSwap = 1;
									auxEmployee=list[i];
									list[i]=list[i+1];
									list[i+1]=auxEmployee;
								}
							}
						}
					}
					len--;
				}while(flagSwap);
			}
		}
	}
	return retorno;
}

int hardcodearEmpleados(Employee* list, int len, int cantidad)
{
	//tenemos 10 empleados como maximo para hardcodear
	int contador=0;

	if(list != NULL && cantidad >0)
	{
		Employee listaSuplentes[]={{1000,"Franco","Armani",      250.20,9,0},
								   {1001,"Gonzalo","Montiel",    300.50,6,0},
								   {1002,"Ignacio","Fernandez",  100.95,13,0},
								   {1003,"JuanFer","Quinteros",  250.20,9,0},
								   {1004,"Franco","Armani",      250.20,5,0},
								   {1005,"Juan","De La Cruz",    250.150,7,0},
								   {1006,"Franco","Armani",      250.20,1,0},
								   {1007,"Marcelo","Gallardo",   250.99,1,0},
								   {1008,"Enzo","Perez",         250.20,5,0},
								   {1009,"Milton","Caso",        10000.380,5,0} };

		if(cantidad <= len && cantidad <=10)
		{
			for(int i=0; i<cantidad; i++)
			{
				list[i]=listaSuplentes[i];
				contador++;
			}
		}

	}

	return contador;
}



