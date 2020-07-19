#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int a[3] = {1,2,3};
    int b[2][3]={ {4 , 5, 6 } ,
                  { 7 ,8 , 9 } } ;
 
    int (*p)[3] = b; 
    //int *p = b; //wrong. b returns a pointer to array of 3 integers
    cout<<a<<endl<<*(a)<<endl; //address of 1 and 1
    cout<<b<<endl<<*(b)<<endl; //both return address of first number
    cout<<b+1<<endl;//address of first element of next block of 3 elements
    cout<<*(*(b+1)+2);//9

}