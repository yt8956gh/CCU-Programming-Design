#include<string.h>
#include "find.h"
#include "struct.h"

DATA *search_BST(DATA *root,char *tmp)
{
	
	if(root==NULL){return NULL;}
	
	int c=strcmp(root->name,tmp);

	if(c==0)
	{
		return root;
	}

	else if(c>0)
	{
		return search_BST(root->left,tmp);
	}

	else
	{
		return search_BST(root->right,tmp);
	}
}


