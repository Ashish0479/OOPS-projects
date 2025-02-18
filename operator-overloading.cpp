#include <iostream>
using namespace std;
class Negation
{
    int x;
    int y;
    int z;

public:
    friend void operator -(Negation &n);
    void getdata(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    void display(void)
    {

        cout << "x:" << x << endl;
        cout << "y:" << y << endl;
        cout << "z:" << z << endl;
    }
   /*void operator- ()            // using member function
    {
        x = -x;
        y = -y;
        z = -z;
    }
};*/
};

void operator- (Negation &n){           //using friend function
    n.x=-n.x;
    n.y=-n.y;
    n.z=-n.z;

}

int main()
{
    Negation N;
    N.getdata(1,2,3);
    cout << "numbers:" << endl;
    N.display();
    -N;
    cout << "Negation of numbers:" << endl;
    N.display();

    return 0;
}