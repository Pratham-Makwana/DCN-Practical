#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
void main()
{
	
	char bsize[MAX];
	char data[1024];
	printf("Enter the data that you want to sent: " );
	gets(data);
	int l=strlen(data);
	int i,j;
	int cnt=0;
	for(i=0;i<MAX;i++)
	{
	   bsize[cnt]=data[i];
	   cnt++;
	}
	
	
	printf("\n\n Following data are transmitted succ: \n\n");
	int l1=strlen(bsize);
	
	for(i=0;i<l1;i++)
	{
	  
	   printf("%c",bsize[i]);
	  fflush(stdout);
	  sleep(1);
	  
	}

	if(l<=MAX)
	{
	  printf("\n \n There is no data are lost \n \n");
	}
	else{
		printf("\n\n Following data are lost \n\n");
		for(i=l1;i<l;i++)
		{
		  
		  printf("%c",data[i]);
	 	  fflush(stdout);
		  sleep(1);
		}
	}

	printf("\n ");

}

