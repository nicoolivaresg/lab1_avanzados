#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void fuerzabruta(int n) {
	int a,b,c,d,e,f,g,h;
  	for(a=1;a<=31;a++)
	{
 	 	for(b=a+1;b<=32;b++)
  		{ 
    		for(c=b+1;c<=33;c++)
    		{
       			for(d=c+1;d<=34;d++)
       			{
         			for(e=d+1;e<=35;e++)
         			{
           				for(f=e+1;f<=36;f++)
            			{
            				for(g=f+1;g<=37;g++)
            				{
	            				for(h=g+1;h<=38;h++)
	            				{
             						printf("%d-%d-%d-%d-%d-%d-%d-%d\n",a,b,c,d,f,e,g,h);
	           					}	
           					}
           				}
     				}
       			}
     		}  
   		} 
	}
}

int bingo_combinacion(int n){
	int z,a;
	if(n>=8)
	{
		for(a=1;a<=13;a++)
		{
			for(b=a+1;b<=14;b++)
			{
				for(c=b+1;c<=15;c++)
				{
					for(d=c+1;d<=16;d++)
					{
						for(e=d+1;e<=17;e++)
						{
							for(f=e+1;f<=18;f++)
							{
								for(g=f+1;g<=19;g++)
								{
									for(h=g+1;h<=20;h++)
									{		
										printf("%d-%d-%d-%d-%d-%d-%d-%d-\n", a,b,c,d,e,f,g,h);
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

				fuerzabruta(n);
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