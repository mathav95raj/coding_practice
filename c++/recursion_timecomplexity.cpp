#include <iostream>
using namespace std;
int fun(int n){
        cout<<"working on fun("<<n<<")"<<endl;
        if(n<=1)
        return 0;
        fun(n/2);
        fun(n/2);
        cout<<"done! fun("<<n<<")"<<endl;
    }
int main(){
    fun(10);
}