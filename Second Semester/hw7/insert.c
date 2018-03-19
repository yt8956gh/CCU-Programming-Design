#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"type.h"

void insert(char *tmp,TABLE *ht)
{
	NODE *header=NULL,*ptr=NULL,*current=NULL;
	header=ptr=ht->hole;
	int c=0;

	while(ptr!=NULL)
	{
		if((c=strcmp(tmp,ptr->key))==0)		
		{
			ptr->count++;
			return ;
		}

		ptr=ptr->next;
	}

	current=(NODE*)malloc(sizeof(NODE));
	strcpy(current->key,tmp);
	current->count=1;

	current->next=header;
	ht->hole=current;

	
	
	return ;
}
