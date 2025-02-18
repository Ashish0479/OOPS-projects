#include<iostream>
using namespace std;
class B{
    public:
    int b;
    void show(){
        cout<<"b:"<<b<<endl;

    }

};
class D:public B
{
    public:
    int d;
    void show(){
        cout<<"b:"<<b<<endl;
        cout<<"d : "<<d<<endl;

    };
};
int main(){
    B *bptr;
    B base;
    bptr=&base;
    bptr->b=100;
    cout<<"bptr points to base object \n";
    bptr->show();

    D derived;
    bptr=&derived;
    bptr->b=200;
     // bptr->d=300  wont work 

   cout<<"bptr now points to derived object \n";
   bptr->show();

   D *dptr;
   dptr=&derived;
   dptr->d=300;

   cout<<"dptr is erived type pointer \n";
   dptr->show();

   cout<<"using ((D * )bptr)\n";
   ((D *)bptr)->d= 400;
    ((D *)bptr)->show();

return 0;
}

