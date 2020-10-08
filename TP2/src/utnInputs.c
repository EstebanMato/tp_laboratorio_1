#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utnInputs.h"

int menu(){

    int option;

    system("clear");
    printf("****ABM EMPLEADOS TP2****\n\n");
    printf("** Nomina de empleados **\n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Listar empleados\n");
    printf("5- Salir\n");
    printf("\nIngrese opcion: ");
    __fpurge(stdin);
    scanf("%d", &option);

    return option;

}


void menuInformes(Employee* list, int len){

    int option;
    int order=0;
    float accumulator=0;
    int counter=0;
    float average;
    int cantEmployee=0;

    system("clear");
    printf("**INFORMES**\n\n");
    printf("1-Listado ordenado alfabeticamente por apellido y sector\n");
    printf("2-Total y promedio de salarios\n");
    printf("\nIngrese opcion: ");
    __fpurge(stdin);
    scanf("%d", &option);

    switch(option)
    {
    case 1:
    	printf("\n1-Ordenado ascendentemente");
    	printf("\n2-Ordenado descendentemente");
    	printf("\nIngrese opcion: ");
		__fpurge(stdin);
		scanf("%d", &order);

		sortEmployees(list, len, order);
		printEmployees(list, len);
    	break;

    case 2:

    	for (int i=0; i<len; i++)
    	{
    		if(list[i].isEmpty==0)
    		{
    			accumulator += list[i].salary;
    			counter++;
    		}
    	}


    	system("clear");
    	printf("**Promedio de sueldos**");
		printf("\n\nEl total de los salarios es %.3f", accumulator);
		average=(float)accumulator/counter;
		printf("\nEl sueldo promedio es %.3f", average);
		printf("\n\nLos empleados que superan el sueldo promedio son");
		printf("\nId                 Nombre        Apellido    Salario     Sector");

		for(int i=0; i<len;i++)
		{
			if(list[i].salary>=average && list[i].isEmpty==0)
			{
				printEmployee(list[i]);
				cantEmployee++;
			}
		}

		printf("\nTotal, %d empleados", cantEmployee);
    	break;

    default:
    	printf("\nOPCION INVALIDA");
    }
}


int utn_getNumber(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int bufferInt;

	do
	{
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno =0;
			*pNumero = bufferInt;
			break;
		}
		else
		{
			printf("%s",mensajeError);
			reintentos--;
		}
	}while(reintentos>0);

	return retorno;
}


int utn_getFloat(float* pFlotante, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	float bufferFloat;

	do
	{
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
		{
			retorno =0;
			*pFlotante = bufferFloat;
			break;
		}
		else
		{
			printf("%s",mensajeError);
			reintentos--;
		}
	}while(reintentos>0);

	return retorno;
}


int utn_getString(char* pPalabra, char* mensaje, char* mensajeError, int len, int reintentos)
{
	int retorno=-1;
	char bufferString[100];

	do
	{
		printf("%s",mensaje);
		if((getString(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString))<len)
		{
			retorno =0;
			strcpy(pPalabra,bufferString);
			break;
		}
		else
		{
			printf("%s",mensajeError);
			reintentos--;
		}
	}while(reintentos>0);

	return retorno;
}


int getInt(int* pResultado)
{
	int retorno=-1;
	char bufferString[4096];

	if(pResultado != NULL)
	{
		if(myGets(bufferString, sizeof(bufferString)) == 0 && isNumber(bufferString, sizeof(bufferString)) == 0)
		{
			retorno=0;
			*pResultado =atoi(bufferString);
		}
	}
	return retorno;
}


int getFloat(float* pResultado)
{
	int retorno=-1;
	char bufferString[100];

	if(pResultado != NULL)
	{
		if(myGets(bufferString, sizeof(bufferString)) == 0 && isFloatNumber(bufferString, sizeof(bufferString)) == 0)
		{
			retorno=0;
			*pResultado =atof(bufferString);
		}
	}
	return retorno;
}


int getString(char* pResultado)
{
	int retorno=-1;
	char bufferString[100];

	if(pResultado!=NULL)
	{
		if(myGets(bufferString, sizeof(bufferString))==0 && isWord(bufferString, sizeof(bufferString))==0)
		{
			retorno=0;
			strcpy(pResultado,bufferString);
		}
	}

	return retorno;
}


int myGets(char* string, int len)//lo usamos en lugar de fgets o scanf, es una version mas completa. Corregimos error del \n
								 //y no dejamos que se exceda de la longitud max del string pisando asi memoria desconocida
{
	int retorno=-1;
	char bufferString[100];

	if(string != NULL && len > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString [strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) -1]='\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<len)
			{
				strncpy(string,bufferString,len);
				retorno=0;
			}
		}
	}
	return retorno;
}


int isNumber(char* string, int len)
{
	int retorno=-1;//ERROR
	int i=0;

	if(string != NULL && len >0)
	{
		for(i=0; i<len && string[i] != '\0'; i++)
		{
			retorno= 0;//VERDADERO

			if( i==0 && (string[i] == '+' || string[i] == '-'))
			{
				continue;
			}
			if(string[i]> '9' || string[i] < '0')
			{
				retorno=-1;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}


int isFloatNumber(char* string, int len)
{
	int retorno=-1;//ERROR
	int i=0;

	if(string != NULL && len >0)
	{
		for(i=0; i<len && string[i] != '\0'; i++)
		{
			retorno= 0;//VERDADERO

			if( i==0 && (string[i] == '+' || string[i] == '-'))
			{
				continue;
			}
			if(string[i]=='.' )
			{
				continue;
			}
			if(string[i]> '9' || string[i] < '0')
			{
				retorno=-1;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}


int isWord(char* string, int len)
{

	int retorno=-1;//ERROR
	int i=0;

	if(string != NULL && len >0)
	{
		for(i=0; i<len && string[i] != '\0'; i++)
		{
			retorno= 0;//VERDADERO

			if( !((string[i]>= 'a' && string[i] <= 'z') || (string[i]>= 'A' && string[i] <= 'Z')) )
			{
				retorno=-1;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}



