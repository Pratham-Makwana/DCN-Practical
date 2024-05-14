#include<stdio.h>

/*
    Enter 7 bits of data: 1
    0
    1
    0
    1
    0
    1
    VRC bit is: 0

*/
int main(){
    int data[10], vrc=0;
    
    //Input data
    printf("Enter 7 bits of data: ");
    for (int i = 0; i < 7; i++)
    {
        scanf("%d",&data[i]);
    }
    
    // calculate VRC
    for (int i = 0; i < 7; i++)
    {
        vrc ^= data[i];
    }

    // Display VRC
    printf("VRC bit is: %d\n",vrc);
    
    return 0;
}