#include<stdio.h>
main()
{
		int a=1;
		while(a)
		{   
				double org=0;
				printf("Input: ");
				scanf("%lf",&org);
					if(org==0)
					{
						printf("END!\n");
						a=0;
					}
					else
					{
						double aft=org*30.48;
						printf("Output: %.6f\n",aft);
						printf("\n");
					}
		}
return 0;
}
