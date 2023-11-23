#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dinamica.h>

//long MENORGLOBAL=2147483641;
long MENORGLOBAL=9223372036854775806;
int iteraciones=0;

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


long cambioLong(char primero, char segundo){

	if (primero=='1'&& segundo=='2'){
		return 3;
	}
	else if (primero=='2'&& segundo=='1'){
		return 3;
	}
	else if (primero=='1'&& segundo=='3'){
		return 2;
	}
	else if (primero=='3'&& segundo=='1'){
		return 2;
	}
	else if (primero=='2'&& segundo=='3'){
		return 1;
	}
	else if (primero=='3'&& segundo=='2'){
		return 1;
	}


}

//Funcion que retorna 1 si ya no se puede reducir la colonia
//true = 1
//false = 0
//si largo(palabra)>1 => return 1
//Si todos los digitos de palabra son iguales => return 1
int fin(long num){

	char palabra[20];
	sprintf(palabra, "%ld", num);


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


//NEW
long generarIzquierda(long num){


	//char palabra[40];
	char *palabra= (char*)malloc(sizeof((char*)20));
	sprintf(palabra, "%ld", num);


	int i=0;
	char *nuevoNum= (char*)malloc(sizeof((char*)20));
	//char nuevoNum[40];
	long nuevoValor;
	int n=0;
	char primero;
	char segundo;
	while(i<strlen(palabra)-1){

		primero=palabra[i];
		segundo=palabra[i+1];


		if (primero==segundo){
			nuevoNum[n]=primero;
			nuevoNum[n+1]=segundo;
			n=n+2;
			nuevoNum[n]='\0';
		}
		else{
			nuevoNum[n]=cambio(primero,segundo);
			n=n+1;
			nuevoNum[n]='\0';
		}

		i=i+2;
	}

	
	//se agrega el ultimo
	//Si es Impar
	if ( ( strlen(palabra) )%2 != 0){
		nuevoNum[n]=palabra[strlen(palabra)-1];
		nuevoNum[n+1]='\0';
	}
	

	//Se pasa a long	
	nuevoValor=atol(nuevoNum);

	free(nuevoNum);
	free(palabra);

	return nuevoValor;
}

//NEW
long generarDerecha(long num){

	//char palabra[40];
	char *palabra= (char*)malloc(sizeof((char*)20));
	sprintf(palabra, "%ld", num);


	int i=1;
	char *nuevoNum= (char*)malloc(sizeof((char*)20));
	//char nuevoNum[40];
	long nuevoValor;
	int n=1;
	char primero;
	char segundo;

	nuevoNum[0]=palabra[0];
	nuevoNum[1]='\0';

	//printf("\ni: %d ",i);
	//printf("\nV: %s ",nuevoNum);


	while(i<strlen(palabra)-1){

		primero=palabra[i];
		segundo=palabra[i+1];
		//printf("\nPrimero: [%c]",primero);
		//printf("\nSegundo: [%c]",segundo);

		if (primero==segundo){

			//printf("\nPrimero: [%c]",primero);
			//printf("\nSegundo: [%c]",segundo);
			//printf("\nN [%d]",n );
			nuevoNum[n]=primero;
			nuevoNum[n+1]=segundo;
			n=n+2;
			nuevoNum[n]='\0';

			//printf("\nSinCambio");
			//printf("\ni: %d ",i);
			//printf("\nV: %s \n",nuevoNum);
			i=i+2;
		}
		else{
			nuevoNum[n]=cambio(primero,segundo);
			//printf("\nEntra");
			//printf("\nValor: %s \n",nuevoNum);
			n=n+1;
			nuevoNum[n]='\0';

			//printf("\nCambio");
			//printf("\ni: %d ",i);
			//printf("\nV: %s \n",nuevoNum);
			i=i+2;
		}

		
	}

	//printf("\ni: %d ",i);
	//printf("\nS: %s \n",nuevoNum);
	int largo=strlen(palabra) ;
	//se agrega el ultimo
	//Si es Par
	if ( largo%2 == 0){
		//
		nuevoNum[n]=palabra[largo-1];
		nuevoNum[n+1]='\0';
	}


	//printf("\nF: %s \n",nuevoNum);
	nuevoValor=atol(nuevoNum);

	free(nuevoNum);
	free(palabra);

	return nuevoValor;
}

void updateMenor(long nuevoMenor){
	
	if (nuevoMenor<MENORGLOBAL){
		MENORGLOBAL=nuevoMenor;
	}
}


void ciclo(long num){

	
	if(iteraciones>10000){
		return;
	}
	

	iteraciones=iteraciones+1;

	//printf("\nPasa");
	char *palabra= (char*)malloc(sizeof((char*)30));
	palabra[0]='\0';
	sprintf(palabra, "%ld", num);
	char primero;
	char segundo;

	int largo=strlen(palabra);
	
	if (largo>=2){
		primero=palabra[0];
		segundo=palabra[1];	
	}
	
	free(palabra);


	//Solo 1 digito
	if (largo>2){

		if (fin(num)!=1){

			printf("\nEntra");
			long izquierda=generarIzquierda(num);
			long derecha=generarDerecha(num);
			printf("\nP: %ld",num);
			printf("\nI: %ld",izquierda);
			printf("\nD: %ld",derecha);
			
			if(num!= izquierda && num!=derecha){
				printf("\nVA");
				ciclo(izquierda);
				ciclo(derecha);
				updateMenor(izquierda);
				updateMenor(derecha);
				return;
			}
			else if(num!= izquierda && num==derecha){
				ciclo(izquierda);
				updateMenor(izquierda);
				return;
			}
			else if(num== izquierda && num!=derecha){
				printf("\nVA a DERECHA");
				ciclo(derecha);
				updateMenor(derecha);
				return;
			}
			else if(num== izquierda && num==derecha){
				updateMenor(num);
				return;
			}
			else{
				updateMenor(num);
				return;
			}
		}
		else{
			updateMenor(num);
			return;
		}

	}
	//2 digitos
	else if(largo==2){

		
		//char cChange=cambio(primero,segundo);

		//char *nuevoValor= (char*)malloc(sizeof((char*)10));
		//nuevoValor[0]=cChange;
		if (primero!=segundo){

			printf("\nPrimero: [%c]",primero);
			printf("\nSegundo: [%c]",segundo);
			long numCambio=cambioLong(primero,segundo);
			

			//printf("\nCaracter: %c",cChange);
			printf("\nValor: %ld",numCambio);

			//int largo=numCambio;
			//free(nuevoValor);
		
			updateMenor(numCambio);
			return;	
		}
		else{
			updateMenor(num);
			return;
		}
		
	}
	else if (largo==1){
		updateMenor(num);
		return;
	}
	
	

}






int main(){

	
	MENORGLOBAL=9223372036854775806;

    //printf("\nBienvenido");
    //printf("\nGoloso: \n");


    //Se pide memoria para la palabra que representa a la colonia inicial
    char *palabra= (char*)malloc(sizeof((char*)30));

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

	/*	
	long izquierda=generarIzquierda(numero);
	long derecha=generarDerecha(numero);

	printf("I: %ld \n",izquierda);
	printf("D: %ld \n",derecha);
	*/

	

	//printf("\n===============================================\n");

	//Archivo de salida
	FILE *archivoSalida;
	archivoSalida=fopen("Salida.out","w");



	//Se llama a la funcion pincipal
	ciclo(numero);
   
   	printf("\n*****************************************************");
   	printf("\nMenor: %ld", MENORGLOBAL);


  	printf("\n");


  	//Se libera la memoria
	free(palabra);
	//Se cierran los archivo de entrada y salida
    fclose(archivoEntrada);  
	fclose(archivoSalida);

    }
