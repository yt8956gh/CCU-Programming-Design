#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_student 10000
#define max_name  100
#define max_phone 100
#define max_id 100
#define max_age 10
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

//syntax check TOOLs

int commacheck(char *cmdtmp,int n);
int IDcheck(stu *addrp,char id[max_id],int n);
stu * DataCheck(char *cmdtmp);

//funtional SubPrograms

int Insert(stu *addrp,char *cmdtmp,int n);

int Update(stu *addrp,char *cmdtmp,int n);

int Delete(stu * addrp,char *cmdtmp,int n);

void sort(stu *addrp,char *cmdtmp,int n);

void find(stu* addrp,char *cmdtmp,int n);

//compare SubPrograms

int cmp_id(const void *x,const void *y);
int cmp_name(const void *x,const void *y);
int cmp_phone(const void *x,const void *y);
int cmp_age(const void *x,const void *y);


int main()
{

	stu addr[max_student];
	int n=0,i=0,len=0;
	int cmdmax=(max_name + max_phone + max_id +	max_age);
	char *cmdtmp=NULL;
	FILE *fp;
	
	cmdtmp=(char*)malloc(sizeof(char *)*cmdmax);

	printf("Please input command(i/d/u/f/l/s/w) and data.\n");
	
	while(fgets(cmdtmp,cmdmax,stdin))
	{	
		len=strlen(cmdtmp);
		*(cmdtmp+len-1)='\0';//make '\n' be '\0'

		switch(*cmdtmp)//the command_lines input are complete 
		{		
			case'i':

				if(*(cmdtmp+1)!=',')
              			{
					fprintf(stderr,errorcode);
        				continue;
            			}

				n=Insert(addr,cmdtmp,n);
				break;

			case'u'://---------------------------------------------------------------------------------------------

				if(*(cmdtmp+1)!=',')
                                {
                                        fprintf(stderr,errorcode);
                                        continue;
                                }
				
                                n=Update(addr,cmdtmp,n);
                                break;

			case'd'://---------------------------------------------------------------------------------------------
				
				if(*(cmdtmp+1)!=',')
                                {
                                        fprintf(stderr,errorcode);
                                        continue;
                                }

				n=Delete(addr,cmdtmp,n);				
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
				printf("\n");
				break;	

                        case's'://----------------------------------------------------------------------------------------------
					
				if(*(cmdtmp+1)!=',')
                                {
                                        fprintf(stderr,errorcode);
                                        continue;
                                }

				sort(addr,cmdtmp,n);
				break;

			case'f'://---------------------------------------------------------------------------------------------
		
				if(*(cmdtmp+1)!=',')
                                {
                                        fprintf(stderr,errorcode);
                                        continue;
                                }

				find(addr,cmdtmp,n);
				break;

			case'q'://----------------------------------------------------------------------------------------------
				
				if(strcmp(cmdtmp,"q")!=0)
                                {
                                        fprintf(stderr,errorcode);
                                        continue;
                                }

				printf("Exit\n");
				return 0;

			case'w'://----------------------------------------------------------------------------------------------
				
				if((commacheck(cmdtmp,1)==error))
				{
					fprintf(stderr,errorcode);
					break;
				}
				
				cmdtmp=cmdtmp+2;
				
				fp=fopen(cmdtmp,"w");

				for(i=0;i<n;i++)
				{
					fprintf(fp,"%s,%s,%s,%d\n",addr[i].id , addr[i].name , addr[i].phone ,addr[i].age);
				}

				if(fp!=NULL)
				{
					printf("Writing file successful!\n");
				}
				
				fclose(fp);
				break;
			
			default://----------------------------------------------------------------------------------------------

				fprintf(stderr,"Please input command(i/d/u/f/l/s/w) and data.\n");
				break;
		}
	}
			
	free(cmdtmp);

	return 0;
}

//	commacheck:
	
//	1,	CHECK the quantity of commas  
//	2,	Ruled Out the possibility of condition ",," in command_line
//	NOTE:	If the syntax of cmdtmp is illegal, return error 

