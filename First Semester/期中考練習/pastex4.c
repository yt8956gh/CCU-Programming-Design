#include<stdio.h>

main(){
		
	int c=0;
	float sum=0;


	while(scanf("%d",&c)&&(c!=0))
	{
		int i=0;		
		
			for(i=c;i>=1;i--)
			{
			float deno=i;
			sum=sum+(1/deno);
			}
	
		printf("%.3f\n",sum);				
	
		sum=0;
	
	
	}
return 0;}
