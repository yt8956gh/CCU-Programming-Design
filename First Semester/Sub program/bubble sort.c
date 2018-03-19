#include<stdio.h>
#include<ctype.h>

main(){
		
	int a[6]={32,21,45,90,12,0};

	int i=0,k=0;
		
	for(i=0;i<5;i++)
	{
		for(k=0;k<(5-i);k++)
		{
				if(a[k]>a[k+1])
				{
				int tmp=0;
				tmp=a[k];
				a[k]=a[k+1];
				a[k+1]=tmp;
				}
		}
	}

		
		
	for(i=0;i<6;i++)	
	{	printf("%d\t",a[i]);	}	
		
return 0;}
