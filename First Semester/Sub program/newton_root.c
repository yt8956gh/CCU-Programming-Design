#include<stdio.h>

main()
{
double a=0,bf=0;


while((scanf("%lf",&bf))!=EOF)
{
	a=bf;

	while((a*a)>bf)
	{
		if((a*a)==bf){break;}
		a=((a*a)+bf)/(2*a);		
	}
		
	printf("%.3lf\n",a);		
}
return 0;		
		
		
		}
