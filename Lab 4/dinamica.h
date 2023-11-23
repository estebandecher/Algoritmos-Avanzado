#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Funcion que lee el archivo de entrada y guarda el contenido en palabra
void leerArchivo(char* palabra,FILE *archivo);


//Funcion que retorna el caracter corespondiente a juntar el caracter primero con caracter segundo
//primero+segundo->salida 
char cambio(char primero, char segundo);


//Funcion que retorna 1 si ya no se puede reducir la colonia
//true = 1
//false = 0
//si largo(palabra)>1 => return 1
//Si todos los digitos de palabra son iguales => return 1
int fin(long num);




//Goloso
//Funcion que retorna el numero menor generado a partir de palabra
//Se ejecuta el while largo(palabra)-1 vez (para cada par de digitos consecutivos)
long goloso(char* palabra);


//Funcion que llama la funcion goloso para agrupar, hasta que no se pueda reducir mas (fin(palabra)!=1)
//En cada ciclo se imprime la palabra actual, que representa al estado de la colonia
void ciclo(long num);





