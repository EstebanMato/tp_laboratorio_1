#ifndef UTNARRAYS_H_
#define UTNARRAYS_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

#endif /* UTNARRAYS_H_ */

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
 * 		   (isEmpty) en TRUE en todas las posiciones del array.
 *
 * @param list Employee* Puntero al array de empleados
 * @param len int Longitud del array
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int initEmployees(Employee* list, int len);


/** \brief Imprime un empleado que lo recibe como parámetro
 *
 * @param empleado Employee
 */
void printEmployee(Employee empleado);


/** \brief Imprime el array de empleados
 *
 * @param list Employee* Puntero al array de empleados
 * @param len int
 */
void printEmployees(Employee* list, int len);


/** \brief Verifica si hay al menos un empleado cargado en el array, isEmpty en 0
 *
 * @param list Employee* Puntero al array de empleados
 * @param len int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int loadedVector(Employee* list, int len);


/** \brief Agrega en un array de empleados existente, los valores recibidos como parámetro en la primer
 * posición libre.
 *
 * @param list Employee* Puntero al array de empleados
 * @param id int
 * @param indice int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int addEmployee(Employee* list, int id, int indice, char name[], char lastName[], float salary, int sector);


/** \brief Pide los datos para la dar alta de un empleado nuevo
 *
 * @param list Emplyee* Puntero al array de empleados
 * @param len int
 * @param id int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int highEmployee(Employee* list, int len, int id);


/** \brief Busca la primera posicion libre del array de empleados, isEmpty en 0
 *
 * @param list Employee* Puntero al array de empleados
 * @param len int
 * @return int Retorna -1 ERROR, indice del array de empleados libre de la primer posicion libre
 */
int searchFree(Employee* list, int len);


/** \brief Busca un empleado por Id, el cual lo recibe como parametro
 *
 * @param list Emlpoyee* Puntero al array de empleados
 * @param len int
 * @param id int
 * @return int Retorna la posicion del empleado en el array, indice, o -1 ERROR
 */
int findEmployeeById(Employee* list, int len, int id);


/** \brief Pide los datos para realizar la baja logica del empleado y llama a la removeEmployee
 *
 * @param list Employee* Puntero al array de empleados
 * @param len int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int lowEmployee(Employee* list, int len);


/** \brief Elimina de manera logica un empleado el cual recibe su Id como parametro
 *
 * @param list Employee* Puntero al array de empleados
 * @param len int
 * @param id int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int removeEmployee(Employee* list, int len, int id);


/** \brief Realiza la modificacion de datos de un empledo pidiendo su Id y el campo a modificar
 *
 * @param list Employee* Puntero al array de empleados
 * @param len int
 */
void modifyEmployee(Employee* list, int len);


/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente
 *
 * @param list Employee* Puntero al array de empleados
 * @param len int
 * @param order int 1 de manera ascendente, 2 descendente
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int sortEmployees(Employee* list, int len, int order);


/** \brief Hardcodea una determinada cantidad de empleados para hacer pruebas del programa
 *
 * @param list Employee* Puntero al array de empleados 1-10
 * @param len int
 * @param cantidad int Cantidad de empleados a hardcodear
 * @return int Retorna la cantidad de empleados cargados
 */
int hardcodearEmpleados(Employee* list, int len, int cantidad);


