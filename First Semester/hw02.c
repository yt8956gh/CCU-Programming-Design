#include<stdio.h>
main()
{
		int total=0,line=0,vowel=0,num=0,c;
		char vowelapha[10]={'a','e','i','o','u','A','E','I','O','U'};
		while((c=getchar())!=EOF)
			{
				total++;
			
				if(c=='\n')
				{line++;}
			
				int i;
				for(i=0;i<10;i++)
				{
					if(c==vowelapha[i])
					{vowel++;}
				}
			
				if(c>='0'&&c<='9')//compare with ascii code
				{num++;}

			}//while

		printf("Total characters= %d\nTotal rows= %d\nNumber= %d\nVowel= %d\n",total,line,num,vowel);
		
		
		
		
		return 0;
		}
