#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> a)
{
    for(unsigned int i = 0; i<a.size(); i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void merge(vector<int> &a,vector<int> &l, vector<int> &r) //address oprtr needed to maintain pointers to arrays in recursive stacks
{
   int  i = 0, nl = l.size();
   int  j = 0, nr = r.size();
   int  k = 0, n = a.size();
   while(i<nl && j<nr)
   {
       if(l[i]<r[j])
       {
        a[k] = l[i];
        i++;
       }
       else
       {
        a[k] = r[j];
        j++;
       }
       k++;
   }
   while(i<nl)
   {
       a[k] = l[i];
       i++;
       k++;
   }
   while(j<nr)
   {
       a[k] = r[j];
       j++;
       k++;
   }
}

void mergesort(vector<int> &a)
{
    int n = a.size();
    if(n<2) //basecase
    return;
    int mid = n/2;
    vector<int> l;
    vector<int> r;
    int nl = mid;
    int nr = n-mid;
    int i=0, j=mid, k = 0;
    while(i<nl)
    {
        l.push_back(a[k]);
        i++;
        k++;
    }
    while(j<n)
    {
        r.push_back(a[k]);
        j++;
        k++;
    }
    mergesort(l);
    mergesort(r);
    merge(a, l, r);
    print(a);   
}

int main()
{
    vector<int> a = {5,6,2,56,12,45,78,23,45,23,67};
    int n = a.size();
    mergesort(a); 
    cout<<"sorted arr is "<<endl;
    print(a);
}

