#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long gcd(long long n, long long m)
{
    if(m == 0)
        return n;
    
    gcd(m, n%m);
}
int egcd(int n, int m, int &x, int &y)
{
    if(m==0)
    {
        x = 1;
        y = 0;
        return n;
    }

    int x1, y1;
    int egcdv = egcd(m, n%m, x1, y1);

    y1 = -floor(n/m)*y1 + x1;
    x1 = y1;
    return egcdv;
}
void printv(vector<int> const &a)
{
    for(auto i = a.rbegin(); i!=a.rend(); ++i)
    {
        cout<<*i;
    }
    cout<<endl;
}
vector<int> long_fact(int n)
{
    vector<int> fact = {1};
    int res, carry{0};
    for(int k{2}; k<=n; ++k)
    {
    for(int i{0}; i<fact.size(); ++i)
    {
        res = fact.at(i) * k + carry;
        carry = res/10;
        fact.at(i) = res % 10;
    }
    while(carry)
    {
            fact.push_back(carry%10); //for putting two digit carries at the end in separate positions
            carry = carry/10;
    }
    // printv(fact);
    }
    return fact;
}
long long factmodm(int n, int m)
{
    long long ans = 1;
    while(n>=1)
    {
        ans = ans*(n%m);
        // cout<<ans<<endl;
        n--;
    }
    return ans;
}
long long trail(int n)
{
    long long fact = 1;
    while(n!=1)
    {
        fact = fact*n;
        n--;
    }
    cout<<fact<<endl;
    long long cnt = 0;
    while(fact%10 == 0)
    {
        cnt++;
        // cout<<fact<<endl;
        fact = fact/10;
        
    }
    return cnt;
}
int main()
{
    // cout<<gcd(8, 5);
    vector<int> a;
    // cout<<trail(18)<<endl;
    a = long_fact(100);
    printv(a);
    cout<<factmodm(5, 119);
    // printv(a);
}