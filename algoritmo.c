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