#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#define MAX 5

struct stack
{
   int a[MAX];
   int top;
}s;

void push();
void disp();
void pop();
int main()
{
	int ch;
	s.top=-1;
	char ans;
	do
	{
	printf("Select Your Choice:");
	printf("\n 1.Enter Data \n 2.Send Data \n 3.Display \n 4.Exit");
	printf("\n Enter Your Choice:");
	scanf("%d",&ch);

	printf("%d",ch);
	
	   switch(ch)
	   {
	       case 1:
		    push();
		    break;
	       case 2:
		    pop();
		    break;
	       case 3:
		    disp();
		    break;
		case 4:
		    break;
	   }	
	   printf("\n Do you want to continue..y/Y");
	   scanf(" %c",&ans);
	}while(ans=='y' || ans=='Y');
	return 0;
}
void push()
{
  int num;
   if(s.top==(MAX-1))
   {
	printf("\n ************Bucket is full*************\n");
   }
   else
   {
	printf("\n Enter the bit:");
	scanf("%d",&num);
	s.top=s.top+1;
	s.a[s.top]=num;

   }
}
void pop()
{
   if(s.top==-1)
   {
	printf("\n Bucket is empty \n");
   }
   else
   {
	if(s.top==MAX-1)
	{
		int fd;
		char * myfifo="myfifo";
		mkfifo(myfifo,0666);
		fd=open(myfifo,O_WRONLY);
		write(fd,s.a,sizeof(s.a));
		close(fd);
		unlink(myfifo);
		s.top=-1;
	}
	else
	{
	  printf("\n You can not send the data until bucket is full \n");
	}
      
   }
}
void disp()
{
   	 int i;
	for(i=0;i<=s.top;i++)
	{
	 printf("\n");
	  printf("a[%d]=>",i);
	  printf("%d",s.a[i]);
	 
	}
}
