/*****************************************************
* Reverse String
* November 13, 2019
******************************************************/

#include <stdio.h>
#include <stdlib.h>


void reverseString ( char * string, int length )
{
    char buffer;
    int leftIndex = 0;
    int rightIndex = length - 1;
    while (leftIndex < rightIndex)
    {
        buffer = string[leftIndex];
        string[leftIndex] = string[rightIndex];
        string[rightIndex] = buffer;
        leftIndex  ++;
        rightIndex --;
    }
}

int main ( void ) 
{
    char string[] = "Hello world!";
    reverseString(string, 12);
    printf("%s\n", string);
    return 0;
}