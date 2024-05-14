#include<stdio.h>
#include<string.h>



void main()
{
	char str[100];	
	char data1[100],quot[100],key[3],key1[100],rem[30],div[30];
	char data[100];
	printf("Enter key");
	gets(div);
	printf("Enter data");
	gets(data);
	int i,j,divlen,str1len,total;
	int cnt=0;
	divlen=strlen(div);
	int dlen=strlen(data);
	//printf("%d",divlen);
	strcpy(key1,div);
	
	for(i=0;i<divlen-1;i++)
	{
	  data[dlen+i]='0';
	}
	data[dlen+divlen-1]='\0';
	//printf("%s",data);
	cnt=0;
	for(i=0;i<divlen;i++)
	{
	    data1[cnt]=data[i];
	    cnt++;
	}
	data1[cnt]='\0';
	
	for(i=0;i<dlen;i++)
	{
	   	quot[i]=data1[0];
		
		if(quot[i]=='0')
		{
		   for(j=0;j<divlen;j++){
			div[j]='0';
		   }
		}
		else
		{
		   for(j=0;j<divlen;j++)
		   {
			div[j]=key1[j];
		   }
		}
		cnt=0;
		for(j=1;j<divlen;j++)
		{
		    if(data1[j]==div[j])
		    {
			rem[cnt]='0';
		    } 
		    else
		    {
			rem[cnt]='1';
		    }
		    cnt++;
		}
		rem[cnt]=data[i+divlen];
		printf("rem is %s",rem);
		strcpy(data1,rem);
	}
	strcpy(rem,data1);
	
	printf("\n quotent is");
	for(i=0;i<dlen;i++)
	{
	  printf("%c",quot[i]);
	}

	printf("Reminder is ");
	for(i=0;i<divlen-1;i++)
	{
	  printf("%c",rem[i]);
	}
	printf("\n data is ");
	for(i=0;i<dlen;i++)
	{
	  printf("%c",data[i]);
	}
	for(i=0;i<divlen-1;i++)
	{
	  printf("%c",rem[i]);
	}
}
