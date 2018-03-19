#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxword 100+5

//VERSION : Free Memory Allocated

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
	WORD *ptr=header,*current=NULL;

	while(ptr!=NULL)//problem
	{
			if((strcmp(ptr->word,wordtmp))==0)
			{
					(ptr->count)++;
					return header;
			}

			ptr=(ptr->next);
	}

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

	return current;
}
//	####SORT####
//	1,FROM FIRST NODE, Check the gap suitable for insertion
//	2,Remove the node correspending to the round
//	3,Check the whether the gap suitable is in front of the first iterm
//	4,Insert node to the suitable gap
//	5,return header(named "Llist" in teacher's note)


WORD * Sort(WORD * header)//#"INSERTION SORT" by Descending Power
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
				
		for(k=0;k<i;k++)// In last round, ptr will be behind "the suitable gap". illustration: lastp -> now -> ptr
		{
			if((ptr==NULL)&&(ptr==now))//"ptr" has be "now" in last round 
			{
				break;
			}
			
			if((ptr->count)<=(now->count))//The find must be the first iterm smaller than now->count
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
				continue;//前面可能會發生PTR(Find)==NOW的情況
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
	WORD *header=NULL,*ptr=NULL;
	
	while(fgets(wordtmp,maxword,stdin))
	{
		len=strlen(wordtmp);//remove '\n'
		wordtmp[len-1]='\0';
			
		header=insert(wordtmp,header);
	}

	header=Sort(header);

	if(header==NULL)
	{
		fprintf(stderr,"The database is empty.\n");
		return 0;
	}

	for(i=0;i<n;i++)
	{
		printf("%d %s\n",header->count,header->word);
		header=(header->next);
	}	

	while(ptr!=NULL)
	{
		ptr=header;
		header=header->next;
		free(ptr);
	}


	return 0;

}


