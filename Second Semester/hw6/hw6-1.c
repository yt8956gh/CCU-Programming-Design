#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100+5
 
struct data
{
	char name[MAX];
	int count;

	struct data *left;
	struct data *right;
};

typedef struct data DATA;


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
		(root->count)--;
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


void printBST(DATA *root)
{
	if(root==NULL)
	{return ;}

	printBST(root->left);

	printf("%s\t%d\n",root->name,root->count);

	printBST(root->right);

}


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

int main(void)
{

	char tmp[MAX],*ort=NULL,*ptr=NULL;

	int c=0;
	int len=0;


	DATA *header=NULL,*find=NULL;

	

	while(fgets(tmp,MAX,stdin)!=NULL)
	{

		len=strlen(tmp);

		if((tmp[len-1]=='\n')||(tmp[len-1]=='\r'))//There are '\r' in the input file.
		{
			tmp[len-1]='\0';
		}

		if((tmp[len-2]=='\n')||(tmp[len-2]=='\r'))
		{
			tmp[len-2]='\0';
		}

//--------------------------------find---------------------------
		
		if((c=strcmp(tmp,"inorder"))==0)
		{	
			printf("inorder\n----------\n");
			printBST(header);
			printf("----------\n");
			continue;	
		}

//-------------------Distinguish operator & name--------------------------

		ort=tmp;
		ptr=NULL;

		ptr=strstr(tmp,"\t");

		if(ptr==NULL)
		{
			fprintf(stderr,"Usage: [operator] [tab] [key]\n");
			continue;
		}

		*ptr++='\0';
//-----------------------------------------------------------------------

		if((c=strcmp("insert",ort))==0)
		{
			header=insert(header,ptr);
		}
		else if((c=strcmp("delete",ort))==0)
		{
			delete(header,ptr);
		}
		else if((c=strcmp("find",ort))==0)
		{	
			find=NULL;
	
			find=search_BST(header,ptr);

			if(find==NULL)
			{
				printf("%s unknown\n",ptr);
			}
			else
			{
				printf("find\n----------\n");
				printf("%s\t%d\n----------\n",find->name,find->count);
			}
			
		}
		else
		{
			fprintf(stderr,"ERROR:The format input is illegal !!\n");
			continue;
		}

	}

	return 0;
}
