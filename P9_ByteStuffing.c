#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
 //for exa: dlestkhelldleo PUdleetx
void main()
{
	char str[1024];
	char str1[1024];
	printf("Enter the String:");
	scanf("%s",str);
	
	int i,j;
	char *start="dlestx";
	char *end="dleetx"; 
	char *startend="dle";

	int l=strlen(str);
	int l1=strlen(start);
	int incharpos;
	char inchar;
	printf("Your String is : %s ",str);
	printf("\n");
	start:
		printf("Enter the  position that you want to stuff character:");
		scanf("%d",&incharpos);
	if(incharpos>=l)
	{
	  printf("Sorry your enter position is grater than lenght of Input String \n");
	  goto start;
	}
	printf("Enter the Character that you want to stuff:");
	scanf(" %c",&inchar);
	int count=0;
	for(i=0;i<l1;i++)
	{
	  str1[i]=start[i];
	  count++;
	}
	for(i=0;i<l;i++)
	{
		
	   if(i==incharpos)
 	   {

		for(j=0;j<strlen(startend);j++)
		{
			str1[count]=startend[j];
			count++;
		}
		str1[count]=inchar;
		count++;
		for(j=0;j<strlen(startend);j++)
		{
			str1[count]=startend[j];
			count++;
		}
	 	
	   }		
	   str1[count]=str[i];  
	  count++;  
	  
	}
	
	for(j=0;j<l1;j++)
	{
	  str1[count]=end[j];
	  count++;
	}
	
	printf("%s",str1);
	
		
	printf("\n");

}

