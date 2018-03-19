#include <stdio.h>
#include <stdlib.h>
#include "count.h"
#include "struct.h"


int cmp_array(const void *x,const void *y)
{
	return ((ARRAY*)y)->count-((ARRAY*)x)->count;
}


void count(ARRAY* sort,int n)
{
	
	int i=0;
	qsort(sort,n,sizeof(ARRAY),cmp_array);
	

	for(i=0;i<n;i++)
	{
		if((sort[i].count)>0)
		{
			printf("%s\t%d\n",sort[i].name,sort[i].count);
		}
		else
		{
			break;
		}

	}

	return;
}

