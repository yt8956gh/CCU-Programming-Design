#include<stdio.h>
#include<ctype.h>
main()
{		
	int c,total,other,aphabet_n,number_n;
	int aphabet[26],number[10];
	int i,j,k,g;
	c=total=other=aphabet_n=number_n=0;
    
    for(i=0;i<26;i++)
    	{aphabet[i]=0;}
		
	for(j=0;j<10;j++)
		{number[j]=0;}
		
	while((c=getchar())!=EOF)
		{	total++;
				
			if(c>='A'&&c<='Z')
				{c=tolower(c);}
			
			if(c>='a'&&c<='z')
				{	aphabet_n++;
					aphabet[c-'a']++;}
			
			else if(c>='0'&&c<='9')
				{	number_n++;
					number[c-'0']++;}
		}
	
	other=total-aphabet_n-number_n;
	printf("Total\tcharacters : %d\n",total);
	printf("Other\tcharacters : %d\n",other);
	
	float total_f=total;
	if(total==0)
	{
	printf("--number--\nThe file input is empty.\n");
	printf("--alphabet--\nThe file input is empty.\n");
	}		
	else
	{	
		printf("--number--\n");
			
		for(k=0;k<10;k++)
		{printf("%d : %d , %.3f \n",k,number[k],number[k]/total_f);}
	
		printf("--alphabet--\n");
	
		for(g=0;g<26;g++)
		{printf("%c : %d , %.3f \n",g+97,aphabet[g],aphabet[g]/total_f);}

	}
return 0;
}
