#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> v; //sequence container  
    cout<<v.capacity()<<endl;
    v.push_back(10);
    vector<int>::iterator itr = v.begin();
    cout<<*itr<<endl;
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    cout<<v.capacity()<<endl;
    cout<<*itr<<endl;
    cout<<v.size()<<endl; //number of elements
    for(itr = v.begin(); itr<v.end(); itr++)
    cout<<*itr<<'\t';
    cout<<endl;
    v.clear();
    cout<<v.size();

    //map is balanced binary tree and sorts according to key. doesnt allow multiple key
    //multimap allows multiple key, but indexing is not allowed
    //unordered is hash ds
    //unordered allows multiple key values and indexing is not allowed
    map<int, int> mp; //key, vallue pair
    mp[3] = 356;
    mp[1] = 43;
    mp.insert(make_pair(10,100));
    for(auto it = mp.begin(); it!=mp.end(); it++)
        cout<<it->first<<"---"<<it->second<<endl;
    multimap<int, int> mmp;
    mmp.insert(make_pair(10, 500));
    mmp.insert(make_pair(10,200));
    mmp.insert(make_pair(9,200));
    for(auto itm = mmp.begin(); itm!=mmp.end(); itm++)
        cout<<itm->first<<"---"<<itm->second<<endl;
    cout<<"next"<<endl;
    unordered_multimap<int,int> ump;
    ump.insert(make_pair(1, 100));
    ump.insert(make_pair(2,800));
    ump.insert(make_pair(2,200));
    //ump[2] = 1000;
    for(auto itu = ump.begin(); itu!=ump.end(); itu++)
        cout<<itu->first<<"---"<<itu->second<<endl;


    
}
