#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operations.h"

int main()
{
	setbuf(stdout, NULL);
    int a;
    int b;
    int sum;
    int subtract;
    int multiplication;
    int flagA=0;
    int flagB=0;
    int flagCalculateOperations=0;

    long factA;
    long factB;

    float divide;

    char exit='n';

    do{
        system("cls");
        int option;
        printf("------------------\n");
        printf("|CALCULADORA TP 1|\n");
        printf("------------------\n");

        if(flagA == 0){
            printf("1. Ingresar 1er operando (A=x)\n");
        }else{
            printf("1. Primer operando (A=%d)\n",a);
        }

        if(flagB == 0){
            printf("2. Ingresar 2do operando (B=x)\n");
        }else{
            printf("2. Segundo operando (B=%d)\n",b);
        }

        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");

        printf("Ingresar la opcion deseada: ");
        fflush(stdin);
        scanf("%d",&option);

        switch(option){
            case 1:
                printf("\nIngrese el primer numero: ");
                scanf("%d",&a);
                flagA=1;
                break;

            case 2:
                printf("\nIngrese el segundo numero: ");
                scanf("%d",&b);
                flagB=1;
                break;

            case 3:
                if(flagA && flagB){
                    sum=getSum(a,b);
                    subtract=getSubtraction(a,b);

                    if(b!=0){
                        divide=getDivide(a,b);
                    }

                    multiplication=getMultiplication(a,b);
                    factA=getFactorial(a);
                    factB=getFactorial(b);

                    printf("\nSe realizaron los calculos de las operaciones. \n");
                    flagCalculateOperations=1;
                }else{
                    printf("\nDebe ingresar los operando A y B antes de calcular todas las operaciones. \n\n");
                }


                break;

            case 4:
                if(flagCalculateOperations){
                    printf("\na) El resultado de A+B es: %d\n",sum);
                    printf("b) El resultado de A-B es: %d\n",subtract);

                    if(b!=0){
                        printf("c) El resultado de A/B es: %.2f\n",divide);
                    }else{
                        printf("c) No es posible dividir por cero.\n");
                    }

                    printf("d) El resultado de A*B es: %d\n",multiplication);


                    printf("e) El factorial de A es: %ld y El factorial de B es: %ld\n",factA,factB);
                    break;
                }else{
                    printf("\nSe deben calcular las operaciones previamente.\n");
                    break;
                }

            case 5:
                printf("\nDesea salir? s/n: ");
                fflush(stdin);
                exit = getchar();
                exit = tolower(exit);
                break;

            default:
                printf("\nSe ingreso una opcion invalida.\n");
                break;
        }

    system("pause");
    }while(exit != 's');

    return 0;
}
