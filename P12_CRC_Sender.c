#include<stdio.h>
#include<string.h>
#include<fcntl.h>

void main()
{
	char data[100],temp[50],rem[50],quot[50],key[50],key1[50];
	int i,j,cnt,keylen,datalen;

	printf("\n Enter Data:");
	gets(data);

	printf("\n Enter key:");
	gets(key);
	
	printf("\n Original Data is : " );
	printf("%s",data);

	printf("\n");
	keylen=strlen(key);
	datalen=strlen(data);
	strcpy(key1,key);

	cnt=datalen;
	for(i=0;i<keylen-1;i++)
	{
	    data[cnt]='0';
	     cnt++;
	}	
	data[cnt]='\0';

	printf("\n Data with key is : " );	
	printf("%s",data);
	printf("\n");

	cnt=0;
	for(i=0;i<keylen;i++)
	{
	    temp[cnt]=data[i];
	    cnt++;	
	}
	temp[cnt]='\0';
	
	printf("%s",temp);
	
	for(i=0;i<datalen;i++)
	{
		quot[i]=temp[0];		
		if(quot[i]=='0')
		{
		   for(j=0;j<keylen;j++)
		   {
			key[j]='0';
		    }
		}
		else
		{		
		    for(j=0;j<keylen;j++)
		    {
			key[j]=key1[j];
		    }
		}
		cnt=0;
		for(j=1;j<keylen;j++)
		{
			if(temp[j]==key[j])
			{
			    rem[cnt]='0';
			     
			}
			else
			{
				rem[cnt]='1';
			}
			cnt++;
		}
		rem[cnt]=data[i+keylen];
		cnt++;
		rem[cnt]='\0';
		printf("Reminder is :%s" ,rem);
		strcpy(temp,rem);
		
	}
	strcpy(rem,temp);
}
