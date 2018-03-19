#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"type.h"

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


