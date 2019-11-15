/*****************************************************
* Find height of binary tree
* November 14, 2019
******************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef int    data_t;
typedef struct node_struct node_t;
struct node_struct 
{
    data_t   data;
    node_t * left;
    node_t * right;
} 

node_t * insert ( node_t * root, data_t data )
{
    if (root == NULL)
    {
        node_t * newNode = (node_t *) malloc(sizeof(node_t));
        newNode->data  = data;
        newNode->left  = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void printTree ( node_t * root )
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    printf("%d", root->data);
    printTree(root->right);
}

int main ( void ) 
{
    node_t binaryTree = NULL;
    binaryTree = insert(binaryTree, 5);

    for (int i = 0; i < 10; i += 2)
    {
        insert(binaryTree, i);
    }

    printTree(binaryTree);
}