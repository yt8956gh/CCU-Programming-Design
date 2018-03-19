#include<stdio.h>
#include<string.h>

main(){
		
int c,a,e,i,o,u;
c=a=e=i=o=u=0;
		
while((c=getchar())!=EOF)
	{
	if(c=='a'||c=='A')
	{a++;}
			
	if(c=='e'||c=='E')
	{e++;}
		
	if(c=='i'||c=='I')
	{i++;}
	
	if(c=='o'||c=='O')
	{o++;}

	if(c=='u'||c=='U')
	{u++;}
	}
		
		
printf("a:%d\ne:%d\ni:%d\no:%d\nu:%D\n",a,e,i,o,u);		
		
		
return 0;	}
