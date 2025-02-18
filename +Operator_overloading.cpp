#include <iostream>
using namespace std;
class complex{
    float x;
    float y;
    public:
      
        complex(){};
        complex(float real,float imag){
            x=real;
            y=imag;

        }
        void display(){
            cout<<x<<" + "<<y<<endl;
        }
        complex operator+(complex c){            //using member function
            complex temp;
            temp.x=x+c.x;
            temp.y=y+c.y;
            return temp;

        }

       

};

int main(){
    complex c1,c2,c3;
    c1=complex(2,4);
    c2=complex(5,6);
    c3=c1+c2;
    c1.display();
    c2.display();
    c3.display();

    return 0;

}