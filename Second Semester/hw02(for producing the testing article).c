#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


int main()
{
char totalc[100],newname[100]="data";
int total=0,i=0,var=0;

printf("Please enter the quantity of the data produced.\n");
scanf("%s",totalc);
total=atoi(totalc);

FILE *fp;
fp=fopen("data.txt","w");
srand(time(NULL));

for(i=0;i<total;i++)
{
	var=rand();
	fprintf(fp,"%d\n",var);
}

strcat(newname,totalc);
strcat(newname,".txt");

rename("data.txt",newname);
return 0;
}

