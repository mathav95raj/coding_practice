#include <iostream>
using namespace std;
int main()
{
    int a[] = {2, 3, 3, 4}, b[] = {2, 3, 3, 3, 4, 4, 4};
    int n1 = sizeof(a)/ sizeof(int);
    int n2 =  sizeof(b)/ sizeof(int);
    int i = 0, j = 0;
    while(i < n1 && j< n2)
    {
        if( i> 0 && a[i] == a[i-1]) {i++; continue; }
        if (j> 0 && b[j] == b[j-1] ) {j++;continue; }
        else
        {
            if(a[i] <= b[j]) cout << a[i++]<<" ";
            else if(a[i] > b[j]) cout << b[j++]<<" ";
            else { cout<<a[i++]<<" "; j++; }
        }
    }
    while(i<n1 && a[i] != a[i-1]) cout<<a[i++]<<" ";
    while(j<n2 && b[j] != b[j-1]) cout<<b[j++]<<" ";      
}

