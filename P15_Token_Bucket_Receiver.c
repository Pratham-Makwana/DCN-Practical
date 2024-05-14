#include<fcntl.h>
#include<stdio.h>
#define MAX 5
void main()
{
		int data[MAX];
		int fd;
		int i;		
		char * myfifo="myfifo";
		mkfifo(myfifo,0666);
		fd=open(myfifo,O_RDONLY);
		read(fd,data,sizeof(data));
	
		printf("\n\n Data are received \n \n");
		for(i=0;i<MAX;i++)
		{
		   printf("%d",data[i]);
		}
		printf("\n");
		close(fd);

}

