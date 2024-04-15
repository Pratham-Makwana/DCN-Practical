#include<stdio.h>
#include<string.h>

void main()
{

	int n;
	char buff[1024];
	int flag[2];
	char *data="hello how are you";
	pipe(flag);

	write(flag[1],data,strlen(data));

	n=read(flag[0],buff,1024);
	int i;

	for(i=0;i<strlen(buff);i++)
	{
		printf("%c",buff[i]);

	}
	printf("\n");

}
