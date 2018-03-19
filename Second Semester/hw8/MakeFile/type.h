#ifndef _TYPE_H_
#define _TYPE_H_


#define CHR_LEN 3 
#define MAX_HV 15000
#define MAX_STR 1000

struct Node
{
	char word[100];
	struct Node *next;
};

typedef struct Node NODE;

int  hash_value(char *tmp);

NODE* insert_node(char *tmp,NODE *header);

int word_check(NODE **ht,char *tmp,int n);

#endif

