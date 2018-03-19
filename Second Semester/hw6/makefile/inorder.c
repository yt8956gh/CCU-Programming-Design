#include<stdio.h>

#include"inorder.h"
#include "struct.h"

void printBST(DATA *root)
{
	if(root==NULL)
	{return ;}

	printBST(root->left);


	if((root->count)>0)
	{
		printf("%s\t%d\n",root->name,root->count);
	}

	printBST(root->right);

}

