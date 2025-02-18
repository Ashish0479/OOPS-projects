#include<iostream>
using namespace std;
class student{
    protected:
        char name;
        int rollno;
    public:
        void setdata(char n,int r){
            name=n;
            rollno=r;
        }


};
class exam:protected student{
    protected:
    int mathsMarks;
    int Phymarks;
    public:
        void setmarks(int m,int p){
            mathsMarks=m;
            Phymarks=p;
        }

};

class result:protected exam{
    public:
        void getdata(){
            cout<<"enter name:";
            cin>>name;
            cout<<"enter rollno:";
            cin>>rollno;

            setdata(name,rollno);

        }
       
      int average(int mathsMarks,int Phymarks){
        int average=(mathsMarks+Phymarks)/2;
        return average;
      };

};
int main(){

    return 0;

}
