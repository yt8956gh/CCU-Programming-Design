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
		if((c%i)==0)//�N��I���]��
		{	
			state=yes;
			for(k=2;k<i;k++)//�P�_�O�_����]��
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
