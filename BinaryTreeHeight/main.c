/*****************************************************
* Find height of binary tree
* November 14, 2019
******************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct node_struct node_t;;
struct node_struct 
{
    int      data;
    node_t * left;
    node_t * right;
} 