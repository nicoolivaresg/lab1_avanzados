#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void imprimirCombinacionEnArchivo(FILE * file, int * a){
	fprintf(file,"[%d-%d-%d-%d-%d-%d-%d-%d]\n", a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
}

//Procedimiento encargado de obtener todas las combinaciónes
//de números entre 1 a 20, sin repeticiones
//Entrada: un archivo para imprimir las combinaciones
//		   un numero entero para el limite 
//Salida: entero para comprobación de estado
int bingo_combinacion_2(FILE * file,int n){
	int a,b,c,d,e,f,g,h,z,i;
	if(n>=8)
	{	
		for(z=n;z<=20;z++)
		{	
			fprintf(file,"Conjunto:\n[");
			for(i=1;i<=z;i++){
				if(i==z){
					fprintf(file,"%d]", i);
				}else{
					fprintf(file,"%d-", i);
				}
			}
			fprintf(file, "\nSubconjuntos:\n");
			for(a=1;a<=z-7;a++)
			{
				for(b=a+1;b<=z-6;b++)
				{
					for(c=b+1;c<=z-5;c++)
					{
						for(d=c+1;d<=z-4;d++)
						{
							for(e=d+1;e<=z-3;e++)
							{
								for(f=e+1;f<=z-2;f++)
								{
									for(g=f+1;g<=z-1;g++)
									{
										for(h=g+1;h<=z;h++)
										{		
											fprintf(file,"[%d-%d-%d-%d-%d-%d-%d-%d]\n", a,b,c,d,e,f,g,h);
										}
									}	
								}	
							}	
						}	
					}		
				}	
			}	
		}
		return 0;
	}else{
		return -1;
	}
}


int bingo_combinacion_1(FILE * file,int n){
	int limite,i;
	if(n>=8)
	{
		int * arr = (int*)malloc(8*sizeof(int));
		for (i = 0; i < 8; i++)
		{
			arr[i]=i+1;
		}

		fprintf(file,"Conjunto:\n[");
		for(i=1;i<=n;i++){
			if(i==n){
				fprintf(file,"%d]", i);
			}else{
				fprintf(file,"%d-", i);
			}
		}
		fprintf(file, "\nSubconjuntos:\n");
		imprimirCombinacionEnArchivo(file,arr);
		for(limite = n;limite>=n-7; limite--)
		{
			i=7;
			while(i>=0)
			{
				while(arr[i]<limite){
					arr[i]++;
					imprimirCombinacionEnArchivo(file,arr);
					if(arr[i]==limite){
						limite--;
						i--;
					}
				}
				i--;
			}	
		}
		return 0;
	}else{
		return -1;
	}
}


int main(int argc, char* argv[]) {
  	int n;
	int* conjunto;
	int i;
	FILE * fileIN,*fileOUT, *fileOUT2;
	switch (argc){
		case 0:
			printf("%s\n", "ARGUMENTOS INSUFICIENTES");
			exit(EXIT_FAILURE);
			break;
		case 1:
			printf("%s\n", "ARGUMENTOS INSUFICIENTES");
			exit(EXIT_FAILURE);
			break;
		case 2:
			//printf("%s\n", argv[1]);
			fileIN = fopen(argv[1],"r");
			fileOUT = fopen("SALIDA.txt","w");
			fileOUT2 = fopen("SALIDA2.txt","w");
			if(fileIN){
				if(fscanf(fileIN,"%d\n",&n)==EOF){
					printf("%s\n", "ERROR DE LECTURA DE ARCHIVO");
					exit(EXIT_FAILURE);
				}else
				{
					conjunto = (int*)malloc(n*sizeof(int));	
				}
				if(bingo_combinacion_1(fileOUT,n)==0 && bingo_combinacion_2(fileOUT2,n)==0){
					printf("%s\n", "COMBINACIONES EXITOSAS ALGORITMO 2, revisar archivo SALIDA2.txt");
					printf("%s\n", "COMBINACIONES EXITOSAS ALGORITMO 1, revisar archivo SALIDA.txt");
					exit(EXIT_SUCCESS);
				}else{
					printf("%s\n", "ERROR EN OBTENCION DE COMBINACIONES");
					exit(EXIT_FAILURE);	
				}
				fclose(fileIN);	
				fclose(fileOUT);
				exit(EXIT_SUCCESS);
				
			}else{
				printf("%s\n", "ERROR DE LECTURA DE ARCHIVO");
				exit(EXIT_FAILURE);
			}
			
		default:
			printf("%s\n", "DEMACIADOS ARGUMENTOS");
			exit(EXIT_FAILURE);
			break;
	}
}
