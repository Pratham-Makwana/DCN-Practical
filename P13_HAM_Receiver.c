#include<stdio.h>
#include<string.h>
#include<fcntl.h>
void main()
{
	
	char data1[13];
	char p1[14],p2[14],p3[14],p4[14];
	
	int p11,p22,p44,p88,pos,val;
	int pa1,pa2,pa4,pa8;
	int par1,par2,par4,par8;
	int i,cnt=0;
	int fd;
	char * myfifo="myfifo";
	mkfifo(myfifo,0666);
	fd=open(myfifo,O_RDONLY);
	read(fd,data1,13);

	printf("\n after inserteing parity bit data is \n %s \n",data1);
	par1=data1[0]-'0';
	par2=data1[1]-'0';
	par4=data1[3]-'0';
	par8=data1[7]-'0';
	
	int l=strlen(data1);
	data1[l]='\0';
	printf(" \n Enter The Postion You Want to Change Bit :");
	scanf("%d",&pos);
	printf("\n Enter the bit:");
	scanf("%d",&val);

	data1[pos]=val+'0';
	printf(" \n After changing bit value \n %s \n",data1);	


	
	int cnt1;
	cnt1=-1;
	p11=0;
	for(i=0;i<strlen(data1);i++)
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
	
	pos=0;
	if(pa1!=0)
	{
	 pos=1;
	}
	if(pa2!=0)
	{
	 pos=pos+2;
	}
	if(pa4!=0)
	{
	  pos=pos+4;
	}
	if(pa8!=0)
	{
	  pos=pos+8;
	}
	
	printf("\n after inserteing parity bit data is \n %s \n",data1);
	if(pos==0)
	{
		printf("\n There is no errror \n");
	}	
	else
	{
		printf("\n You have error at position %d \n",pos-1);
	
	}
}
