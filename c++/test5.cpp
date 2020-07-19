#include<iostream>
using namespace std;
int main()
{
	int *p = new(nothrow) int[10];
	if(!p)
	{
		cout<<"memory allocation fail";
	}
	else
	{
		for(int i= 0; i<5; i++)
		{
			*(p+i) = i;   // or p[i] = i;   when we create pointer to arrays we can dereference the pointer with the name itself
			cout<<*(p+i)<<endl;
		}
			
	}
	delete[] p;
}
