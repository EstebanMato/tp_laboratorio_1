#ifndef UTNINPUTS_H_
#define UTNINPUTS_H_



#endif /* UTNINPUTS_H_ */

/**
 *
 * @return
 */
int menu();

/**
 *
 * @param list
 * @param len
 */
void menuInformes(Employee* list, int len);

/**
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return
 */
int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 *
 * @param pFlotante
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param intentos
 * @return
 */
int utn_getFloat(float* pFlotante, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

/**
 *
 * @param pPalabra
 * @param mensaje
 * @param mensajeError
 * @param len
 * @param reintentos
 * @return
 */
int utn_getString(char* pPalabra, char* mensaje, char* mensajeError, int len, int reintentos);

/**
 *
 * @param pResultado
 * @return
 */
int getInt(int* pResultado);

/**
 *
 * @param pResultado
 * @return
 */
int getFloat(float* pResultado);

/**
 *
 * @param pResultado
 * @return
 */
int getString(char* pResultado);

/**
 *
 * @param string
 * @param len
 * @return
 */
int myGets(char* string, int len);

/**
 *
 * @param string
 * @param len
 * @return
 */
int isNumber(char* string, int len);

/**
 *
 * @param string
 * @param len
 * @return
 */
int isFloatNumber(char* string, int len);

/**
 *
 * @param string
 * @param len
 * @return
 */
int isWord(char* string, int len);



