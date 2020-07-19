#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A = 5;
    vector<int> arr;
    int key1 = 1, key2;
    arr.push_back(1);
    while(arr.size() != A+1)
    {
    arr.resize(arr.size() + 1);
    for(int i = 1; i <  arr.size()-1 ; ++i)
    {
        key2 = arr[i];
        arr[i] = key1  + key2;
        key1 = key2;
    }
    arr[arr.size() - 1] = 1;
    for(int i = 0; i<arr.size(); ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    }
}