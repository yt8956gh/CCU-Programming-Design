#include<stdio.h>
#include<ctype.h>
#define in 1
#define out 0
#define other 2
main()
	{
	int c,state,w_total,a_total,ch,wmax,wtmp;
	int a_count[26];
	int i;
	float a_f[26];
	char all_tmp[9999] = {' '}; 
	c=ch=state=wmax=wtmp=w_total=a_total=0;

	for(i=0;i<26;i++)
	{a_count[i]=a_f[i]=0;}	

	while((c=getchar())!=EOF)
	{	
		if(c==' '||c=='\n'||c=='\t')
		{	
			state=out;
			all_tmp[ch]=' ';
			if(wmax<=wtmp)
			{wmax=wtmp;}
			wtmp=0;
		}
		else if(state==out)
		{
			if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
			{	
				state=in;
				w_total++;	
			}
			else
			{state=other;}

		}
		
		if(state==in)
		{	all_tmp[ch]=c; wtmp++;
		}
		if(c>='A'&&c<='Z')
		{	c=tolower(c);}
		
		if(c>='a'&&c<='z')
		{	a_count[c-'a']++;
			a_total++;		}
		ch++;		
	}

if(a_total==0)
{printf("ERROR : The file input could be EMPTY or NOT EXIST.\n");return 0;	}	

printf("Word count : %d \n",w_total++);
printf("Length of the max word : %d\n",wmax);
printf("\n--Words--\n");

state=out;

for(i=0;i<ch;i++)
{	
	if(all_tmp[i]==' '||all_tmp[i]=='\n'||all_tmp[i]=='\t')
	{state=out;}

	else if(state==out)
	{printf("\n");
	state=in;}

	if(state==in)
	{printf("%c",all_tmp[i]);}		
}

printf("\n--alphabet--\n");
printf("total : %d\n",a_total);

float sum=0,avg=0,a_total_f=a_total;
for(i=0;i<26;i++)
	{	
		a_f[i]=a_count[i]/a_total_f;
		sum=a_f[i]+sum;
		printf("%c : %d , %.3f\n",97+i,a_count[i],a_f[i]);
	}

printf("\nAvg = %.3f\n",sum/26.0);

int max=a_count[0],min=a_count[0];
int max_s=0,min_s=0;

for(i=0;i<26;i++)
{
	if(max<a_count[i])
		{	max=a_count[i];
			max_s=i;}
	if(min>a_count[i])
		{	min=a_count[i];
			min_s=i;}	
}
printf("Max : %c:%d,%.3f\n",'a'+max_s,max,a_f[max_s]);
printf("Min : %c:%d,%.3f\n",'a'+min_s,min,a_f[min_s]);

return 0;}
