import math
import os
import random
import re
import sys


def BITAdd(BIT, index):
    '''
        @brief   Binary Index Tree Add function - adds 1 to BIT[index], and updates other values 
        @param   BIT   - Binary Index Tree to add to
        @param   index - index at which to increment value
        @retval  None
    '''

    while index < len(BIT):
        BIT[index] += 1
        index += (index & (-index))


def BITGet(BIT, index):
    '''
        @brief   Binary Index Tree Get function - gets sum of BIT[index:-1] 
        @param   BIT   - Binary Index Tree to get from
        @param   index - index from which to get sum
        @retval  Sum of BIT[index:-1]
    '''

    sum = 0
    print(BIT, index, end=" ")

    while index > 0:
        sum += BIT[index]
        index -= (index & (-index))
    print(sum)
    return sum

def insertionSort(arr):
    '''
        @brief   Returns number of shifts neccessary for insertion sort
        @param   arr - input array to be sorted using insertion sort
        @retval  shiftCount - number of shifts

        My solution loops through the array backwards and uses a Binary 
        Index Tree to find the number of values smaller than the current
        value before it
    '''

    shiftCount = 0

    maxValueInArray = max(arr)

    ''' Make Binary Index Tree that has maxValueInArray + 1 indices - so BIT can be indexed
        according to value - ex. values[max(arr)] should not be out of range
    '''
    values = [0] * (maxValueInArray + 1)
    # Loop through array backwards
    for i in range(len(arr)-1, -1, -1):
        # Add number of values that are less than arr[i] from arr[i:-1] to shiftCount
        shiftCount += BITGet(values, arr[i])
        # Add 1 to values[i], and update rest of the indices
        BITAdd(values, arr[i])
    return shiftCount



arr = [4,2,3,1]
print(insertionSort(arr))
