#include<string.h>
#include<stdlib.h>
#include "insert.h"
#include "struct.h"

DATA *insert(DATA* root,char *tmp)
{
	int c;
	DATA *p;
		
	if(root==NULL)
	{
		p=(DATA*)malloc(sizeof(DATA));
		strcpy(p->name,tmp);
		p->count=1;
		p->left=NULL;
		p->right=NULL;
	
		return p;
	}

	c=strcmp(root->name,tmp);

	if(c==0)
	{ 
		(root->count)++;
		return root;// root will be linked back to parent root in last function
	}
	else if(c<0)
	{
		p=insert(root->right,tmp);
		root->right=p;
		return root;
	}

	else //(c>0)
	{
		p=insert(root->left,tmp);
		root->left=p;
		return root;
	}
}


int insert_a(ARRAY* sort,char *tmp,int n)
{
	int i=0,c=0;

	for(i=0;i<n;i++)
	{
		if((c=strcmp(sort[i].name,tmp))==0)
		{
			(sort[i].count)++;
			return n;
		}
	}

	strcpy(sort[n].name,tmp);
	sort[n].count=1;

	return ++n;
}


