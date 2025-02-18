#include<iostream>
#include<string>
using namespace std;

class Cars {
protected:
    string name;
    string List[50] = {
        "Audi A4", "Audi Q7", "BMW 3 Series", "Chevrolet Beat", "Chevrolet Cruze",
        "Ford EcoSport", "Ford Endeavour", "Honda City", "Honda Civic", "Hyundai Creta",
        "Hyundai Elantra", "Hyundai Grand i10", "Hyundai Verna", "Mahindra Alturas G4", 
        "Mahindra Bolero", "Mahindra Scorpio", "Maruti Alto 800", "Maruti Celerio", 
        "Maruti Dzire", "Maruti Ertiga", "Maruti Swift", "Maruti Vitara Brezza", "Nissan Magnite", 
        "Renault Kwid", "Renault Triber", "Skoda Octavia", "Skoda Superb", "Tata Altroz", 
        "Tata Harrier", "Tata Nexon", "Tata Tiago", "Toyota Fortuner", "Toyota Innova Crysta", 
        "Toyota Land Cruiser", "Volkswagen Polo", "Volkswagen Virtus", "Volvo XC90"
    };
    
public:
    void search() {
        cout << "Enter car name: ";
        getline(cin, name);  // To handle multi-word input

        bool found = false;  // Flag to check if the car is found
        for(int i = 0; i < 38; i++) {
            if(name == List[i]) {
                cout << "Car found: " << List[i] << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Car not found." << endl;
        }
    }
};

int main() {
    Cars c1;
    c1.search();
    return 0;
}
