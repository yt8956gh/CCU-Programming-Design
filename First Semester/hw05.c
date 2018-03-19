#include<stdio.h>
#include<stdlib.h>
float  adjscore(float bf)
{
	double a=bf;
	while((a*a)>bf)
	{a=((a*a)+bf)/2.0/a;}
	float aft=a*10;
	return aft;
		    /* double a=0,b=bf,near=0;
		     int i=0;
		
		     for(i;i<100;i++)
		     {
			 near=(a+b)/2.0;
	         if((near*near)>bf){b=near;}
			 else if((near*near)<bf){a=near;}
			 }
near=near*10;


return near;*/
}

main()
{
	
	float CS[1500],PS[1500],AS[1500],avg[1500],tmp=0;
	int i,j,k,g,ct,sq[1500];

	for(;i<1500;i++)
	{
	CS[i]=PS[i]=AS[i]=avg[i]=0;
	sq[i]=i;
	}
	
	i=j=k=g=ct=0;//ct is squence of poeple
	
	
	while(	(scanf("%f %f %f\n", &CS[i], &PS[i], &AS[i]))!=EOF	)
	{	
		fflush(stdin);
		if(CS[i]<0||PS[i]<0||AS[i]<0)
		{printf("ERROR : There are negative numbers in the scores input. \n");	return 0;}

		if(CS[i]>100||PS[i]>100||AS[i]>100)
		{printf("ERROR : There are numbers over 100 in the scores input. \n");	return 0;}

		CS[i]=adjscore(CS[i]);
		PS[i]=adjscore(PS[i]);
		AS[i]=adjscore(AS[i]);
		
		i++;	ct++;
	}
	if(ct==0)	
	{printf("ERROR : The file input could be empty or not exist.\n");	return 0;}	

	i=0;

	for(;i<ct;i++)
	{avg[i]=(CS[i]+PS[i]+AS[i])/3.0;}
	
	for(j=0;j<=ct;j++)
	{	
		for(i=0;i<=ct;i++)	
		{
				if(avg[i]<avg[i+1])	//max~min	
				{
				tmp=0;

				tmp=avg[i]; avg[i]=avg[i+1]; avg[i+1]=tmp;
				
				tmp=CS[i]; CS[i]=CS[i+1]; CS[i+1]=tmp;
				
				tmp=PS[i]; PS[i]=PS[i+1]; PS[i+1]=tmp;
				
				tmp=AS[i]; AS[i]=AS[i+1]; AS[i+1]=tmp;
				
				tmp=sq[i]; sq[i]=sq[i+1]; sq[i+1]=tmp;

				}//if		
		}//for interior
	}	
	
	printf("ID\t|   Calculus    |  Programming  | Linear Algebra|    Average\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<ct;i++)
	{	
		printf("%d\t|\t%.1f\t|\t%.1f\t|\t%.1f\t|\t%.1f\n",sq[i],CS[i],PS[i],AS[i],avg[i]);	
		//building
	}
	
	tmp=0;
	
	float cavg,csum,pavg,psum,aavg,asum,ctf=ct; 
	cavg=csum=pavg=psum=aavg=asum=0.0;

	for(i=0;i<ct;i++)
	{	
		csum=csum+CS[i];
		psum=psum+PS[i];
		asum=asum+AS[i];		
	}
			
			
	for(j=0;j<ct;j++)		
	{		
			
			//CS				
			for(i=0;i<(ct-j);i++)
			{	
				if(CS[i]<CS[i+1])	//max~min	
				{
				tmp=0;	tmp=CS[i];	CS[i]=CS[i+1];	CS[i+1]=tmp;
				}
			}
			//PS
			for(j=0;j<(ct-i);j++)
			{	
				if(PS[i]<PS[i+1])	//max~min	
				{
				tmp=0;	tmp=PS[i];	PS[i]=PS[i+1];	PS[i+1]=tmp;
				}
			}

			//AS
			for(j=0;j<(ct-i);j++)
			{	
				if(AS[i]<AS[i+1])	//max~min	
				{
				tmp=0;	tmp=AS[i];	AS[i]=AS[i+1];	AS[i+1]=tmp;
				}
			}		
	}
		cavg=csum/ctf;
		pavg=psum/ctf;
		aavg=asum/ctf;
		printf("------------------------------------------------------------------------------------------------------------\n");
		printf("MAX\t|\t%.1f\t|\t%.1f\t|\t%.1f\n",CS[0],PS[0],AS[0]);	
		printf("MIN\t|\t%.1f\t|\t%.1f\t|\t%.1f\n",CS[ct-1],PS[ct-1],AS[ct-1]);	
		printf("AVG\t|\t%.1f\t|\t%.1f\t|\t%.1f\n",cavg,pavg,aavg);	

return 0;}
