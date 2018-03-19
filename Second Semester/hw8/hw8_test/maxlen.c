#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc,char **argv)
{

	char tmp[100],maxW[100];
	int MAX=0,len=0;

	FILE *fp;
	fp=fopen(argv[1],"r");

	while(fgets(tmp,100,fp))
	{
		len=strlen(tmp);
		
		if(len>MAX)
		{
			MAX=len;
			strcpy(maxW,tmp);
		}

	}

	printf("MAX: %d\nWORD: %s\n",MAX,maxW);



	return 0;
}

