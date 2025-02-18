#include <iostream>
#include <string> // Include string library
using namespace std;

class student {
    string name;  // Changed from 'char name' to 'string name'
    int rollno;
    
public:
    friend ostream &operator<<(ostream &, student &);
    friend istream &operator>>(istream &, student &);
};

// Overloaded << operator
ostream &operator<<(ostream &out, student &s1) {
    out << "Name: " << s1.name << "\n";
    out << "Roll No: " << s1.rollno << "\n";
    return out;
}

// Overloaded >> operator
istream &operator>>(istream &in, student &s1) {
    cout << "Enter name: ";
   in >> s1.name;
    
    cout << "Enter roll no.: ";
    in >> s1.rollno;
    
    
    return in;
}

int main() {
    student s1;
    cout << "Enter details for object:\n";
    cin >> s1;
    
    cout << "\nDetails for object:\n";
    cout << s1;
    
    return 0;
}
