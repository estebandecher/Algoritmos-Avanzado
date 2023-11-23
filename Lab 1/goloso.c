#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <goloso.h>



//Funcion que lee el archivo de entrada y guarda el contenido en palabra
void leerArchivo(char* palabra,FILE *archivo){

	fscanf(archivo,"%s",palabra);
	//printf("\nPalabra: %s",palabra);
}


//Funcion que retorna el caracter corespondiente a juntar el caracter primero con caracter segundo
//primero+segundo->salida 
char cambio(char primero, char segundo){

	if (primero=='1'&& segundo=='2'){
		return '3';
	}
	else if (primero=='2'&& segundo=='1'){
		return '3';
	}
	else if (primero=='1'&& segundo=='3'){
		return '2';
	}
	else if (primero=='3'&& segundo=='1'){
		return '2';
	}
	else if (primero=='2'&& segundo=='3'){
		return '1';
	}
	else if (primero=='3'&& segundo=='2'){
		return '1';
	}


}


//Funcion que retorna 1 si ya no se puede reducir la colonia
//true = 1
//false = 0
//si largo(palabra)>1 => return 1
//Si todos los digitos de palabra son iguales => return 1
int fin(char* palabra){

	//si es de tamaño 1
	if (strlen(palabra)<=1){
		return 1;
	}

	//int diferentes;
	char letra=palabra[0];
	int i=0;
	while(i<strlen(palabra)){
		if (letra!=palabra[i]){
			return 0;
		}
		i=i+1;
	}
	return 1;


}




//Goloso
//Funcion que retorna el numero menor generado a partir de palabra
//Se ejecuta el while largo(palabra)-1 vez (para cada par de digitos consecutivos)
long goloso(char* palabra){

	int actual=0;

	
	char primero;
	char segundo;



	//int menor=atoi(palabra);
	//int nuevoValor;
	//update
	long menor=atol(palabra);
	long nuevoValor;

	//orden de nueva palabra
	int n=0;
	while(actual<strlen(palabra)-1){
		//printf("---------------------------");
		int i=actual;
		char *nuevaPalabra= (char*)malloc(sizeof((char*)100));


		

		//analisis actual
		//char nuevaPalabra;
		primero=palabra[i];
		segundo=palabra[i+1];
		if (primero!=segundo){

			//pegando iniciales
			int p=0;
			while(p<actual){
				//printf("\nEntra");
				nuevaPalabra[p]=palabra[p];
				//i=i+1;
				p=p+1;
			}

			//Cambio	
			char nuevaLetra=cambio(primero,segundo);
			nuevaPalabra[p]=nuevaLetra;
			p=p+1;
			i=i+2;

			//pegandoFinales
			while(p<strlen(palabra)){
				nuevaPalabra[p]=palabra[i];
				i=i+1;
				p=p+1;

			}

			//comparar y ver el menor
			//printf("\n%s",nuevaPalabra);	
			//nuevoValor=atoi(nuevaPalabra);
			//update
			nuevoValor=atol(nuevaPalabra);
			if(nuevoValor<menor){
				menor=nuevoValor;
			}


		}
		

		actual=actual+1;
		//printf("\n%s",nuevaPalabra);
		free(nuevaPalabra);
		//printf("\nMenor: %d", menor);
		//printf("\n---------------------------\n");
	}

	return menor;

}


//Funcion que llama la funcion goloso para agrupar, hasta que no se pueda reducir mas (fin(palabra)!=1)
//En cada ciclo se imprime la palabra actual, que representa al estado de la colonia
void ciclo(char *palabra,FILE *archivoSalida){


	//printf("\nPasa");


	
	char *nuevaPalabra= (char*)malloc(sizeof((char*)100));
	nuevaPalabra=palabra;
	//printf("\nOriginal: %s",palabra);
	fprintf(archivoSalida,"%s\n", nuevaPalabra);
	while(fin(nuevaPalabra)!=1){

		//int nuevoValor=goloso(nuevaPalabra);
		long nuevoValor=goloso(nuevaPalabra);
		nuevaPalabra[0]='\0';
		sprintf(nuevaPalabra, "%ld", nuevoValor);
		//printf("\nNuevaPalabra: %s",nuevaPalabra);
		fprintf(archivoSalida,"%s\n", nuevaPalabra);
		
	}

}






int main(){

	


    //printf("\nBienvenido");
    //printf("\nGoloso: \n");


    //Se pide memoria para la palabra que representa a la colonia inicial
    char *palabra= (char*)malloc(sizeof((char*)20));

    FILE *archivoEntrada;
	archivoEntrada=fopen("entrada.in","r");


	palabra[0]='\0';

	//Se lee el archivo
	leerArchivo(palabra,archivoEntrada);
	//printf("\nPalabra: %s",palabra);



	//apoyo
	int largo=strlen(palabra);
	//printf("\nLargo: %d", largo);

	//int numero=atoi(palabra);
	long numero=atol(palabra);
	//printf("\nNumero: %ld",numero );



	//printf("\n===============================================\n");
	//printf("\nSiguiente: %d\n",correr(palabra));


	 
	char *nuevaPalabra= (char*)malloc(sizeof((char*)100));



	//nuevaPalabra=palabra;
	//printf("Nueva: %s\n",nuevaPalabra);
	//int nuevoValor;
	//sprintf(nuevaPalabra, "%d",correr(palabra) );
	//printf("\nSiguiente: %d\n",correr(nuevaPalabra));
	

	//printf("\n===============================================\n");

	//Archivo de salida
	FILE *archivoSalida;
	archivoSalida=fopen("Salida.out","w");

	//Se llama a la funcion pincipal
	ciclo(palabra,archivoSalida);
   


  	printf("\n");


  	//Se libera la memoria
	free(palabra);
	//Se cierran los archivo de entrada y salida
    fclose(archivoEntrada);  
	fclose(archivoSalida);

    }
