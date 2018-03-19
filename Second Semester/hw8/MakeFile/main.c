#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "type.h"

int main(int argc,char **argv)
{

	int len=0,hv=0,i=0,MAXTERM=0,exist=0,other=0;
	char tmp[MAX_STR],*ptr=NULL,*end=NULL;

	NODE *ht[MAX_HV];

	FILE *dic=NULL,*input=NULL,*src;

	//"The Array of Pointer to Structure" will not be assigned NULL in sequence automatically.
	// if the pointer not assigned NULL , the "segmentation fault" will happen.

	for(i=0;i<MAX_HV;i++)
	{
		ht[i]=NULL;
	}

	if(argc==3)
	{
		dic=fopen(argv[1],"r");
		input=fopen(argv[2],"r");
		src=input;//src will be used in while(fgets(,,src))

		if(input==NULL)
		{
			fprintf(stderr,"The file cannot be opened !\n");
			exit(1);
		}
	}
	else if(argc==2)
	{
		dic=fopen(argv[1],"r");
		src=stdin;//src will be used in while(fgets(,,src))

	}
	else
	{
		fprintf(stderr,"Usage: seg [dictionary file] [input file] OR [stdin]\n");
		exit(1);
	}

	if(dic==NULL)
	{
		fprintf(stderr,"The dictionary file cannot be opened !\n");
		exit(1);
	}


	while(fgets(tmp,MAX_STR,dic)) 
	{

		if((*(int*)tmp<128)&&(*(int*)tmp>0))
		{
			//printf("REMOVE: %s\n",tmp);
			continue;
		}

		len=strlen(tmp);
		len--;
		tmp[len]='\0';

		if(len>MAXTERM)
		{
			MAXTERM=len;
		}

		hv=hash_value(tmp);
		ht[hv]=insert_node(tmp,ht[hv]);
	}


	while(fgets(tmp,MAX_STR,src))
	{	

		len=strlen(tmp);
		len--;
		tmp[len]='\0';

		ptr=tmp;
	
		end=&tmp[len];
		other=0;

		while(ptr<end)
		{
			i=*ptr;

			while((i<128)&&(i>0))
			{
				printf("%c",*ptr);
				ptr++;
				other=1;
				i=*ptr;
			}
			
			if(other==1)
			{
				printf("\n");
				other=0;
			}

			len=strlen(ptr);
						
			if(len>MAXTERM)	len=MAXTERM;

			len=len/CHR_LEN;
			len=len*CHR_LEN;

			exist=0;
	
			for(i=len;i>0;i=i-CHR_LEN)
			{
				if((exist=word_check(ht,ptr,i))==1)// i is the string length of the word 
				{
					ptr=ptr+i;
					break;
				}
			}

			if(exist==0)
			{		
				// Print BOM(byte-order-mark) U+FEFF without "\n"
				if((ptr[0]==-17)&&(ptr[1]==-69)&&(ptr[2]==-65))	
				{
					printf("%c%c%c",-17,-69,-65);//print FEFF
				}
				else
				{
					printf("%.3s\n",ptr);
				}

				ptr+=CHR_LEN;
			}
		}
	}

	return 0;
}


