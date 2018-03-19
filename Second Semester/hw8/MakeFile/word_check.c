#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "type.h"

int word_check(NODE **ht,char *tmp,int n)
{
	int hv=0,c=0;
	char *process=NULL;
	NODE *ptr=NULL;

	process=(char *)malloc(sizeof(char)*(n+1));

	if(process==NULL)
	{
		fprintf(stderr,"ERROR:Cannot allocate memory !\n");
		exit(1);
	}

	memset(process,'\0',sizeof(char)*(n+1));
	strncpy(process,tmp,n);
	hv=hash_value(process);
	ptr=ht[hv];

	while(ptr!=NULL)
	{
		if((c=strcmp(ptr->word,process))==0)
		{
			printf("%s\n",ptr->word);
			free(process);
			return 1; 
		}
		
		ptr=ptr->next;
	}

	//printf("N:%d\tSTR:%-50s\tHV:%d\n",n,process,hv);
	free(process);
	return 0;
}


