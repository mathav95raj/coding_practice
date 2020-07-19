#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main()
{
 
    vector<int> vec{1,4,3,5,6,7};
    vector<int> ran(7);
    iota(ran.begin(), ran.end(), 1);
    // map<int, int> M;
    int res = 0;
    auto ItA = vec.begin();
    auto ItB = ran.begin();

    while(ItA != vec.end() || ItB != ran.end())
    {
  
        if(ItA!=vec.end()){
        res = *ItA ^ *ItB;
        ++ItA;}
        cout<<*ItB;
        if(ItA!=ran.end())
        
        ++ItB;

}
// cout<<res;
        // M[x]++;
        // if((M[x] & 1) == 0)
        // remove(vec.begin(), vec.end(), x);
    // }
    // cout<<vec[0];
    // for(auto x: M)
    // {
    //     if((x.second & 1) == 1)
    //     cout<<x.first;
    // }

}