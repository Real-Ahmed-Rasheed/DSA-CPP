#include <bits/stdc++.h> 
#include <algorithm> 
class NStack
{
public:
    int* arr;
    int* next;
    int* top;
    int freeSpace;
    int noOfStacks;
    int sizeOfArray;
    NStack(int N, int S)
    {
        noOfStacks=N;
        sizeOfArray=S;
        freeSpace = 0;
        arr = new int[sizeOfArray];
        top = new int[noOfStacks];
        next = new int[sizeOfArray];

        //intially the tops will be -1(empty stack)
        for(int i=0; i<noOfStacks; i++){
            top[i] =-1;
        }

        //next will intially contain nextFreeSpace index
        for(int i=0; i<sizeOfArray; i++){
            if(i +1 == sizeOfArray){
            next[i] = -1;
            } else{
            next[i] = i+1;
            }
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        // last element of next array will be -1
        if(freeSpace == -1){
            return false;
        }
        //get freeSpot
        int index = freeSpace;

        //update freeSpot
        freeSpace = next[index];

        //store
        arr[index] = x;

        //update next
        //m-1 for 0 based indexing
        next[index] = top[m-1];

        //update top
        top[m-1] = index;
        return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // is stack is already empty 
       if(top[m-1] == -1){
           return -1;
       }
       // store the elements index, top is pointing to
       int index = top[m-1];

       //update top to previous element
       top[m-1] = next[index];

       //clean next[i] and point to next freeSpot
       next[index] = freeSpace;

       //point freeSpot to deleted elemnts index
       freeSpace = index;
       return arr[index];
    }
};