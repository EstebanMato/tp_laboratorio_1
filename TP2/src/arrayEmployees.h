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

/**
 *
 * @param list
 * @param len
 * @return
 */
int initEmployees(Employee* list, int len);

/**
 *
 * @param empleado
 */
void printEmployee(Employee empleado);

/**
 *
 * @param list
 * @param len
 */
void printEmployees(Employee* list, int len);

/**
 *
 * @param list
 * @param len
 * @return
 */
int loadedVector(Employee* list, int len);

/**
 *
 * @param list
 * @param id
 * @param indice
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return
 */
int addEmployee(Employee* list, int id, int indice, char name[], char lastName[], float salary, int sector);

/**
 *
 * @param list
 * @param len
 * @param id
 * @return
 */
int highEmployee(Employee* list, int len, int id);

/**
 *
 * @param list
 * @param len
 * @return
 */
int searchFree(Employee* list, int len);

/**
 *
 * @param list
 * @param len
 * @param id
 * @return
 */
int findEmployeeById(Employee* list, int len, int id);

/**
 *
 * @param list
 * @param len
 * @return
 */
int lowEmployee(Employee* list, int len);

/**
 *
 * @param list
 * @param len
 * @param id
 * @return
 */
int removeEmployee(Employee* list, int len, int id);

/**
 *
 * @param list
 * @param len
 */
void modifyEmployee(Employee* list, int len);

/**
 *
 * @param list
 * @param len
 * @param order
 */
void sortEmployees(Employee* list, int len, int order);

/**
 *
 * @param list
 * @param len
 * @param cantidad
 * @return
 */
int hardcodearEmpleados(Employee* list, int len, int cantidad);


