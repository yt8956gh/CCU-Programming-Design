#include<stdio.h>
#include<string.h>

int isprime(int en)
{	
	int tf=1,i=0;

	for(i=2;i<en;i++)
	{
		if((en%i)==0)
		{tf=0;break;}
	}

	return tf;

}
main()
	{
	int a[1005]={'\0'},prime[1005]={'\0'},tmp=0,i=0,k=0,total=0;

	while((scanf("%d",&a[i]))!=EOF)
	{
	prime[i]=isprime(a[i]);		i++;	total++;
	}
	
	if(i==0){printf("ERROR :The file input could be empty.\n");return 0;}

	printf("--isPrime--\n");

	for(i=0;i<total;i++)
	{
		printf("%d:",a[i]);
		if(prime[i]==1)
		{printf("yes\n");}
		else
		{printf("no\n");}
	}
		
			
	for(i=0;i<total;i++)		
	{					
		
		for(k=0;k<total-i-1;k++)
		{
			if(a[k]>=a[k+1])
			{
			tmp=a[k];
			a[k]=a[k+1];
			a[k+1]=tmp;
			}
		}
	}		
	
		
	printf("--Sort--\n");			
			
	for(i=0;i<total;i++)		
	{printf("%d\n",a[i]);}		
			
	return 0;}
