#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define in 1
#define out 0
main(){
		
	int a[100]={'\0'},state=0,sq=0,i=0,k=0,c=0;

	while((c=getchar())!=EOF)
	{
		if(isspace(c))		
		{
		a[sq]++;
		sq=0;
		state=out;
		}
		else if( (state==out) && (isalpha(c)) )
		{state=in;}		
				
		if(state==in)
		{sq++;}
	}

	for(i=1;i<100;i++)
	{
		if(a[i]!='\0')
		{
			printf("%d:",i);
		
			for(k=0;k<a[i];k++)
			{printf("*");}

			printf("\n");
		}
			
	}
return 0;}
