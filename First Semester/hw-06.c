#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define out 0
#define in 1
main()
{
int c,upa,lowa,num,state,max,tmp,re[1500],ct,i,j,k,g;
char wmax[1500]={' '},wtmp[1500]={' '};
float ul,na;
c=upa=lowa=num=state=i=k=j=g=ul=na=ct=max=tmp=0;

for(i=0;i<1500;i++)
{re[i]=0;}
i=0;

while((c=getchar())!=EOF)
{	
	re[i]=c;

	if(c>=65&&c<=90)
	{upa++;}
	else if(c>=97&&c<=122)
	{lowa++;}
	else if(isdigit(c))
	{num++;}
//--------------------------------------------		
	if(isspace(c)||c=='\t')
	{state=out;	
		if(tmp>max)		
		{
		max=tmp;	
		strcpy(wmax,wtmp);		
		}
	}	
	else if((state==out)&&(isalpha(c)))
	{
	state=in;  k=tmp=0;
	memset(wtmp,' ',sizeof(wtmp));
	}
//---------------------------------------------
	if(state==in)
	{ wtmp[k]=c;  tmp++;  k++;}		
	
	i++;   ct++;							
}//while			
	
if((upa+lowa+num)==0)
{printf("ERROR : The file input could be empty or not exist.\n");	return 0;}

if((lowa+upa)==0||lowa==0)
{printf("ERROR : divided by zero\n");return 0;}





float totala=upa+lowa,lowaf=lowa;		

printf("Uppercase/Lowercase : %.3f\n",upa/lowaf);
printf("Digit/Alphabet : %.3f\n",num/totala);
printf("--Reverse--\n");

for(j=ct-1;j>=0;j--)
{printf("%c",re[j]);}

printf("\n--MAX--\n");	
i=0;
while(wmax[i]!=' ')
{printf("%c",wmax[i]);i++;}

printf("\n%d\n",max);

return 0;		}
