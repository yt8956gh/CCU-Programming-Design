#include<stdio.h>
#include<string.h>

main(){
		
	int a[26],A[26],c,i,j,k,sq;

	c=i=j=k=sq=0;

	for(i=0;i<26;i++){a[i]=A[i]=0;}

	while((c=getchar())!=EOF)
	{
	if	   (c>='a'&&c<='z'){sq=c-'a';	a[sq]++;}
	else if(c>='A'&&c<='Z'){sq=c-'A';	A[sq]++;}
	}

	for(i=0;i<26;i++)
	{
		for(k=0;k<a[i];k++)
		{printf("%c",i+97);}		
	}
	
	for(i=0;i<26;i++)
	{
		for(k=0;k<A[i];k++)
		{printf("%c",i+65);}		
	}
	printf("\n");		
	return 0;}
