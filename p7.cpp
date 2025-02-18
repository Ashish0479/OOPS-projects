#include <iostream> 
using namespace std;
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class Rational
{public:
    int numerator;
    int denominator;

public:
    Rational() : numerator(0), denominator(1) {}
    Rational(int x, int y) : numerator(x), denominator(y)
    {
        if (denominator == 0)
        {
            cout << "Denominator cannot be zero. Resetting to 1." << endl;
            denominator = 1;
        }
        reduce();
    }
    void reduce()
    {
        int hcf = gcd(numerator, denominator);
        numerator /= hcf;
        denominator /= hcf;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    Rational operator+(const Rational &r)
    {
        Rational result;
        result.numerator = (numerator * r.denominator) + (r.numerator * denominator);
        result.denominator = denominator * r.denominator;

        result.reduce();
        return result;
    }
    friend istream &operator>>(istream &in, Rational &r);
    friend ostream &operator<<(ostream &out, const Rational &r);
};
istream &operator>>(istream &in, Rational &r)
{
    cout << "Enter numerator: ";
    in >> r.numerator;
    cout << "Enter denominator: ";
    in >> r.denominator;
    if (r.denominator == 0)
    {
        cout << "Denominator cannot be zero. Resetting to 1." << endl;
        r.denominator = 1;
    }
    r.reduce();
    return in;
}
ostream &operator<<(ostream &out, const Rational &r)
{
    out << r.numerator << "/" << r.denominator;
    return out;
}
int main()
{
    Rational r1, r2, r3;

    cout << "Enter the first rational number:" << endl;
    cin >> r1;
    cout << "Enter the second rational number:" << endl;
    cin >> r2;
    cout << "First rational number in reduced form: " << r1 << endl;
    cout << "Second rational number in reduced form: " << r2 << endl;
    r3 = r1 + r2;
    cout << "The addition of the two rational numbers is: " << r3 << endl;
    return 0;
}