#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utnInputs.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    char salir='n';
    int flagLoadedLinkedlist=0;
    int saveBin=0;
    //Employee* empAux;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

    	utn_getNumber(&option, "***MENU*** \n"
    			"\n1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
    			"\n2- Cargar los datos de los empleados desde el archivo data.bin (modo binario)."
    			"\n3- Alta de empleado"
    			"\n4- Modificar datos de empleado"
    			"\n5- Baja de empleado"
    			"\n6- Listar empleados"
    			"\n7- Ordenar empleados"
    			"\n8- Guardar los datos de los empleados en el archivo data.csv (modo texto)."
    			"\n9- Guardar los datos de los empleados en el archivo data.bin (modo binario)."
    			"\n10- Salir"
    			"\n\nIngrese la opcion elegida: ", "\nERROR OPCION INCORRECTA (1-10)\n", 1, 10, 3);

        switch(option)
        {
            case 1:
            	if(flagLoadedLinkedlist == 0)
            	{
					if(controller_loadFromText("data.csv",listaEmpleados) == 0)
					{
						printf("\nCarga exitosa");
						flagLoadedLinkedlist=1;
					}
					else
					{
						printf("\nError al cargar el archivo");
					}
            	}else
            	{
            		printf("\nYa esta cargado el archivo");
            	}
                break;


            case 2:
            	if(flagLoadedLinkedlist == 0)
				{
            		if(saveBin == 1)
            		{
            			if(controller_loadFromBinary("data.bin",listaEmpleados)== 0)
						{
							printf("\nCarga exitosa");
							flagLoadedLinkedlist=1;
						}
						else
						{
							printf("\nError al cargar el archivo");
						}
            		}
            		else
            		{
            			printf("\nSe debe guardar primero el archivo en modo binario");
            		}


				}else
				{
					printf("\nYa esta cargado el archivo");
				}
            	break;

            case 3:
            	if(flagLoadedLinkedlist==1)
            	{
            		if(!controller_addEmployee(listaEmpleados))
            		{
            			printf("\nEmpleado cargado correctamente");
            		}
            	}
            	else
            	{
            		printf("\nSe debe cargar primero el archivo");
            	}

            	break;

            case 4:
            	if(flagLoadedLinkedlist==1)
				{
					if(!controller_editEmployee(listaEmpleados))
					{
						printf("\nEmpleado editado correctamente");
					}
				}
				else
				{
					printf("\nSe debe cargar primero el archivo");
				}

            	break;

            case 5:
            	if(flagLoadedLinkedlist==1)
				{
					if(!controller_removeEmployee(listaEmpleados))
					{
						printf("\nEmpleado eliminado correctamente");
					}
				}
				else
				{
					printf("\nSe debe cargar primero el archivo");
				}
            	break;

            case 6:
            	if(flagLoadedLinkedlist ==0)
            	{
            		printf("\nSe debe cargar primero el archivo");
            	}
            	else
            	{
            		controller_ListEmployee(listaEmpleados);
            	}

            	break;

            case 7:
            	if(flagLoadedLinkedlist ==0)
				{
					printf("\nSe debe cargar primero el archivo");
				}
				else
				{
					if(!controller_sortEmployee(listaEmpleados))
					{
					printf("\nSe ordeno el listado correctamente");
					}
				}
            	break;

            case 8:
            	if(flagLoadedLinkedlist !=0)
            	{
            		if(!controller_saveAsText("data.csv", listaEmpleados))
					{
						printf("\nGuardado del archivo exitoso. Se libero de memoria");
						flagLoadedLinkedlist =0;
						deleteEmployeLinkedlist(listaEmpleados);
						listaEmpleados = ll_newLinkedList();
					}else
					{
						printf("\nERROR al guardar el archivo");
					}
            	}
            	else
            	{
            		printf("\nSe debe cargar primero el archivo");
            	}

            	break;

            case 9:
            	if(flagLoadedLinkedlist !=0)
            	{
					if(!controller_saveAsBinary("data.bin", listaEmpleados))
					{
						printf("\nGuardado del archivo exitoso. Se libero de memoria");
						flagLoadedLinkedlist =0;
						deleteEmployeLinkedlist(listaEmpleados);
						listaEmpleados = ll_newLinkedList();
						saveBin=1;
					}else
					{
						printf("\nERROR al guardar el archivo");
					}
            	}
            	else
				{
					printf("\nSe debe cargar primero el archivo");
				}
            	break;

            case 10:
            	printf("\nConfirma la salida del sistema? (s/n): ");
				__fpurge(stdin);
				scanf("%c", &salir);

				if(salir!='s')
				{
					option =-1;
				}
            	break;

        }
        __fpurge(stdin);
        getchar();
        system("clear");
    }while(option != 10);

    return 0;
}

