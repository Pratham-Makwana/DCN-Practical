#include<stdio.h>
#include<string.h>

int main()
{
	int i=0,j=0,l=0;
	char data[1024];
	char frame[1024]="";
	printf("\n Enter the Bit Stream : ");
	scanf("%s",data);

int size = strlen(data);
for(i,j;i<size;i++,j++)
{
	if(i==0 || i%4==0)
	{
		frame[j]="#";
		j++;	
	}
	frame[j]=data[i];
}

for(l;l<strlen(frame);l++)
{
	printf("%c",frame[l]);
}

return 0;
}



