#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"type.h"


void delete(char *tmp,TABLE *ht)
{
	NODE *ptr=ht->hole;
	int c=0;

	while(ptr!=NULL)
	{
		if((c=strcmp(tmp,ptr->key))==0)		
		{
			ptr->count--;
			return ;
		}
		ptr=ptr->next;
	}

	return;
}

