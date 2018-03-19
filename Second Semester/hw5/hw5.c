#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100+5
#define MAXITERM 10000
#define PLUS 1
#define MINUS 0

struct WordType
{
	char	word[MAXWORD];
	int		count;
	struct WordType *next;
};

typedef struct WordType WORD;

//	##insert##
//	1, Determine if "state" is  PLUS(insert) or MINUS(delete)
//	2, Determine whether the input word is repetive in data 
//	3, Exist==1 represent that there is same word in data, vice versa
//	4, WHEN ADD NEW NODE, Allocate a space for current and Save data in current
//	5, ETHIER (Build new node in linked list) OR (Delete node form data and Free memory)

WORD* insert(char *wordtmp,WORD *header)
{
	int exist=0,state=PLUS;
	WORD *ptr=header,*current=NULL,*lastp=NULL;

	if(*wordtmp=='-')
	{
			state=MINUS;
			wordtmp++;
	}

	while(ptr!=NULL)//WARING: Don't access NULL point with "->"
	{

			if((strcmp(ptr->word,wordtmp))==0)//ptr is the "same word node"
			{
					exist=1;	//"exist==1" represent that there is same word in data
					break;
			}

			lastp=ptr;	//save last node of ptr
			ptr=(ptr->next);
	}

	if(exist==0)// build NEW node
	{
			if(state==PLUS)
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

					return current;
			}
			
			else if(state==MINUS)
			{
					return header;
			}


	}
	else if(exist==1)	// "exist==1" represent that there is same word in data
	{
			if(state==PLUS)
			{
					(ptr->count)++;
					return header;
			}

			else if(state==MINUS)
			{
					(ptr->count)--;

					if((ptr->count)<=0)
					{	
							if(ptr==header)
							{
										header=header->next;
										free(ptr);
										return header;
							}

							lastp->next=ptr->next;
							free(ptr);
							return header;	
					}
			}
	}
	return header;//problem: gcc ERROR
}

int WORD_cmp(const void *x,const void *y)
{
	int a=((WORD*)x)->count;
	int b=((WORD*)y)->count;
	
	if(a==b){return strcmp(((WORD*)x)->word,((WORD*)y)->word);}
	return (b-a);
}

int main(int argc,char **argv)
{

	char wordtmp[MAXWORD];
	int i=0,len=0,n=0;
	WORD *header=NULL,*ptr=NULL,sort[MAXITERM];
	FILE *fp;
	
	if(argc!=2)
	{
			printf("The command is illegal\n");
			return 0;
	}

	fp=fopen(argv[1],"r");
	
	if(fp==NULL)
	{
			printf("ERROR:File cannot be opened correctly\n");
			return 0;
	}

	while(fgets(wordtmp,MAXWORD,fp))
	{
			len=strlen(wordtmp);//remove '\n'
			wordtmp[len-1]='\0';
			header=insert(wordtmp,header);
	}

	if(header==NULL)
	{
			fprintf(stderr,"Terms not exists!\n");
			return 0;
	}

	ptr=header;

	for(i=0;ptr!=NULL;i++)
	{
			sort[i]=*ptr;
			ptr=ptr->next;
			n++;
	}

	qsort(sort,n,sizeof(WORD),WORD_cmp);
	
	ptr=header;

	for(i=0;ptr!=NULL;i++)
	{
			strcpy(ptr->word,sort[i].word);
			ptr->count=sort[i].count;
			ptr=ptr->next;
	}

	while(header!=NULL)
	{
			printf("%s:\t%d\n",header->word,header->count);
			ptr=header;
			header=(header->next);
			free(ptr);
	}

	return 0;
}


