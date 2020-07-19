
#include<iostream>
using namespace std;
class arraywrapper
{
    public:
    int array[5];
    void modify(arraywrapper a)
    {
        a.array[0] = 2;
        for(int i = 0; i <5;i++)
        cout<<a.array[i]<<'\t';
        cout<<endl;
    }

};
int main()
{
    arraywrapper a;
    for(int i = 0; i<5;i++)
        a.array[i] = i;
    a.modify(a); //an object passed by value invokes copy constructor and creates deep copy, deep copy is when separate memory locations are created
    for(int i = 0; i <5;i++)
    {
    cout<<a.array[i]<<'\t';
    }
    cout<<endl;
    return 0;
}