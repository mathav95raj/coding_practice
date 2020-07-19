#include <iostream>
#include <vector>
using namespace std;
/* void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
} */
void print(vector<int> &a)
{
    for(unsigned int i = 0; i<a.size(); i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
vector<int> selection(vector<int> a, unsigned int n)
{
    for(unsigned int i = 0; i< n-1; i++) //unsigned because n is size
    {
        int min = i;
        for(int j = i+1; j< n; j++)
        {
            if (a[j] < a[min])  //is there any minimum than the present, in the unsorted part
            min = j;
        }
        if(min != i)  //for stability of sort
        swap(a[i], a[min]);
        print(a);
    }
    return a;
}
vector<int> bubble(vector<int> a, unsigned int n)
{
    for(unsigned int i = n-1; i> 0; i--) //small element bubbles to first in each pass
    {
        int flag = 0;
        for(unsigned int j = n-1; j> n-i-1; j--) // in each ith pass i elements in last will be in correct order
                                            //each pass start the comparisons from end
        {
            if (a[j] < a[j-1]) //stability imposed
            {
            swap(a[j], a[j-1]);
            flag = 1;
            }
        }
        print(a);
        if(flag != 1)  //for omega = n 
        break;
    }
    return a;
}
vector<int> insertion(vector<int> a,int n)
{
    for(int i = 1; i< n; i++) 
    {
       /*  if(a[i] < a[i-1])   is the best case complexity o(n)?
        {
        for(int j = 0; j< i; j++)
        {
            if (a[i] < a[j])  
            {
                a.insert(a.begin() + j, a[i]);
                a.erase(a.begin()+i+1);
            }
        }
        } */
        int temp = a[i];
        int j = i -1;
        while(j>=0 && temp<a[j]) //loop through sorted sublist from reverse compare first element of unsorted sublist
        {                       //condn failure at desired position
            a[j+1] = a[j]; //push
            j--;
        }
        a[j+1] = temp;
        print(a);
    }
    return a;
}
int main()
{
    vector<int> a = {5,6,2,56,12,45,78,23,45,23,67};
    int n = a.size();
 /*    vector<int> mizu = selection(a, n); //n2 all, very bad 
    cout<<"sorted arr is "<<endl;
    print(mizu); */
 /*    vector<int> mizu = bubble(a, n); //n2 for reverse, n for sorted, 
    cout<<"sorted arr is "<<endl;
    print(mizu);  */
/*     vector<int> mizu = insertion(a, n); //n2 for reverse, n for sorted, 
    cout<<"sorted arr is "<<endl;
    print(mizu); */
}

