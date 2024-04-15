#include<stdio.h>
#include<string.h>
#include<unistd.h>
//#include<sys/syscall.h>
#include<fcntl.h>
int  main()
{
	printf("\n Enter the Message That You want to sent.....:)\n");
	char str[1024];
	char smsg[1024];
	char readData[1024];
	scanf("%s",str);
	int msglen=strlen(str);
	int l=4;
	int i,j;
	int count=0;
	//int fds[2];
	for(i=0;i<msglen;i++)
	{
		for(j=0;j<l;j++)
		{
		  smsg[count]=str[i];
		  i++;
		  count++;
		}
		i--;
		smsg[count]='#';
		count++;
	}

	for(i=0;i<strlen(smsg);i++)
	{
	  printf("%c",smsg[i]);
	}

	int fd=creat("test1.txt",777);
	
	if(fd<0)
	{
	  printf("file already created");
	}
	else
	{
		write(fd,smsg,strlen(smsg));
		
		read(fd,readData,sizeof(smsg));
	}

	return 0;
}
