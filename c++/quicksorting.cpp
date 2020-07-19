#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void print(vector<int> a)
{
    for(unsigned int i = 0; i<a.size(); i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
int partition(vector<int> &a,int start, int end) 
{
    int pivot;
    srand(time(NULL)); 
    int random = start + rand() % (end - start); 
    cout<<random<<' '<<end<<endl;
    swap(a[random], a[end]);
    pivot = a[end];
    int pindex = start;
    for(int i = start; i<=end-1; i++){
        if(a[i]<=pivot){
            swap(a[i], a[pindex]);
            pindex = pindex+1;
        }
    }
    swap(a[pindex], a[end]);
    return pindex;

}

void quicksort(vector<int> &a, int start,int end)
{
    if(start < end){
    int pindex;
    pindex = partition(a, start, end);
    //print(a);
    quicksort(a, start, pindex-1);
    quicksort(a, pindex+1, end);
    } 
}

int main()
{
    vector<int> a = {5,6,2,56,12,45,78,23,45,23,67};
    int n = a.size();
    quicksort(a, 0, n-1); 
    cout<<"sorted arr is "<<endl;
    print(a);
}

