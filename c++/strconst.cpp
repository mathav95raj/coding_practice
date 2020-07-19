#include<iostream>
using namespace std;
int main()
{
//    char* immutable = "hello", *k; //s is a pointer to the starting of an immutable string literal  CONSTANT DATA VARIABLE POINTER same as CONST CHAR* S
//    char dessert[50];
//    cout<<dessert;
	char name[50] = "tom";
	char* ptr = name;
	cout<<"start";
	cout<<(void*)ptr<<endl<<&ptr<<endl<<&name<<endl<<name;
//    //char* mutable2 = &immutable;
//    //s[0] = 'y';  deprecated conversion from const
//    char* mutable1 = dessert;
//    char* mutable2 = immutable;
//    //mutable
//    char a = 'g';
//    char *f = &a;   
//    int *ptr;
//    cout<<sizeof(k)<<endl<<sizeof(immutable);  //all pointers are same size , 4 bytes
//    cout<<immutable<<endl<<f<<endl<<ptr;
//    cout<<&dessert;
}
