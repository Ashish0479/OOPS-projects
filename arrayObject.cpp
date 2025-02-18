#include<iostream>
using namespace std;
class shopItem{
    int id;
    float price;
    public:
        void setdata(int a,int b){
            id=a;
            price=b;

        }
        void getdata(){
            cout<<"code of this item is : "<<id<<endl;
            cout<<"price of this item is : "<<price<<endl;

        }

};

int  main(){
    int size=3;
    int p,q;
    shopItem *ptr= new shopItem[size];
    shopItem *ptrtemp=ptr;          // in first loop ptr will reach size ,,so in 2nd loop it start from size ,,but we want to start our 2nd loop from 0 ,,so we use ptrtemp in 2nd loop
    for(int i=0;i<size;i++){
        cout<<"enter id and price of item "<<i+1<<endl;
        cin>>p>>q;
        ptr->setdata(p,q);
        ptr++;
    }

    for(int i=0 ; i<size ; i++){
        cout<<"item number:"<<i+1<<endl;
        ptrtemp->getdata();
        ptrtemp++;

    }

}