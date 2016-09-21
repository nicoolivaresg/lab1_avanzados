#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void imprimirCombinacionEnArchivo(FILE * file, int * a){
	fprintf(file,"%d-%d-%d-%d-%d-%d-%d-%d\n", a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
}

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
	int a,b,c,d,e,f,g,h;
	if(n>=8)
	{
		for(a=1;a<=n-7;a++)
		{
			for(b=a+1;b<=n-6;b++)
			{
				for(c=b+1;c<=n-5;c++)
				{
					for(d=c+1;d<=n-4;d++)
					{
						for(e=d+1;e<=n-3;e++)
						{
							for(f=e+1;f<=n-2;f++)
							{
								for(g=f+1;g<=n-1;g++)
								{
									for(h=g+1;h<=n;h++)
									{		
										fprintf(file,"%d-%d-%d-%d-%d-%d-%d-%d\n", a,b,c,d,e,f,g,h);
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

int bingo_combinacion(FILE * file,int n){
	int z,i,j;
	int * a = (int*)malloc(n*sizeof(int));
	if(n>=8)
	{
		for(i=0;i<8;i++){
			a[i] = i+1;
		}

		
		imprimirCombinacionEnArchivo(file,a);
					
		return 0;
	}else{
		return -1;
	}
}

int main(int argc, char* argv[]) {
  	int n;
	int* conjunto;
	int i;
	FILE * fileIN,*fileOUT;
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
			if(fileIN){
				if(fscanf(fileIN,"%d\n",&n)==EOF){
					printf("%s\n", "ERROR DE LECTURA DE ARCHIVO");
					exit(EXIT_FAILURE);
				}else
				{
					conjunto = (int*)malloc(n*sizeof(int));	
				}

				bingo_combinacion_2(fileOUT,n);
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
