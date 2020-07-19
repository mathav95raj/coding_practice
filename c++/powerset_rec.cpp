#include <iostream>
#include <string>
using namespace std;

int powerset(string str, string curr, int i)
{
if (i == 3)
    {
        cout<<curr<<endl;
        return 0;
    }
 
    powerset(str, curr, i+1);
    powerset(str, curr + str.at(i), i+1);
    
}


int main() {
    string str("abc");
	powerset(str, "", 0);
	return 0;
}