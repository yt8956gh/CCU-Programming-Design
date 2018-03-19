#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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


int hash_value(char *tmp)
{
	int hv=0,i=0;
	int len=strlen(tmp);

	for(i=0;i<len;i++)
	{
		hv=hv+tmp[i];
	}

	return hv; 
}


void insert(char *tmp,TABLE *ht)
{
	NODE *header=NULL,*ptr=NULL,*current=NULL;
	header=ptr=ht->hole;
	int c=0;

	while(ptr!=NULL)
	{
		if((c=strcmp(tmp,ptr->key))==0)		
		{
			ptr->count++;
			return ;
		}

		ptr=ptr->next;
	}

	current=(NODE*)malloc(sizeof(NODE));
	strcpy(current->key,tmp);
	current->count=1;

	current->next=header;
	ht->hole=current;

	
	
	return ;
}

void delete(char *tmp,TABLE *ht)
{
	NODE *ptr=ht->hole;
	int c=0;

	while(ptr!=NULL)
	{
		if((c=strcmp(tmp,ptr->key))==0)		
		{
			ptr->count--;
			return ;
		}
		ptr=ptr->next;
	}

	return;
}

NODE* find(char *tmp,TABLE *ht)
{
	NODE *ptr=ht->hole;
	int c=0;

	while(ptr!=NULL)
	{

		if((c=strcmp(tmp,ptr->key))==0)		
		{
			break;
		}
		ptr=ptr->next;
	}

	return ptr;
}






int main(void)
{
	char tmp[MAXWORD];
	char *ptr,*qtr,*word;
	int hv=0,c=0,len=0;
	TABLE ht[100000];
	NODE *result=NULL;	
	
	while(fgets(tmp,MAXWORD,stdin))
	{
		len=strlen(tmp);
		tmp[len-1]='\0';

	
		if((qtr=strchr(tmp,'\t'))==NULL)
		{
			fprintf(stderr,"ERROR: The command is illegal!!\n");
			continue;
		}

		ptr=strtok(tmp,"\t");	
		word=strtok(NULL,"\t");

		hv=hash_value(word);

		//printf("HV: %d\tword: %s\n",hv,word);
		
		if((c=strcmp("insert",ptr))==0)
		{
			insert(word,&ht[hv]);
		}
		else if((c=strcmp("delete",ptr))==0)
		{
			delete(word,&ht[hv]);
		}
		else if((c=strcmp("find",ptr))==0)
		{
			result=find(word,&ht[hv]);
			printf("find\t%s\n----------\n",word);

			if(result!=NULL)
			{
				printf("%s\t%d\n----------\n",result->key,result->count);
			}
			else
			{
				printf("Not found!\n----------\n");
			}
			
		}
		else
		{
			fprintf(stderr,"ERROR: The command is illegal!!\n");
		}


	}

	return 0;
}


