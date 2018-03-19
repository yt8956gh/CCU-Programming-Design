#include<stdio.h>
#include<string.h>

main()
{

char n[130]={'n','u','l','l','\0'},N[130]={'N','U','L','L','\0'};
int state=0,i=0,k=0,j=0,size1=0,test1=0,test2=0,samesq[130]={'\0'};
char str1[130]={'\0'},str2[130]={'\0'};

while((scanf("%s",&str1))!=EOF)
{		
	scanf("%s",&str2);
	//ok
	test1=strcmp(str1,n);
	test2=strcmp(str1,N);

	for(i=0;str1[i]!='\0';i++)
	{size1++;}
	//ok
	if(test1==0||test2==0)	{printf("Yes\n");	continue;}

	for(i=0;str2[i]!='\0';i++)
	{		
		if(str2[i]==str1[0])		
		{samesq[k]=i; k++;}				
	}		
	//ok

//printf("@%d@",samesq[0]);
		
	for(i=0;i<k;i++)
	{		
			int sq=samesq[i],comnum=1;
			
				for(j=1;str1[j]!='\0';j++)	
				{
					if(str2[sq+j]==str1[j])
					{comnum++;}
					else
					{break;}
				}
	
			if(comnum==size1)
			{state=1;}
		
	}

	if(state==1){printf("Yes\n");}
	else{printf("No\n");}

state=i=k=j=size1=test1=test2=0;

memset(samesq,'\0',sizeof(samesq));
memset(str1,'\0',sizeof(str1));
memset(str2,'\0',sizeof(str2));

}

return 0;}
