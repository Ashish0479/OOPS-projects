#include<iostream>
using namespace std;
class complex{
    int real,imaginary;
    public:
        void getdata(){
            cout<<"the real part is :"<<real<<endl;
            cout<<"the imaginary part is :"<<imaginary<<endl;
        };
        void setdata(int a,int b){
            real=a;
            imaginary=b;

        }
}; 
int main(){
    complex c1;
    complex *ptr=&c1;  // 2nd method:  complex *ptr = new complex;
    (*ptr).setdata(1,23);  // 2nd method :   ptr -> setdata(1,23);
    (*ptr).getdata();


    return 0;

}