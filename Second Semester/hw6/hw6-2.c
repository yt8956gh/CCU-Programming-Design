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


struct array
{
	char name[MAX];
	int count;
};

typedef struct data DATA;

typedef struct array ARRAY;



DATA *insert(DATA* root,char *tmp);
//BST
void delete(DATA* root,char *tmp);
//BST


int insert_a(ARRAY* sort,char *tmp,int n);
//the insert of array version

int delete_a(ARRAY* sort,char *tmp,int n);
//the delete of array version



void printBST(DATA *root);
//print BST with inorder



void count(ARRAY* sort,int n);
//print the array copyed from BST with count order

int cmp_array(const void *x,const void *y);
//be used in qsort of count



DATA *search_BST(DATA *root,char *tmp);
//find function in SPEC


int main(void)
{

	char tmp[MAX],*ort=NULL,*ptr=NULL;

	int c=0,n=0;
	int len=0;


	DATA *header=NULL,*find=NULL;
	ARRAY sort[10000];//declare for the purpose of "print data in count order"

	

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

//--------------------------------find-------------------------------
		
		if((c=strcmp(tmp,"inorder"))==0)
		{	
			printf("inorder\n----------\n");
			printBST(header);
			printf("----------\n");
			continue;	
		}
//-------------------------------count-------------------------------
		else if((c=strcmp(tmp,"count"))==0)
		{	
			printf("count\n----------\n");
			count(sort,n);
			printf("----------\n");
			continue;	
		}


//-------------------Distinguish operator & name---------------------

		ort=tmp;
		ptr=NULL;

		ptr=strstr(tmp,"\t");

		if(ptr==NULL)
		{
			fprintf(stderr,"Usage: [operator] [tab] [key]\n");
			continue;
		}

		*ptr++='\0';
//-----------insert & delete (BST and ARRAY version) & find----------

		if((c=strcmp("insert",ort))==0)
		{
			header=insert(header,ptr);
			n=insert_a(sort,ptr,n);
		}
		else if((c=strcmp("delete",ort))==0)
		{
			delete(header,ptr);
			delete_a(sort,ptr,n);
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

	if(c==0)//found the node corresponding to "tmp"
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

	// The situation where "no node exist in array" will break "For Loop" in n==0  

	for(i=0;i<n;i++)
	{
		if((c=strcmp(sort[i].name,tmp))==0)
		{
			(sort[i].count)++;
			return n;
		}
	}

	// AND continue running subprogram for build "new node" in array

	strcpy(sort[n].name,tmp);
	sort[n].count=1;

	return ++n;
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
		return;
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

	if((root->count)>0)
	{
		printf("%s\t%d\n",root->name,root->count);
	}

	printBST(root->right);

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

int cmp_array(const void *x,const void *y)
{
	return ((ARRAY*)y)->count-((ARRAY*)x)->count;
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
