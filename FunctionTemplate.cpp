#include<iostream>
using namespace std;
template<class T>
void swap1(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

void display(int m,int n,float a,float b){
    cout<<"m and n before swap: "<<m<<" "<<n<<endl;
    swap1(m,n);
    cout<<"m and n after swap: "<<m<<" "<<n<<endl;

      cout<<"a and b before swap :"<<a<<"  "<<b<<endl;
    swap1(a,b);
    cout<<"a and b after swap: "<<a<<"   "<<b<<endl;
}
int main(){
    display(10,20,3.5,7.6);
    return 0;
}