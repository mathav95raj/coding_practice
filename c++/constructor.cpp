
#include<iostream>
#include<string.h>
using namespace std;
class car
{
    public:
    char* name; //creating a char pointer to name
    //char* model;  //for shallow copy example with model use this. dynamic allocation works only with this
    char model[15]; //for deep copy example use this 
    car()
    {
        name = '\0';
    }
    car(const char *x){
        name = new char[15]; //dynamic alloc of name from line 8
        strcpy(name,x);
    } 
    car(const car &x){      //without copy constructor line 27 will create shallow copy sharing same name variable
        strcpy(name, x.name);
    } 
    char* changen(const char *x)
    {
        strcpy(name,x);
    }
    char* getn(){
        return name;
    }
};
int main()
{
car c1("hyundai");
car c2 = c1; //with copy constructor this is deep copy, separate memory blocks created
c2.changen("honda");
cout<<c1.getn()<<endl<<c2.getn()<<endl;
//arrays create deep copies, dynamic allocation creates shallow copies
car c3,c4;
//c3.model = new char[15]; use this along with line 9
strcpy(c3.model, "be102");
c4 = c3;
c3.model[0]= 'a';
cout<<c3.model<<endl<<c4.model;

//without any explicit declaration, cpp adds default non parametrzed and copy constructors
}
