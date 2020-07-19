#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void print(const forward_list<int> &A)
{
    for(auto x : A)
    {
        cout<<x<<" "; 
    }
    cout<<endl;
}
int main()
{
    forward_list<int> A{1,5,4,6};
    forward_list<int> B(A);
    forward_list<int> C{1,2,3,2};
    // copy(A.begin(), A.end(), B.begin()); // will not work when B is empty
    B.reverse(); //reverses in place //6,4,5,1

    copy_if(A.begin(), A.end(), 
    B.begin(), [](int i){return i%2!=0;}); //1,5,5,1 (first two elements copied) copies from A to B
    
    // print(A);
    // print(B);
    A.sort();
    B.sort();
    // A.merge(B); 
    print(A);
    print(B);
    B.splice_after(B.begin(), A); // 1, A, 1, 5, 5
    print(B);
    cout<<distance(A.begin(), A.end());
    C.unique();
    print(C); //will not work on non adjacent duplicates
    
    C.remove_if([] (int n)  //removes elements greater than 2
    {
        return n>2;
    });


    print(C);
    C.resize(10);
    print(C);




}