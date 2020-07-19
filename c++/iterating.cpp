#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    static const int size = 3;
    // vector<pair<int, string>> vs;
    // vs.push_back({1, "One"});
    // vs.push_back({2, "Two"});
    // vs.push_back({3, "Three"});
    list<pair<int, string>> table[size];
    table[0].push_back({1, "One"});
    table[0].push_back({1, "One"});
    table[0].push_back({2, "One"});

    table[1].push_back({2, "Two"});
    table[1].push_back({2, "Two"});
    table[1].push_back({2, "Two"});

    table[2].push_back({3, "Three"});
    table[2].push_back({3, "Three"});
    table[2].push_back({3, "Three"});


    // for (auto x : table[0])
    // {
    // if(x.first == 2)
    // {
    // table[0].erase(x);
    // cout<<"[warn] erased\n";
    // }
    // }

    for (auto itr = begin(table[0]) ; itr != end(table[0]); itr++)
    {
    if(itr->first == 2)
    {
    table[0].erase(itr);
    cout<<"[warn] erased\n";
    break;
    }
    }


    for (auto cell : table)
    {
        for(auto x : cell)
        {
            cout << x.first<<" " <<x.second<<" ";
        }
        cout<<endl;
    }
    // for (auto x : vs)
    // {
    //     cout << x.first<<" " <<x.second<< endl;
    // }


    return 0;
}