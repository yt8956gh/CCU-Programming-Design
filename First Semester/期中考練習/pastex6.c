#include<stdio.h>
#include<string.h>
main()
{
char a[1000][32]={'\0'};
int i=0,k=0,max=0,maxsq=0,tmp=0;


while((scanf("%s",&a[i]))!=EOF)		
{	
	for(k=0;(a[i][k]!='\0')&&(k<=32);k++){tmp++;}//�`�N:�{�b�ϥΪ��O�G���}�C	
	
	if(max<tmp)	
	{
	max=tmp;
	maxsq=i;
	}
	
	tmp=0;
	i++;
}


printf("%s\n",a[maxsq]);				
return 0;}
