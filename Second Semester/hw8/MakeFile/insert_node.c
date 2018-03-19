#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "type.h"

NODE* insert_node(char *tmp,NODE *header)
{
	NODE *current;
	current=(NODE*)malloc(sizeof(NODE));
	
	strcpy(current->word,tmp);
	current->next=header;
	//printf("%s\n",current->word);
	return current;
}
