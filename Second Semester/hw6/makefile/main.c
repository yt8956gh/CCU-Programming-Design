#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"struct.h"
#include"count.h"
#include"delete.h"
#include"insert.h"
#include"inorder.h"
#include"find.h"


int main(void)
{

	char tmp[MAX],*ort=NULL,*ptr=NULL;

	int c=0,n=0;
	int len=0;


	DATA *header=NULL,*find=NULL;
	ARRAY sort[10000];

	

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

		else if((c=strcmp(tmp,"count"))==0)
		{	
			printf("count\n----------\n");
			count(sort,n);
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


