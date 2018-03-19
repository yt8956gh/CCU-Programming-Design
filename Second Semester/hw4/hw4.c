#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxword 100+5

int n=0;

struct WordType
{
	char	word[maxword];
	int		count;
	struct WordType *next;

};

typedef struct WordType WORD;

//	##insert##
//
//	1,Determine whether the word is repetive
//	2,Keep data in current (struct)
//	3,Allocate a space for current
//	4,Build new node in linked list

WORD* insert(char *wordtmp,WORD *header)
{
	int exist=0,i=0,check=0;
	WORD *ptr=header,*current=NULL;

	for(i=0;i<n;i++)//problem
	{
			if(ptr==NULL)
			{
				break;
			}

			if((check=strcmp(ptr->word,wordtmp))==0)
			{
					exist=1;
					(ptr->count)++;
					return header;
			}

			ptr=(ptr->next);
	}

	if(exist==0)
	{
			current=(WORD*)malloc(sizeof(WORD));
			
			if(current==NULL)
			{
				fprintf(stderr,"ERROR:Can not allocate memory !\n");
				return header;
			}

			strcpy(current->word,wordtmp);
			(current->count)=1;
			(current->next)=header;
			n++;
	}
	
	return current;
}
//	####SORT####
//	1,FROM FIRST NODE, Check the gap suitable for insertion
//	2,Remove the node correspending to the round
//	3,Check whether the gap suitable is in front of the first iterm
//	4,Insert node to the suitable gap
//	5,return header(named "Llist" in teacher's note)


WORD * Sort(WORD * header)//insertion for the first iterm
{
	int i=0,k=0;
	WORD *now=header,*nowlast=NULL,*ptr=NULL,*find=NULL,*lastp=NULL;
	
	for(i=1;i<n;i++)
	{			
		now=header;//warning
		
		for(k=0;k<(i-1);k++)
		{
			now=now->next;
		}
		
		nowlast=now;
		now=now->next;
	
		find=NULL;
		ptr=header;		
				
		for(k=0;k<i;k++)
		{
			if((ptr==NULL)&&(ptr==now))
			{
				break;
			}
			
			if((ptr->count)<=(now->count))
			{
				if(((ptr->count)==(now->count))&&(strcmp(ptr->word,now->word)<0))//sort with ASCII order
				{
					find=ptr;
				}
				else
				{
					find=ptr;
					break;
				}
			}
			
			lastp=ptr;	
			ptr=(ptr->next);

		}

		if(find!=NULL)
		{

			if(find==header)
			{
				(nowlast->next)=(now->next);
				now->next=header;
				header=now;
			}
			else if(find==now)
			{
				continue;
			}	
			else
			{
				(nowlast->next)=(now->next);
				(lastp->next)=now;
				(now->next)=find;
			}
			
		}
		

	}

	return header;
}


int main()
{

	char wordtmp[maxword];
	int i=0,len=0;
	WORD *header=NULL;
	
	while(fgets(wordtmp,maxword,stdin))
	{
		len=strlen(wordtmp);//remove '\n'
		wordtmp[len-1]='\0';
			
		header=insert(wordtmp,header);
	}

	header=Sort(header);
	
	for(i=0;i<n;i++)
	{
		if(header==NULL)
		{
			fprintf(stderr,"The database is empty.\n");
			break;
		}		

		printf("%d %s\n",header->count,header->word);

		header=(header->next);
	}

	return 0;

}


