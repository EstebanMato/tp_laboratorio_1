#include "operations.h"

int getSum(int a, int b){
    int result;
    result=a+b;

    return result;
}

int getSubtraction(int a, int b){
    int result;
    result=a-b;

    return result;
}

float getDivide(int a, int b){
    float result;
    result= (float) a/b ;

    return result;
}

int getMultiplication(int a, int b){
    int result;
    result=a*b;

    return result;
}

long getFactorial(int number){
    long fact;
    if( number == 1){
        fact = 1;
    }else if(number == 0){
    	fact = 1;
    }else if(number == -1){
    	fact = -1;
    }
    else if(number>0){
        fact = number * getFactorial (number-1);
    }
    else if(number<0){
    	fact = number * getFactorial (number+1);
    }
    return fact;
}
