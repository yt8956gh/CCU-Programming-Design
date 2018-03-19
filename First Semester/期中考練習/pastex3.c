#include<stdio.h>
#define yes 1
#define no 0
main()
{
int c=0,state=0;

while( scanf("%d",&c)&&(c!=0) )
{
	int i=0,k=0;

	for(i=2;i<=c;i++)
	{
		if((c%i)==0)//代表I為因數
		{	
			state=yes;
			for(k=2;k<i;k++)//判斷是否為質因數
			{
				if((i%k)==0)
				{state=no;}
			}
				
		if(state==yes){printf("%d ",i);}
		}
	}
	printf("\n");
}
return 0;		
}
