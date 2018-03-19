#include<stdio.h>
#include<ctype.h>
int LCM(int a,int b)
{
	int max=0,min=0,i=1,result=0;

	if(a>=b){max=a;min=b;}
	else 	{max=b;min=a;}

	while(i)	
	{
		if((max*i)%min==0)
		{result=max*i; break;}
		i++;
	}
	return result;
}

int GCD(int a,int b)
{
	return a*b/LCM(a,b);
}

main(){


int a=0,b=0,i=0,gcd=0,lcm=0;
		
while((scanf("%d %d",&a,&b))!=EOF)
{
getchar();//test
if(a==0||b==0){printf("ERROR: There is Zero in numbers input.\n");continue;}

gcd=GCD(a,b);
lcm=LCM(a,b);

printf("--%d,%d--\n",a,b);
printf("GCD = %d\n",gcd);		
printf("LCM = %d\n\n",lcm);
i++;
}		
		
if(i==0){printf("ERROR: The file input could be empty.\n");}		
				
return 0;}
