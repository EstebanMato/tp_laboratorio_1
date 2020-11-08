#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utnInputs.h"
#include "Employee.h"

Employee* employee_new()
{
	Employee* this = (Employee*) malloc(sizeof(Employee));
	if(this != NULL)
	{
		this->horasTrabajadas=0;
		this->id=0;
		strcpy(this->nombre, "\0");
		this->sueldo=0;
	}
	return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		this = employee_new();
		if(this != NULL)
		{
			if((employee_setId(this, atoi(idStr)) != 0) || (employee_setNombre(this, nombreStr) !=0) || (employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) !=0) || (employee_setSueldo(this, atoi(sueldoStr)) !=0))
			{
				free(this);
				this=NULL;
			}
		}
	}
	return this;
}

Employee* employee_newParametrosInt(int idInt,char* nombreStr,int horasTrabajadasInt, int sueldoInt)
{
	Employee* this;

	if(idInt >0 && nombreStr != NULL && horasTrabajadasInt > 0 && sueldoInt >0)
	{
		this = employee_new();
		if(this != NULL)
		{
			if((employee_setId(this, idInt) != 0) || (employee_setNombre(this, nombreStr) !=0) || (employee_setHorasTrabajadas(this, horasTrabajadasInt) !=0) || (employee_setSueldo(this, sueldoInt) !=0))
			{
				free(this);
				this=NULL;
			}
		}
	}
	return this;
}

int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this!= NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int employee_setIdTxt(Employee* this,char* id)
{
	int retorno=-1;
	if(this!= NULL && id!= NULL)
	{
		if(isNumber(id, sizeof(id)) == 0)
		{
			this->id=atoi(id);
			retorno=0;
		}
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno=-1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno=0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!= NULL && nombre != NULL)
	{
		if(isWord(nombre, sizeof(nombre)) == 0)
		{
			strncpy(this->nombre,nombre, sizeof(this->nombre));
		}
		retorno=0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno =0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas  = this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;
	if(this!=NULL && sueldo>=0)
	{
		this->sueldo=sueldo;
		retorno=0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=-1;
		if(this != NULL && sueldo != NULL)
		{
			*sueldo= this->sueldo;
			retorno=0;
		}
		return retorno;
}

void showEmployee(Employee* pEmpleado)
{
	int idAux;
	char nombreAux[128];
	int horasTrabajadasAux;
	int sueldoAux;

	employee_getId(pEmpleado, &idAux);
	employee_getNombre(pEmpleado, nombreAux);
	employee_getHorasTrabajadas(pEmpleado, &horasTrabajadasAux);
	employee_getSueldo(pEmpleado, &sueldoAux);

	if(pEmpleado != NULL)
	{
		printf("\n%-5d %-15s %-6d %-5d",idAux, nombreAux, horasTrabajadasAux, sueldoAux);
	}

}

void showEmployees(LinkedList* pArrayLinkedList)
{
	int lenArray=ll_len(pArrayLinkedList);

	printf("\n***Listado de empelados***");
	printf("\nID    NOMBRE          HORAS  SUELDO");

	for(int i=0; i<lenArray; i++)
	{
		showEmployee((Employee*) ll_get(pArrayLinkedList, i));
	}
}

int findEmployeeById(LinkedList* pArrayLinkedList, int id)
{
	int indice=-1;
	int idAux=-1;
	Employee* this;

	for(int i=0;i<ll_len(pArrayLinkedList);i++)
	{
		this = (Employee*)ll_get(pArrayLinkedList, i);
		employee_getId(this, &idAux);
		if(idAux==id)
		{
			indice=i;
			break;
		}
	}
	return indice;
}

int ordenarId(void* emp1, void* emp2)
{
	int retorno=0;
	Employee* empAux1;
	Employee* empAux2;

	if(emp1!=NULL && emp2!=NULL)
	{
		empAux1=(Employee*)emp1;
		empAux2=(Employee*)emp2;

		if(empAux1->id > empAux2->id)
			retorno=1;
		else if(empAux1->id < empAux2->id)
			retorno=-1;
	}
	return retorno;
}

int ordenarNombre(void* emp1, void* emp2)
{
	int retorno=0;
	Employee* empAux1;
	Employee* empAux2;
	if(emp1!=NULL && emp2!=NULL)
	{
		empAux1=(Employee*)emp1;
		empAux2=(Employee*)emp2;

		if(strcmp(empAux1->nombre,empAux2->nombre)>0)
			retorno=1;
		else if(strcmp(empAux1->nombre,empAux2->nombre)<0)
			retorno=-1;
	}
	return retorno;
}

int ordenarHorasTrabajadas(void* emp1, void* emp2)
{
	int retorno=0;
	Employee* empAux1;
	Employee* empAux2;

	if(emp1!=NULL && emp2!=NULL)
	{
		empAux1=(Employee*)emp1;
		empAux2=(Employee*)emp2;

		if(empAux1->horasTrabajadas > empAux2->horasTrabajadas)
			retorno=1;
		else if(empAux1->horasTrabajadas < empAux2->horasTrabajadas)
			retorno=-1;
	}
	return retorno;
}

int ordenarSueldo(void* emp1, void* emp2)
{
	int retorno=0;
	Employee* empAux1;
	Employee* empAux2;

	if(emp1!=NULL && emp2!=NULL)
	{
		empAux1=(Employee*)emp1;
		empAux2=(Employee*)emp2;

		if(empAux1->sueldo > empAux2->sueldo)
			retorno=1;
		else if(empAux1->sueldo < empAux2->sueldo)
			retorno=-1;
	}
	return retorno;
}
