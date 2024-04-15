//DCN LAB Program: Write a C Program to implement BitCount Method.

#include "stdio.h"
#include "string.h"

int main()
{
    unsigned int cnt0=0, cnt1=0, iCnt=0, size;
    char stream[256];
    
printf("Enter BitStream:");
scanf("%s",stream);
size = strlen(stream);
for(int i=0; i<size; i++)
{
   if(stream[i] == '1')
   {
        cnt1++;
   }
   else if(stream[i] == '0')
   {
        cnt0++;
   }
   else
   {
        iCnt++;
   }
}

printf("\n No. of Bits: %d", size);
printf("\n No. of 1s Bits: %d", cnt1);
printf("\n No. of 0s Bits: %d", cnt0);
printf("\n No. of Invalid Bits: %d", iCnt);

return 0;
}

