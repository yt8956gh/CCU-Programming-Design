#include<stdio.h>
#include<string.h>

main()
{
		
int c=0,max=0,min=0;

scanf("%d",&c);//比大小時，min & max 的初始值必須是 [被比較的集合] 中的元素

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
