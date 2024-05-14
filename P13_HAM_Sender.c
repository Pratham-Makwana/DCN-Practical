#include<stdio.h>
#include<string.h>
#include<fcntl.h>
void main()
{
	char *data="11010011";
	
	char data1[50];
	char p1[14],p2[14],p3[14],p4[14];
	int pos,val;
	int l=strlen(data);
	int p11,p22,p44,p88;
	int pa1,pa2,pa4,pa8;
	int i,cnt=0;
	int fd,fd1;
	data1[0]='n';
	data1[1]='n';
	data1[3]='n';
	data1[7]='n';

	for(i=0;i<l;i++)
	{
	     if(data1[cnt]=='n')
	     {	
		cnt++;
		i--;
	     }
	     else
	     {
		data1[cnt]=data[i];
		cnt++;
	     }
	}
	data1[cnt]='\0';

	printf("data1 is %s \n",data1);
// calculateion parity bit p1;
	int cnt1;
	cnt1=-1;
	p11=0;
	for(i=0;i<=strlen(data1);i++)
	{ 
	    if(p11==1)
	    {
		p11=0;
		i=i+1;
		
	    }
	    	cnt1++;
	     	p11++;
		p1[cnt1]=data1[i];
	}
	p1[cnt1]='\0';
	
	
	printf("\n data of p1 is %s ",p1);

	
	// calculation parity bit p22;

	cnt1=-1;
	p22=0;
	for(i=1;i<=strlen(data1);i++)
	{ 
	    if(p22==2)
	    {
		p22=0;
		i=i+2;
		
	    }
	    
	    	cnt1++;
	     	p22++;
		p2[cnt1]=data1[i];
	}
	p2[cnt1]='\0';
	
	printf("\n data of p2 is %s \n",p2);
	
	// calculation of parity bit p3

	cnt1=-1;
	p44=0;
	for(i=3;i<=strlen(data1);i++)
	{ 
	    if(p44==4)
	    {
		p44=0;
		i=i+4;
		
	    }
	    
	    	cnt1++;
	     	p44++;
		p3[cnt1]=data1[i];
	}
	p3[cnt1]='\0';
	
	printf(" data of p4 is %s \n",p3);
	
	// calculation of parity bit 4

	cnt1=-1;
	 p88=0;
	for(i=7;i<=strlen(data1);i++)
	{ 
	    if(p88==8)
	    {
		p88=0;
		i=i+8;
		
	    }
	    
	    	cnt1++;
	     	p88++;
		p4[cnt1]=data1[i];
	}
	p4[cnt1]='\0';
	
	printf(" data of p8 is %s \n",p4);


	// calculation of p1
	cnt1=0;
	for(i=0;i<strlen(p1);i++)
	{
	   if(p1[i]=='1')
	   {
		cnt1++;
	   }
	}
	if(cnt1%2==0)
	{
	   pa1=0;
	}
	else
	{
	  pa1=1;
	}

	// calculation of p2
	cnt1=0;
	for(i=0;i<strlen(p2);i++)
	{
	   if(p2[i]=='1')
	   {
		cnt1++;
	   }
	}
	if(cnt1%2==0)
	{
	   pa2=0;
	}
	else
	{
	  pa2=1;
	}

	// calculation of p4
	cnt1=0;
	for(i=0;i<strlen(p3);i++)
	{
	   if(p3[i]=='1')
	   {
		cnt1++;
	   }
	}
	if(cnt1%2==0)
	{
	   pa4=0;
	}
	else
	{
	  pa4=1;
	}
	
	// calculaiton of p8
	cnt1=0;
	for(i=0;i<strlen(p4);i++)
	{
	   if(p4[i]=='1')
	   {
		cnt1++;
	   }
	}
	if(cnt1%2==0)
	{
	   pa8=0;
	}
	else
	{
	  pa8=1;
	}
	printf("%d %d %d %d",pa1, pa2,pa4,pa8);
	data1[0]=pa1+'0';
	data1[1]=pa2+'0';
	data1[3]=pa4+'0';
	data1[7]=pa8+'0';
	
	printf("\n after inserteing parity bit data is \n %s \n",data1);
	
	char * myfifo="myfifo";
	mkfifo(myfifo,0666);
	fd=open(myfifo,O_WRONLY);
	write(fd,data1,strlen(data1));
	close(fd);
	unlink(myfifo);	
	
}
