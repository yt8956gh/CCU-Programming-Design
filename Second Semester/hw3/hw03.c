#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_student 10000
#define max_name  100
#define max_phone 100
#define max_id 100
#define error 0
#define corret 1
#define errorcode "ERROR: The format input is illegal.\n"


typedef struct student_data
{
	char name[max_name];
	char phone[max_phone];
	char id[max_id];
	int age;
}stu;

int commacheck(char *cmdtmp,int n)
{
	int commaN=0,len=strlen(cmdtmp),i=0;
	char *ptr,*qtr;
	
	if((qtr=strstr(cmdtmp,",,"))!=NULL)
	{
		return error;
	}
		
	ptr=(cmdtmp+len-1);//check whether the last character is comma in command_line

	if(*ptr==',')
	{
		return error;
	}


	for(i=0;i<len;i++)
	{	
		if((ptr=strchr(cmdtmp,','))!=NULL)
		{
			commaN++;
			cmdtmp=(ptr+1);
		}
		else
		{
			break;
		}
	}

	
	if(commaN!=n)
	{
		return error;
	}	
	else
	{
		return corret;
	}
}

int IDcheck(stu *addrp,char *id,int n)
{
		int i=0;
	
		for(i=0;i<n;i++)
		{
				if(strcmp(addrp[i].id,id)==0)
				{
					return 1;
				}
		}
		return 0;
}


int Insert(stu *addrp,char *cmdtmp,int n)
{
	
	int i=0;
	int CommaCheck=commacheck(cmdtmp,4);
	char *id,*name,*phone,*age;
	
	cmdtmp++;
	id=name=phone=age=NULL;
	
	if(CommaCheck==error)
	{
		fprintf(stderr,errorcode);
		return n;
	}

	id=strtok(cmdtmp,",");
	
	for(i=1;i<=3;i++)
	{
			switch(i)
			{
				case 1:
					name=strtok(NULL,",");
					break;
				case 2:
					phone=strtok(NULL,",");
					break;
				case 3: 
					age=strtok(NULL,",");
					break;							
			}
	}

			
	if((id!=NULL)||(age!=NULL)||(phone!=NULL)||(name!=NULL))//if there is nothing between the commas.
	{
		fprintf(stderr,errorcode);
		return n;
	}

	if(IDcheck(addrp,id,n)==1)
	{
		fprintf(stderr,"Insert error! studentID is exists!\n");
		return n;
	}

	strcpy (addrp[n].id , id);
	strcpy (addrp[n].name , name);
	strcpy (addrp[n].phone , phone);
	addrp[n].age = atoi(age);
	
	printf("%s,%s,%s,%d\n",addrp[n].id , addrp[n].name , addrp[n].phone ,addrp[n].age);

	return ++n;

}


int main()
{

	stu addr[max_student];
	int n=0,i=0,cmdmax=(max_name + max_phone + max_id+6),len=0;
	char *cmdtmp=NULL;
	FILE *fp;
	
	cmdtmp=(char*)malloc(sizeof(char *)*cmdmax);

	printf("Please input command(i/d/u/f/l/s/w) and data.\n");
	
	while(fgets(cmdtmp,cmdmax,stdin))
	{	
	
		len=strlen(cmdtmp);
		*(cmdtmp+len-1)='\0';

		switch(*cmdtmp)
		{		
			case'i':

				if(*(cmdtmp+1)!=',')
              			{
					fprintf(stderr,errorcode);
        				continue;
            			}

				n=Insert(addr,cmdtmp,n);
				break;
					
			case'l'://----------------------------------------------------------------------------------------------
				
				if(strcmp(cmdtmp,"l")!=0)
				{
					fprintf(stderr,errorcode);
					continue;
				}
			
				for(i=0;i<n;i++)
				{
					printf("%s,%s,%s,%d\n",addr[i].id , addr[i].name , addr[i].phone ,addr[i].age);
				}	
				break;		
			case'q'://----------------------------------------------------------------------------------------------

				printf("Exit\n");
				return 0;

			case'w'://----------------------------------------------------------------------------------------------
				
				if((commacheck(cmdtmp,1)==error))
				{
					fprintf(stderr,errorcode);
				}
				
				cmdtmp=cmdtmp+2;
				
				fp=fopen(cmdtmp,"w");

				for(i=0;i<n;i++)
				{
					fprintf(fp,"%s,%s,%s,%d\n",addr[i].id , addr[i].name , addr[i].phone ,addr[i].age);
				}
				break;
			
			default://----------------------------------------------------------------------------------------------

				fprintf(stderr,"Please input command(i/d/u/f/l/s/w) and data.\n");
				break;
		}
	}
			

free(cmdtmp);

return 0;
}


