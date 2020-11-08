#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva un espacio en memoria
 *
 * @return Employee*, retorna el espacio en memoria reservado
 */
Employee* employee_new();

/** \brief Reserva un espacio en memoria y carga los datos pasados como parametros
 *
 * @param idStr char*
 * @param nombreStr char*
 * @param horasTrabajadasStr char*
 * @param sueldo char*
 * @return Employee*, retorna el espacio en memoria reservado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/** \brief Reserva un espacio en memoria y carga los datos pasados como parametros
 *
 * @param idInt int*
 * @param nombreStr char*
 * @param horasTrabajadasInt int*
 * @param sueldoInt int*
 * @return Employee*, retorna el espacio en memoria reservado
 */
Employee* employee_newParametrosInt(int idInt,char* nombreStr,int horasTrabajadasInt, int sueldoInt);

/** \brief Setea el id en la entidad pasada como paramtro
 *
 * @param this Employee*
 * @param id int
 * @return int -1, ERROR 0 EXITO
 */
int employee_setId(Employee* this,int id);

/** \brief Setea el id en la entidad pasada como paramtro
 *
 * @param this Employee*
 * @param id char
 * @return int -1, ERROR 0 EXITO
 */
int employee_setIdTxt(Employee* this,char* id);

/** \brief Obtiene el id de la entidad pasada como paramtro
 *
 * @param this Employee*
 * @param id int
 * @return int -1, ERROR 0 EXITO
 */
int employee_getId(Employee* this,int* id);

/** \brief Setea el nombre en la entidad pasada como paramtro
 *
 * @param this Employee*
 * @param nombre char*
 * @return int -1, ERROR 0 EXITO
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Obtiene el nombre de la entidad pasada como paramtro
 *
 * @param this Employee*
 * @param nombre char*
 * @return int -1, ERROR 0 EXITO
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Setea las horasTrabajdas en la entidad pasada como paramtro
 *
 * @param this Employee*
 * @param horasTrabajadas int
 * @return int -1, ERROR 0 EXITO
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Obtiene las horasTrabajadas de la entidad pasada como paramtro
 *
 * @param this Employe**
 * @param horasTrabajadas int
 * @return int -1, ERROR 0 EXITO
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief setea el sueldo en la entidad pasada como paramtro
 *
 * @param this Employee*
 * @param sueldo int
 * @return int -1, ERROR 0 EXITO
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el sueldo de la entidad pasada como paramtro
 *
 * @param this Employee*
 * @param sueldo int
 * @return int -1, ERROR 0 EXITO
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Imprime por pantalla la entidad pasada por paramtro
 *
 * @param pEmpleado Employee*
 */
void showEmployee(Employee* pEmpleado);

/** \brief Imprime por pantalla el LinkedList pasado por paramtro
 *
 * @param pArrayLinkedList LinkedList*
 */
void showEmployees(LinkedList* pArrayLinkedList);

/** \brief Busca un empleado por Id, el cual lo recibe como parametro
 *
 * @param pArrayLinkedList LinkedList*
 * @param id int
 * @return int Retorna la posicion del empleado en el array, indice, o -1 ERROR
 */
int findEmployeeById(LinkedList* pArrayLinkedList, int id);

/** \brief Compara el campo id entre dos entidad del tipo Employee*
 *
 * @param emp1 void*
 * @param emp2 void*
 * @return 1 emp1>emp2, -1 emp1<emp2, 0 emp1=emp2
 */
int ordenarId(void* emp1, void* emp2);

/** \brief Compara el campo nombre entre dos entidad del tipo Employee*
 *
 * @param emp1 void*
 * @param emp2 void*
 * @return 1 emp1>emp2, -1 emp1<emp2, 0 emp1=emp2
 */
int ordenarNombre(void* emp1, void* emp2);

/** \brief Compara el campo horasTrabajadas entre dos entidad del tipo Employee*
 *
 * @param emp1 void*
 * @param emp2 void*
 * @return 1 emp1>emp2, -1 emp1<emp2, 0 emp1=emp2
 */
int ordenarHorasTrabajadas(void* emp1, void* emp2);

/** \brief Compara el campo sueldo entre dos entidad del tipo Employee*
 *
 * @param emp1 void*
 * @param emp2 void*
 * @return 1 emp1>emp2, -1 emp1<emp2, 0 emp1=emp2
 */
int ordenarSueldo(void* emp1, void* emp2);


#endif // employee_H_INCLUDED
