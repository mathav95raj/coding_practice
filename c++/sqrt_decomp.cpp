#include <bits/stdc++.h>
using namespace std;

int amin(long long l, long long r, long long blk, vector<long long> &a)
{
    long long lb = l/blk;
    long long rb = r/blk;
    long long mn = INT_MAX;

    if(lb == rb)
    {
        for(auto i = l; i<r; ++i)
        {
            mn = min(mn, a[i]);
        }
    }

    else
    {
        for(auto i = l; i< lb*blk+1; i++)
        mn = min(mn, a[i]);

        for(auto i = l; i< lb*blk+1; i++)
        mn = min(mn, a[i]);

        for(auto i = l; i< lb*blk+1; i++)
        mn = min(mn, a[i]);
    }
    

}
int main()
{
    vector<long long> a,f;
    long long n, blk, mf = INT16_MAX;
    cin>>n;
    a.reserve(n+5);
    a = {n,0};
    for(auto x: a)
    {
        cin>>x;
    }
    long long l, r, mn;
    blk = sqrt(n);
    f.reserve(blk*2);
    for(auto i = a.begin(); i<a.end(); )
    {
        if(i - a.begin() > blk*blk)
        {
            mf = min(mf, a[i]);
            ++i;
        }
        else
        {
            i = i+blk
        }
        

    }
    mn = amin(l, r, blk, a);
}