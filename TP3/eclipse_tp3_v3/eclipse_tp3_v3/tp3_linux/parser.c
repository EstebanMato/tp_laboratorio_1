#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char buffer[4][128];
	int retorno=0;
	Employee* empAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);

		while(!feof(pFile))
		{
			if( fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]) < 4)
			{
				if(feof(pFile))
				{
					retorno=0;
					break;
				}
				else
				{
					retorno=-1;
					printf("\nERROR. No llego al final del archivo");
					break;
				}
			}

			empAux = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

			if(empAux!=NULL)
			{
				ll_add(pArrayListEmployee, empAux);
			}
			else
			{
				printf("\nError al agregar un empleado");
				retorno =-1;
				break;
			}
		}
	}
	else
	{
		retorno=-1;
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	Employee* empAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			empAux = employee_new();
			if(empAux!=NULL)
			{
				if(fread(empAux,sizeof(Employee),1,pFile)<1)
				{
					if(feof(pFile))
					{
						retorno=0;
						break;
					}
					else
					{
						retorno=-1;
						printf("\nERROR. No llego al final del archivo");
						break;
					}
				}

				ll_add(pArrayListEmployee, empAux);
			}
			else
			{
				printf("\nError al agregar un empleado");
				retorno=-1;
			}
		}
	}
	else
	{
		retorno=-1;
	}
    return retorno;
}
