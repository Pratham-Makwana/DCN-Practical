#include<stdio.h>
#include<string.h>
#include<fcntl.h>

void main()
{
     char str[100],str1[10][10],pr[10];
     char data[100];
     gets(str);
     int i,j,cnt,cnt1,total,fd;
	cnt=0,cnt1=0,total=0;

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
	}
	else
	{
	  pr[cnt1]='1';
	}
	total=0;
	cnt1++;

    }
  pr[cnt1]='\0';
  printf("\n Parity Bit are:  %s \n",pr);
  cnt1=0;
  for(i=0;i<strlen(str);i++)
  {
	data[cnt1]=str[i];
	cnt1++;
  }
  for(i=0;i<strlen(pr);i++)
  {
	data[cnt1]=pr[i];
	cnt1++;
  }
   data[cnt1]='\0';
   printf("%s",data);
   mkfifo("vivek",0666);
   fd=open("vivek",O_WRONLY);
   write(fd,data,sizeof(data));
   close(fd);
}

