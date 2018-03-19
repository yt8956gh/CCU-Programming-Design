#ifndef _STRUCT_
#define _STRUCT_

#define MAX 100+5

struct data
{
	char name[MAX];
	int count;

	struct data *left;
	struct data *right;
};


struct array
{
	char name[MAX];
	int count;
};

typedef struct data DATA;

typedef struct array ARRAY;

#endif
