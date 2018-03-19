#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "type.h"


int  hash_value(char *tmp)
{
	int len=0,i=0;
	long long hv=0;

	len=strlen(tmp);

	for(i=0;i<len;i++)
	{
		if(tmp[i]>=0)	{hv=(hv<<3)+tmp[i];}
		else		{hv=(hv<<3)-tmp[i];}
	}

	hv=hv%MAX_HV;

	if(hv<0){hv=-hv;}

	return hv;
}
