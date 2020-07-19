#include <iostream>
#include <stdlib.h>
using namespace std;
int* add(int *a, int *b)
{
    int *c = new int;//good practice to allocate return pointer variable in heap or global, as stack will get overwritten if any other subsequent functions called
    
}
int main()
{
    int *p;
    //call to malloc will give a void pointer to chunk of memory of size specified
    p = (int*)malloc(sizeof(int));
    p = (int*)realloc(p, 2*sizeof(int));
    *p = 20;
    free(p);
    p = (int*)malloc(sizeof(int));
    *p = 40; //now pointer points to this
    //if line 10 is not there 20 is still in heap because we havent dealloc it
    p = new int[20];
    delete[] p;
     
}