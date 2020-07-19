#include <bits/stdc++.h>
using namespace std;


//insert and emplace same for primitive types like int
//emplace cre
class A
{
    public:
    int x;
    A(int x = 0): x{x} {cout<<"construct"<<endl;};
    A(const A& rhs)
    {
        x = rhs.x;
        cout<<"copy"<<endl;
    }
};
bool operator < (const A& lhs, const A& rhs)
{
    return lhs.x < rhs.x;
}
int main()
{
    set<A> stuff;
    stuff.insert(A(1)); //constructs a temporary object and then copies
    stuff.emplace(2);//only contruct, just pass the parameter
    return 0;
}