//chaining not implemented

#include <iostream>
#include <list>
#include <string>
using namespace std;

class hashtable{
    private:
    static const int hashgroup = 10;
    list<pair<int, string>> table[hashgroup];

    public:
    bool ishashempty();
    int hashingfunc(int key);
    void insertitem(int key, string name);
    void removeitem(int key);
    void printtable();
};

bool hashtable::ishashempty(){
    for(auto x: table){
        if (x.size())
            return false;
    } 
    cout<<"empty\n";
    return true;
}

int hashtable::hashingfunc(int key){
    return  key % hashgroup;
}

void hashtable::insertitem(int key, string name){
    bool keyexists{false}; //initializes var to 0 of type int , int i = 1.2 --> i is 1  , int i{1.2} -->error
    int hashvalue = hashingfunc(key);
    auto& cell = table[hashvalue];
    auto itr = begin(cell);
    for(; itr!=end(cell); itr++){
        if (itr->first == key){
            keyexists = true;
            itr->second = name;
            cout<<"[warn] replaced\n";
            break;
        }
    }
    if(!keyexists){
        // auto& cell = table[hashvalue];
        // cell.emplace_back(key, name);
        cell.emplace_back(key, name);  //emplace_back is faster than push_back
                                                    //push_back --> vector<vector<int>> v1; v1.pushback(100); --> compiler error --> correct:  v1.pushback({100});--> creates temporary vector object and copies it to last place
                                                    //emplace_back --> implicit conversion in the container itself, no temp obj created --> vector<vector<int>> v1; v1.pushback(100000); --> creates a vector with 100000 elements!!
    }
    return; 
}
void hashtable::removeitem(int key){
    int hashvalue = hashingfunc(key);
    // auto& cell = table[hashvalue];
    // auto itr = begin(cell);
    // for(; itr!=end(cell); itr++)
    // {
    //     if (itr->first == key)
    // {
    //         itr = cell.erase(itr);
    //         cout<<"[warn] erased\n";
    //         return;
    // }

    // }
    for (auto x : table[hashvalue])
    {
        if (x.first == key)
        {
            x = table[hashvalue].erase(x);
            cout<<"[warn] erased\n";
            return;
        }
    }
    return;
}
void hashtable::printtable(){
    // for(int i{}; i<hashgroup; i++)
    // {
    //     if (table[i].size() == 0)
    //         continue;
    //     else
    //     {
    //        auto itr = table[i].begin();
    //        for(; itr!= table[i].end(); itr++)
    //          cout<<"info "<<itr->first<<" "<<itr->second<<endl; 
    //     }        
        
    // }
        for (auto cell : table)
    {
        if (cell.size() == 0)
            continue;
        for(auto x : cell)
        {
            cout << x.first<<" " <<x.second<< endl;
        }
    }
    return;
}
int f(){
static int i = 0;
i++;
return i;
}
int f1(){
    int k = f();
    k = f();
    cout<<k<<endl;
}
int main()
{

    hashtable HT;
    f1();
    cout<<HT.ishashempty()<<"\n";
    HT.insertitem(123, "tilda");
    HT.insertitem(112, "fasfd");
    HT.insertitem(134, "dbfdg");
    HT.insertitem(145, "fasffasdf");
    HT.insertitem(145, "uiof");
    HT.insertitem(156, "cvxczv");
    HT.removeitem(156);
    HT.printtable();
    return 0;
}

