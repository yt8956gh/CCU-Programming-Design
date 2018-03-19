#include<stdio.h>

main(){
	int c=0,i=0,mid=0,k=0;	
		
	while(scanf("%d",&c)!=EOF)
	{
		printf("-- n = %d --\n",c);

		if((c%2)==0)
		{printf("n is not an odd number.\n");continue;}
		
		mid=(c+1)/2;
	
		for(i=0;i<mid;i++)
		{
				
			for(k=0;k<(mid-i);k++)
			{printf(" ");}

			for(k=0;k<(1+2*i);k++)
			{printf("*");}

			printf("\n");
		}


		for(i=1;i<mid;i++)
		{		
				
			for(k=0;k<=i;k++)	
			{printf(" ");}

			for(k=(c-2*i);k>0;k--)
			{printf("*");}

			printf("\n");
		}
	}							
return 0;}
