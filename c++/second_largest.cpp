#include <iostream>
using namespace std;
int main()
{
    int arr[6] = {12, 35, 1, 10, 34, 1 };
    int max1 = arr[0], max2 = arr[0];
    for(int i = 1; i<5; i++){
        if (arr[i] > max1){
            max2 = max1;
            max1 = arr[i]; 
        }     
        else if (arr[i] > max2 || max1 == max2)
            max2 = arr[i];   
    }
    cout<<max1;
    cout<<max2;

}