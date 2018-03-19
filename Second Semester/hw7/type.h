#ifndef _TYPE_H_
#define _TYPE_H_

#define MAXWORD 100

struct hash_node
{
	char key[MAXWORD];
	int count;
	struct hash_node *next;
};

typedef struct hash_node NODE;



struct hash_table
{
	NODE *hole;
};

typedef struct hash_table TABLE;



int hash_value(char *tmp);

void insert(char *tmp,TABLE *ht);

void delete(char *tmp,TABLE *ht);

NODE* find(char *tmp,TABLE *ht);

#endif
