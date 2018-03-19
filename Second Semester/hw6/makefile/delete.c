#include<stdio.h>
#include<string.h>
#include "delete.h"
#include "struct.h"



void delete(DATA* root,char *tmp)
{
	int c;
		
	if(root==NULL)
	{
		return;
	}

	c=strcmp(root->name,tmp);

	if(c==0)
	{ 
		if(root->count>0)	
		{
			(root->count)--;
		}
		return;// root will be linked back to parent root in last function
	}
	else if(c<0)
	{
		delete(root->right,tmp);
	}

	else //(c>0)
	{
		delete(root->left,tmp);
	}

}

int delete_a(ARRAY* sort,char *tmp,int n)
{
	int i=0,c=0;

	for(i=0;i<n;i++)
	{
		if((c=strcmp(sort[i].name,tmp))==0)
		{
			if(sort[i].count>0)
			{
				(sort[i].count)--;
			}
			break;
		}
	}

	return n;
}


