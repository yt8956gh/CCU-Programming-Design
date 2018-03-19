#include<stdio.h>
#include<string.h>
#define in 1
#define out 0
main()
{
int state=0,c=0;

while((c=getchar())!=EOF)
{
	if((c==' ')||(c=='\n')||(c=='\t'))	
	{state=out;}
	else if((state==out) && isalpha(c))
	{
	state=in;
	printf("\n");
	}
	
	if(state==in)
	{printf("%c",c);}

}	

printf("\n");

return 0;}
