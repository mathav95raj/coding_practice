// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the leaders in an array of size n
vector<int> leaders(int arr[], long long n){
    
    // Your code here
    vector<int> v;
    v.push_back(arr[n-1]);
    cout<<v[0];
    long long pos = 0;
    for(long long i = n-2; i >=0; i++)
    {
        if(arr[i] >= v.at(pos)){
            v.push_back(arr[i]);
            pos++;
        }
    }
    for(long long i = 0; i<v.size()/2 ; i++)
    {
        swap(v[0], v[v.size() - 1 - i]);
    }
    return v;
    /******************
     * You just need to complete this
     * function and return the vector
     * containing the leaders.
     * ***************/
     
    
}

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;
   while (t--)
   {
       long long n;
       cin >> n;
        
        int a[n];
        
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        
        vector<int> v = leaders(a, n);
        
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends