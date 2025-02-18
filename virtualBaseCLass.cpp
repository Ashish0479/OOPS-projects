#include<iostream>
using namespace std;
class student{
    protected:
        int Roll_no;
    public:
        void set_number(int a){
            Roll_no=a;

        }
        void print_number(void){
            cout<<"your roll number is : "<<Roll_no<<endl;
        }


};
class test: virtual public student{
    protected:
        float maths,physics;
    public:
        void setMarks(float m1,float m2){
            maths=m1;
            physics=m2;

        }
        void printMarks(void){
            cout<<"your result is here: "
                <<"maths : "<<maths<<endl
                <<"physics :"<<physics<<endl;
        }



};
class sports : virtual public student{
    protected:
        float score;
    public:
        void setScore(float s){
            score = s;

        }
        void print_score(void){
            cout<<"your pt score is : "<<score<<endl;

        }

};

class result: public test,public sports{
    private:
        float total;
    public:
        void display(void){
            total= maths+physics+score;
            print_number();
            printMarks();
            print_score();
            cout<<"your total score is : "<<total<<endl;
        }

};

int main(){
    result ashish;
    ashish.set_number(33);
    ashish.setMarks(80.5,95.5);
    ashish.setScore(9);
    ashish.display();
    return 0;

}