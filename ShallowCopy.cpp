// Online C++ compiler to run C++ program online
// shallow copy 
using namespace std;
#include <iostream>
class A
{  
    private:
    int a, b, *p;
    public :
    A()
    {
        p= new int;
    }
    void f(int x, int y , int z)
    {
       a=x;
       b=y;
       *p=z;
      
        
    }
    A (A &d)
    {
        a=d.a;
        b=d.b;
        p= new int;
        *p=*(d.p);
        *p=10;
    }
    ~ A()
    {
        delete p;
    }
    void show()
    {
        cout<<a<<b<<*p<<endl;
    }
};

  
int main() {
    // Write C++ code here
    
    A obj1;
    
    obj1.f(2,3,5);
    obj1.show();
    A obj2=obj1;
    obj2.show();
    

    return 0;
}
