/** \brief Carga en modo texto los datos del archivo data.csv el cual recibimos la ruta de ubicacion como parametro
 *
 * @param pFile FILE*
 * @param pArrayListEmployee LinkedList*
 * @return int -1, ERROR 0 EXITO
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Carga en modo binario los datos del archivo data.bin el cual recibimos la ruta de ubicacion como parametro
 *
 * @param pFile FILE*
 * @param pArrayListEmployee LinkedList*
 * @return int -1, ERROR 0 EXITO
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
