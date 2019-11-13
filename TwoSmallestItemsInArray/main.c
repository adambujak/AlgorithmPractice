/*****************************************************
* Find two smallest items in array
* November 13, 2019
******************************************************/

#include <stdio.h>
#include <stdlib.h>



int * findTwoSmallestItems ( int * array, int length )
{
    int * twoSmallestItems = (int *) malloc(2*sizeof(int));
    
    twoSmallestItems[0] = array[0];
    twoSmallestItems[1] = array[0];

    for (int i = 0; i < length; i++)
    {
        if (array[i] < twoSmallestItems[0])
        {
            twoSmallestItems[0] = array[i];
        }
        else if (array[i] < twoSmallestItems[1])
        {
            twoSmallestItems[1] = array[i];
        }
    }
    return twoSmallestItems;
}

void printArray ( int * array, int length )
{
    printf("[");
    int i = 0;
    for (i = 0; i < length - 1; i++)
    {
        printf("%d,", array[i]);
    }
    printf("%d]\n", array[i]);
}

int main ( void ) 
{
    int array[9]={67,89,90,11,65,4,999,45,12};
    printArray(findTwoSmallestItems(array, 9), 2);
    return 0;
}