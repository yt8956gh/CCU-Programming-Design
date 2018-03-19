#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>



void insertion(int *sort,int n)
{
	int i=0,next=0,tmp=0;

	for(i=1;i<n;i++)//第一個值視為已排序
	{
		tmp=sort[i];
		next=i;//未排序的第一個值
		
		while((next>=1)&&(sort[next-1]>tmp))
		{
			sort[next]=sort[next-1];
			next--;				
		}	
		sort[next]=tmp;//此時的NEXT已經往前挪一位 也就是兩個重複值（next & next-1）的前一個
				
	}

}



void selection(int *sort,int n)
{
	int i=0,j=0,tmp=0,st=0;//st存最小數的編號
	
	for(i=0;i<n;i++)
	{
		st=i;
		
		for(j=(i+1);j<n;j++)//找最小值sort[st]  @注意j=(i+1)
		{
			
			if(sort[st]>sort[j])
			{	
				st=j;
			}
		}
		
		tmp=sort[i];//交換最小值和未排序中的首項
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
		printf("%d			%d\n",var[i],number[i]);
	}

}



int cmp_int(const void *x,const void *y)
{
	return (*(int*)x-*(int*)y);
}








int main()
{

	int i=0,var[1000000]={0},sorted[1000000]={0},j=0,total=1000;
    double times[5][4]={0.0};
	clock_t t1=0,t2=0;
	srand(time(NULL));

	for(i=0;i<1000000;i++)
	{
		var[i]=rand();
	}
	
/*	

    for(i=0;i<5;i++)
    {
        memcpy(sorted,var,sizeof(sorted));           
        switch(i)
	    {
				case 0:	
                    printf("Isertion Sort\n");
                    t1=clock();                    
                    insertion(sorted,1000); 
                    t2=clock();
                    break;
				case 1:	
                    printf("Selection Sort\n");
                    t1=clock();   
            	    selection(sorted,1000);
                    t2=clock();
                    break;
				case 2:	
                    printf("Bubble Sort\n");
                    t1=clock();   
            	    bubble(sorted,1000);
                    t2=clock();
                    break;
				case 3:	
                    printf("Merge Sort\n");
                    t1=clock();   
        		    qsort((int*)sorted,1000,sizeof(int),cmp_int);
                    t2=clock();
                    break;
				case 4:	
                    printf("Quick Sort\n");
                    t1=clock();   
		            mergesort((int*)sorted,1000,sizeof(int),cmp_int);
                    t2=clock();
                    break;
	    }

        print_number(var,sorted);

        times[i][0]=((t2-t1)/(double)(CLOCKS_PER_SEC));
    }

*/



    for(j=0;j<4;j++)
    {      

            for(i=0;i<5;i++)
            {
                    memcpy(sorted,var,sizeof(sorted));           
                    switch(i)
	                {
				            case 0:	
                                t1=clock();                    
                                insertion(sorted,total); 
                                t2=clock();
                                break;
				            case 1:	
                                t1=clock();   
                        	    selection(sorted,total);
                                t2=clock();
                                break;
				            case 2:	
                                t1=clock();   
                        	    bubble(sorted,total);
                                t2=clock();
                                break;
				            case 3:	
                                t1=clock();   
                    		    qsort((int*)sorted,total,sizeof(int),cmp_int);
                                t2=clock();
                                break;
				            case 4:	
                                t1=clock();   
		                        mergesort((int*)sorted,total,sizeof(int),cmp_int);
                                t2=clock();
                                break;
	                }

                   if(j==0) {print_number(var,sorted);}

                   times[i][j]=((t2-t1)/(double)(CLOCKS_PER_SEC));
            }

	    total=total*10;
    }



    printf("1000     10000       100000      1000000\n");

    for(i=0;i<4;i++)
    {    
       printf("%lf      %lf      %lf      %lf\n",times[i][0],times[i][1],times[i][2],times[i][3]);

    }




return 0;
}

