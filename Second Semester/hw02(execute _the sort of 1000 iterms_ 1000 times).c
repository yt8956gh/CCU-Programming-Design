#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define maxtest 10

void insertion(int *sort,int n)
{
	int i=0,next=0,tmp=0;

	for(i=1;i<n;i++)
	{
		tmp=sort[i];
		next=i;
		
		while((next>=1)&&(sort[next-1]>tmp))
		{
			sort[next]=sort[next-1];
			next--;				
		}	
		sort[next]=tmp;
				
	}

}



void selection(int *sort,int n)
{
	int i=0,j=0,tmp=0,st=0;
	
	for(i=0;i<n;i++)
	{
		st=i;
		
		for(j=(i+1);j<n;j++)
		{
			
			if(sort[st]>sort[j])
			{	
				st=j;
			}
		}
		
		tmp=sort[i];
		sort[i]=sort[st];
		sort[st]=tmp;
	}

}



void bubble(int *sort,int n)
{
	int i=0,j=0,tmp=0;

	for(i=0;i<n;i++)
	{
		for(j=1;j<(n-i);j++)
		{
			if(sort[j-1]>sort[j])
			{
				tmp=sort[j];
				sort[j]=sort[j-1];
				sort[j-1]=tmp;
			}		
		}
	}	
}



void print_number(int *var,int *number)
{
	int i=0;

	printf("Before			After\n");
	
	for(i=0;i<100;i++)
	{
		printf("%d",var[i]);

		if(var[i]<=9999999)
		{
			printf("			");
		}
		else
		{
			printf("		");
		}

		printf("%d\n",number[i]);

	}
}



int cmp_int(const void *x,const void *y)
{
		return (*(int*)x-*(int*)y);
}

int main()
{

	int i=0,var[1000000]={0},sorted[1000000]={0},j=0,total=1000,k=0;;
    double times[5][4],thousand[5];
	clock_t t1=0,t2=0;
	
	srand(time(NULL));

	for(i=0;i<1000000;i++)
	{
		var[i]=(rand()%1000000+1);
	}

    for(j=0;j<4;j++)
    {      
		
            for(i=0;i<5;i++)
            {	
            	k=0;
                 
                if(j==0)
				{
						if(i==0)printf("Insertion Sort\n");               	                 
                		if(i==1)printf("Selection Sort\n");
            		    if(i==2)printf("Bubble Sort\n");              	
           			    if(i==3)printf("Merge Sort\n"); 
          			    if(i==4)printf("Quick Sort\n");                                
				}
    
                do     
				{
                	memcpy(sorted,var,sizeof(sorted));           
                    
                    switch(i)
	                {
				            case 0:	
                                if(j==3)break;
                                t1=clock();                    
                                insertion(sorted,total); 
                                t2=clock();
                                break;
				            case 1:	
                                if(j==3)break;
                                t1=clock();   
                        	    selection(sorted,total);
                                t2=clock();
                                break;
				            case 2:	
                                if(j==3)break;
                                t1=clock();   
                        	    bubble(sorted,total);
                                t2=clock();
                                break;
				            case 3:	
                                t1=clock();   
		                        mergesort((int*)sorted,total,sizeof(int),cmp_int);
                                t2=clock();
                                break;
                            case 4:	
                                t1=clock();   
                    		    qsort((int*)sorted,total,sizeof(int),cmp_int);
                                t2=clock();
                                break;
	                }
					
					thousand[i]+=(t2-t1);
					k++;

				}while((k<=maxtest)&&(j==0));//do while
                
                if(j==0){print_number(var,sorted);}
				
				
				if(j==0)	{times[i][j]=thousand[i]/(10.0*(double)(CLOCKS_PER_SEC));}
              	else		{times[i][j]=((t2-t1)/(double)(CLOCKS_PER_SEC));}
            }

	    total=total*10;
    }
	

	//the code below is output of comparison table
	

    printf("		1000		10000		100000		1000000\n");

    for(i=0;i<3;i++)
    {    
      	 	switch(i)
			{
				case 0: printf("Insertion Sort	"); break;
				case 1: printf("Selection Sort	"); break;
				case 2: printf("Bubble  Sort	"); break;
			}
      	 	
      	 	printf("%lf	%lf	%lf	X\n",times[i][0],times[i][1],times[i][2]);
    }		
    
    for(i=3;i<5;i++)
	{	
			switch(i)
			{
				case 3: printf("Merge Sort	"); break;
				case 4: printf("Quick Sort	"); break;
			}

    		printf("%lf	%lf	%lf	%lf\n",times[i][0],times[i][1],times[i][2],times[i][3]);
	}

return 0;
}

