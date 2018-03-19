#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"type.h"

int hash_value(char *tmp)
{
	int hv=0,i=0;
	int len=strlen(tmp);

	for(i=0;i<len;i++)
	{
		hv=hv+tmp[i];
	}

	return hv; 
}
