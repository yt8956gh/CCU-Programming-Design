#include<stdio.h>
#include<string.h>

main()
{
		
int c=0,max=0,min=0;

scanf("%d",&c);//��j�p�ɡAmin & max ����l�ȥ����O [�Q��������X] ��������

min=max=c;

while((scanf("%d",&c))!=EOF)
{ 
if(c==-1){break;}


if(c>=max){max=c;}
if(c<=min){min=c;}


}
printf("\nMIN : %d",max);
printf("\nMAX : %d\n",min);

return 0;}