int commacheck(char *cmdtmp,int n)
{
	int commaN=0,len=strlen(cmdtmp),i=0;
	char *ptr=NULL;//ptr is assistant pointer
	
	if((ptr=strstr(cmdtmp,",,"))!=NULL)
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

int IDcheck(stu *addrp,char id[max_id],int n)
{
	int i=0;
	
	for(i=0;i<n;i++)
	{
		if(strcmp(addrp[i].id,id)==0)
		{
			return 1;		//	NOTE:	"1" represents that "the ID checked exists in array of struct"
		}
	}

	return 0;
}

//	DataCheck
//	1.	Deal with the command_line of insert and update
//	2.	Using commacheck to examine syntax of cmdtmp 
//	3.	Return the (sturct_pointer_stu*) to insert and updata funtion 
//		for copying data to data_array in main


stu * DataCheck(char *cmdtmp)
{
	
	int len=strlen(cmdtmp),i=0,k=0;
	int CommaCheck=commacheck(cmdtmp,4);
	char *id,*name,*phone,*age;
	id=name=phone=age=NULL;

	stu *stutmp=NULL;
	stutmp=(stu*)malloc(sizeof(stu));
	
	if(CommaCheck==error)
	{
		return NULL;
	}
	
	for(k=0;k<len;k++)
	{
		if(*cmdtmp==',')
		{	
			*cmdtmp='\0';
			cmdtmp++;

			switch(i)
			{
				case 0:	
					id=cmdtmp;
					break;
				case 1:
					name=cmdtmp;
					break;
				case 2:
					phone=cmdtmp;
					break;
				case 3: 
					age=cmdtmp;
					break;							
			}
			
			i++;
		}
		cmdtmp++;
	}

	if(((age-phone)==1)||((phone-name)==1)||((name-id)==1))//if there is nothing between the commas.
	{
		return NULL;
	}

	strcpy (stutmp->id , id);

	strcpy (stutmp->name , name);

	strcpy (stutmp->phone , phone);

	stutmp->age = atoi(age);
		
	return stutmp;

}


int Insert(stu *addrp,char *cmdtmp,int n)
{
	
	stu *stutmp=NULL;
        stutmp=(stu*)malloc(sizeof(stu));
	cmdtmp++;
	stutmp=DataCheck(cmdtmp);

        if(stutmp==NULL)
        {
                fprintf(stderr,errorcode);
		return n;
        }

	if(IDcheck(addrp,stutmp->id,n)==1)
	{
		fprintf(stderr,"Insert error! studentID exists!\n");
		return n;
	}

	addrp[n]=(*stutmp);

        printf("%s,%s,%s,%d\n",stutmp->id , stutmp->name , stutmp->phone ,stutmp->age);


	return ++n;

}

int Update(stu *addrp,char *cmdtmp,int n)
{
    	cmdtmp+=2;
	int i=0,target=0,len=strlen(cmdtmp);
	char *ptr=NULL,id[max_id];
        stu *stutmp=NULL;
        stutmp=(stu*)malloc(sizeof(stu));
	ptr=cmdtmp;	

        for(i=0;i<len;i++)
	{
		if(*cmdtmp==',')
		{
			break;
		}

		cmdtmp++;
	}
	
	*cmdtmp='\0';
	strcpy(id,ptr);
	*cmdtmp=',';//make the format be ",ID,name,phone,age\0"

	stutmp=DataCheck(cmdtmp);

	//printf("DATA_CHECK finished\n");	

	if(stutmp==NULL)
	{
		fprintf(stderr,errorcode);	
		return n;
	}

        //printf("STUTMP_CHECK finished\n");

	if(strcmp(stutmp->id,id)!=0)
	{
		fprintf(stderr,errorcode);
		return n;	
	}	

        //printf("Same_ID_CHECK finished\n");

	if(IDcheck(addrp,stutmp->id,n)!=1)
        {
                fprintf(stderr,"Update error! studentID does not exists!\n");
                return n;
        }

	//printf("ID_CHECK finished\n");
	
	for(i=0;i<n;i++)
        {
                if(strcmp(addrp[i].id,stutmp->id)==0)
                {
                  	target=i;      
                }
        }

        printf("%s,%s,%s,%d\n",stutmp->id , stutmp->name , stutmp->phone ,stutmp->age);


	addrp[target]=(*stutmp);

        return n;

}

int Delete(stu * addrp,char *cmdtmp,int n)
{

	cmdtmp+=2;
	
	int i=0,target=0,exist=0;
	char *id=cmdtmp;
	
	if((strchr(cmdtmp,','))!=NULL)
	{
		fprintf(stderr,errorcode);
		return n;
	}

	for(i=0;i<n;i++)
	{
		if(strcmp(addrp[i].id,id)==0)
		{
			target=i;
			exist=1;
		}
	}

	if(exist==0)
	{
		fprintf(stderr,"Delete error! studentID does not exists!\n");
		return n;
	}
	
	printf("%s,%s,%s,%d\n",addrp[target].id,addrp[target].name,addrp[target].phone,addrp[target].age);

	for(i=target;i<(n-1);i++)
	{
		addrp[i]=addrp[i+1];
	}

	memset(&addrp[n-1],0,sizeof(stu));
	
	return --n;
}

//	COMPARE SubProgram:
//	The x in cmp_string funtion represents a pointer of void type
//	Thus,we must assign type(stu*) to x and make x be a (stu *x)
//	The operation  (x -> string)  symbols    (*x).string   
//	NOTE:  Because x is a pointer , the (x) just represents a address of struct


int cmp_id(const void *x,const void *y)
{
        return (strcmp( ((stu*)x)->id , ((stu*)y)->id) );
}

int cmp_name(const void *x,const void *y)
{
        return (strcmp( ((stu*)x)->name , ((stu*)y)->name) );
}

int cmp_phone(const void *x,const void *y)
{
        return (strcmp( ((stu*)x)->phone , ((stu*)y)->phone) );
}

int cmp_age(const void *x,const void *y)
{
        return ( ((stu*)x)->age - ((stu*)y)->age) ;
}

void sort(stu *addrp,char *cmdtmp,int n)
{
	int i=0;
	cmdtmp+=2;//remove "s," from  command_line  

	if((strcmp("studentID",cmdtmp))==0)
	{
		qsort(addrp,n,sizeof(stu),cmp_id);
	}
	
	else if((strcmp("name",cmdtmp))==0)
        {
                qsort(addrp,n,sizeof(stu),cmp_name);
        }

	else if((strcmp("phone",cmdtmp))==0)
        {
                qsort(addrp,n,sizeof(stu),cmp_phone);
        }

	else if((strcmp("age",cmdtmp))==0)
        {
                qsort(addrp,n,sizeof(stu),cmp_age);
        }

	else
	{
		fprintf(stderr,errorcode);
		return;
	}
	for(i=0;i<n;i++)
	{
		printf("%s,%s,%s,%d\n",addrp[i].id , addrp[i].name , addrp[i].phone ,addrp[i].age);
	}
	
	printf("\n");

}

void find(stu* addrp,char *cmdtmp,int n)
{
	cmdtmp+=2;
	int CommaCheck=commacheck(cmdtmp,0);
	int i=0,FIND[n],j=0,fn=0;
	char *ptr=NULL;

	if(CommaCheck==error)
	{
		fprintf(stderr,errorcode);
		return ;	
	}
	
	for(i=0;i<n;i++)// "j" is the counter of FIND[]
	{
		if((ptr=strstr(addrp[i].id,cmdtmp))!=NULL)
		{
			FIND[j++]=i;		
		}

                else if((ptr=strstr(addrp[i].name,cmdtmp))!=NULL)
                {
                        FIND[j++]=i;
                }

                else if((ptr=strstr(addrp[i].phone,cmdtmp))!=NULL)
                {
                        FIND[j++]=i;
                }

                else if( addrp[i].age == atoi(cmdtmp) )
                {
                        FIND[j++]=i;
                }
		
	}

	if(j==0)
	{
		fprintf(stderr,"Find error! The string input is not found!\n");
		return ;
	}
	
	for(i=0;i<j;i++)
	{
		fn = FIND[i];
		printf("%s,%s,%s,%d\n",addrp[fn].id , addrp[fn].name , addrp[fn].phone ,addrp[fn].age);
	}
	
	printf("\n");

}


