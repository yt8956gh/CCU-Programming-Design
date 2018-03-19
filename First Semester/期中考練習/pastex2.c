#include<stdio.h>
#include<string.h>

main()
{
int c,i,sum;

c=i=sum=0;

while(scanf("%d",&c)&&(c!=0))
{	
	for(i=1;i<c;i++)
	{	
			
		if((c%i)==0)
				
		{
		sum=sum+i;
		}
	}
	
	if(c==sum)
	{printf("Yes\n");}
	else{printf("No\n");}

	sum=0;
}		
return 0;}
