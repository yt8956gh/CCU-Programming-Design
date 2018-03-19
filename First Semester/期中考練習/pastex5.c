#include<stdio.h>
#include<string.h>

main(){
		
		char a[1000][32]={'\0'};
		int i=0,k=0;

		while((scanf("%s",&a[i]))!=EOF)	{i++;}
		
		for(k=i;k>=0;k--)
		{printf("%s ",a[k]);}

		
return 0;}
