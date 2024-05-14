#include<stdio.h>
#include<string.h>
#include<fcntl.h>

void main()
{
     char str[50],str1[10][10],pr[10];
     int i,j,cnt,cnt1,total,fd,flag=0;
	cnt=0,cnt1=0,total=0;

	char * str="111010100000";
    fd=open("vivek",O_RDONLY);
	read(fd,str,sizeof(str));


    for(i=0;i<strlen(str);i++)
    {
	  for(j=0;j<4;j++)
	  {
		str1[cnt][j]=str[i];
	        i++;
	  }
	  str1[cnt][j]='\0';
	  i--;
	  cnt++;
    }

    for(i=0;i<cnt;i++)
    {
	  for(j=0;j<strlen(str1[i]);j++)
	  {
		printf("%c",str1[i][j]);
	  }
	printf("\n");
    }

   for(i=0;i<4;i++)
   {
	for(j=0;j<cnt;j++)
	{

	   total=total+str1[j][i]-'0';
	}
	if(total%2==0)
	{
	   pr[cnt1]='0';
	   flag=0;
	}
	else
	{
	  pr[cnt1]='1';
	  flag=1;
	}
	total=0;
	cnt1++;

    }
    pr[cnt1]='\0';
    printf("%s",pr);
    if(flag==0)
    {
	printf("\n there is no error \n");
    }
    else
    {
	printf("\n ther is error");
    }
}
