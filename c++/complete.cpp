#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> //for sort
#include <unordered_map>

using namespace std;
void printvector(vector<int> A){
    // vector<int>::iterator itr;
    // for(itr = A.begin(); itr!= A.end(); itr++)
    // {
    //     cout<< *itr <<" ";
    // }
    // cout<<endl;
    
    //iterate by value
    for(int x: A)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
bool f(int x, int y){
    return x>y;
}
vector<int> not_inplace_sort(vector<int> A){
    sort(A.begin(), A.end(), greater<int>());
    return A;
}

void vectordemo(){
    vector<int> A = {1,45,54,14};
    cout << A[1] <<endl;
    sort(A.begin(), A.end()); //sorting in o(nlogn)
    
    printvector(A);
    //1, 14, 45, 54
    
    bool present = binary_search(A.begin(), A.end(), 3); //o(logn)
    A.push_back(100);
    
    //1, 14, 45, 54, 100
    A.push_back(100);
    A.push_back(100);
    A.push_back(99);
    A.push_back(100);
    A.push_back(123);
    printvector(A);
    //to get the iterator at first occurence of >=100
    vector<int>::iterator it1 = lower_bound(A.begin(), A.end(), 100);
    //to get the iterator at first occurence of >100
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100);
    
    cout<<*it1<<" "<<*it2<<endl;
    cout<<it2-it1<<endl; //vector iterator arithmetic done in o(1)

    //sort in descending order
    sort(A.begin(), A.end(), f);
    printvector(A);

    sort(A.begin(), A.end());

    auto rev = not_inplace_sort(A);
    printvector(rev);

    A.push_back(11123);
    auto it3 = lower_bound(A.begin(), A.end(), 1000);
    cout<<"value at "<<*it3<<endl;
    cout<<"address it points to "<<&(*it3);
    cout<<"address of it3 "<<&it3;

    cout << "lower_bound at position " << (it1 - A.begin()) << endl;
    cout << "upper_bound at position " << (it2 - A.begin()) << endl;
    printvector(A);
    //iterate by ref
    for(int &x: A){
        x++;
    }
    printvector(A);

}
void printset(set<int> s){
    for(int x: s){
        cout<<x;
    }
}
void printpairset(set<pair<int, int>> s){
    for(pair<int, int> x: s){
        cout<<x.first<<","<<x.second <<endl;
    }
}
// SETS ARE SORTED BY DEFAULT EVEN IN INSERTION
void setdemo(){
    //sometimes we want elements to be inserted in ascending order so that it will enable binary search and other operations in log n time

    set<int> S;
    S.insert(-10);
    S.insert(-1);
    S.insert(-14);
    printset(S);
    auto it = S.find(100);
    if(it == S.end()){
        cout<<"not present"<<endl;
    }

}
void mapdemo()
{
    map<int, int> A;
    A[1] = 100;
    A[-1] = 1000;
    A[56] = 90;

    //histogram of characters
    map<char, int> cnt;
    string name = "timberman";
    for(char x: name){
        cnt[x]++; //cnt is a map of each character to its count, note that ++ is on int
    }
    cout<<"count "<<cnt['m']<<endl;
}
void findinterval(){
set<pair<int, int>> S;
  S.insert({-2,20});
  S.insert({40,80});
  S.insert({100,200});
//   findinterval(51, S);
//{a,b}  == {c,d} iff a==c and b==d
//{a,b}  > {c,d} iff a>c or ( a==c and b>d)
//{a,b}  < {c,d} iff a<c or ( a==c and b<d)
//{a,b}  >= {c,d} iff (a==c and b==d) or (a>c or ( a==c and b>d))

  printpairset(S);

  //given a point which interval it is

  int val = 81;
  pair<int,int> point(val, INT16_MAX);
  auto it = S.upper_bound(point); //upper bound always points to interval immediat above true interv
  //lower bound wont work for values in first interval


  if(it == S.begin()){
  cout<<"itr is "<< (*it).first<<","<<(*it).second<<endl;
  cout<<"below first";
  return;
  }

  else{
  it--;
  cout<<"itr is "<< (*it).first<<","<<(*it).second<<endl;
  if((*it).first <= point.first && point.first <= (*it).second)
  cout<<"present in "<< (*it).first<<","<<(*it).second;
  else
  cout<<"not present";
  }
  


}

// template<typename T>
// std::ostream& print(std::ostream &out, T const &val) { return (out << val << " "); }

// template<typename T1, typename T2>
// std::ostream& print(std::ostream &out, std::pair<T1, T2> const &val) { return (out << "{" << val.first << " " << val.second << "} "); }

// template<template<typename, typename...> class TT, typename... Args>
// std::ostream& operator<<(std::ostream &out, TT<Args...> const &cont) {
//   for(auto elem : cont) print(out, elem);
//   return out;
// }
void map_vs_umap()
{
 map<char, int> M;
   unordered_map<char, int> U;

   string st = "tinkerbll";
   
   for(char x: st)    //o(NlogN) N = |st|  //uses balanced binary tree// O(logn) per add operation
   M[x]++; 

   for(char x: st)   ////o(N) N = |st| //uses hashing to add values to keys in array//O(1) per add operation
   U[x]++;
}
void print_map(map<long long, int>& A)
{
    for(const auto& x: A )
    cout<<"{"<<x.first<<" "<<x.second<<"}"<<" ";
    cout<<endl;
}
int main()
{  
  int n;
  cin>>n;
  vector<int> A(n, 0);
  long long sum = 0;
  
  for(int i{}; i<n; ++i) cin>>A[i], sum+=A[i];
  
  if(sum & 1)
  {
      cout<<"NO\n"; //odd sum wont satisfy the property
      return 0;

  } 
  map<long long, int> first, second;

  first[A[0]] = 1; //initialization

  for(int i{1}; i<n; ++i) second[A[i]]++; //not =1 cuzmap doesn't take duplicate so increment value for duplicate keys

  print_map(first);
  print_map(second);

  long long sdash = 0;
  for(int i{0}; i< n; ++i)
  {
      sdash+=A[i];
      if(sdash == sum/2)
      {
      cout<<"YES\n";
      return 0;
      }
      if(sdash< sum/2)
      {
          long long x = sum/2 - sdash;
          //delete element from swc half and insert in fir
          if(second[x] > 0) 
          {
              cout<<"Yes but index, val next to first "<< find(A.begin(), A.end(), x) - A.begin() <<","<<x<<endl;
                print_map(first);
                print_map(second);
              return 0;
          }
      }
      else
      {
          long long y = sdash - sum/2 ;
          //delete element from firs half and insert in ssec
          if(first[y] > 0) 
          {
            
              cout<<"Yes but index, val first to next "<< find(A.begin(), A.end(), y) - A.begin() <<","<<y<<endl;
                print_map(first);
  print_map(second);
              return 0;
          }
      }

      first[A[i+1]]++;
      second[A[i+1]]--;

    
  }
  cout<<"even but still not possible\n";
  return 0;
}