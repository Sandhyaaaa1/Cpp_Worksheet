#include <iostream>
#include <fstream>
using namespace std;

class Vehicle {
protected:
    string registrationNumber;
    string color;

public:

    Vehicle(string regNum = "", string col = "") : registrationNumber(regNum), color(col) {}


    virtual void writeToFile() {
        ofstream outFile("vehicle_details.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Vehicle Registration Number: " << registrationNumber << endl;
            outFile << "Vehicle Color: " << color << endl;
        } else {
            cout << "Error opening file!" << endl;
        }
        outFile.close();
    }


    virtual void display() {
        cout << "Vehicle Registration Number: " << registrationNumber << endl;
        cout << "Vehicle Color: " << color << endl;
    }


    void inputVehicleDetails() {
        cout << "Enter Vehicle Registration Number: ";
        cin >> registrationNumber;
        cout << "Enter Vehicle Color: ";
        cin >> color;
    }
};


class Car : public Vehicle {
private:
    int numberOfSeats;

public:

    Car(string regNum = "", string col = "", int seats = 0) : Vehicle(regNum, col), numberOfSeats(seats) {}


    void writeToFile() override {
        ofstream outFile("vehicle_details.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "\n--- Car Details ---" << endl;
            outFile << "Registration Number: " << registrationNumber << endl;
            outFile << "Color: " << color << endl;
            outFile << "Number of Seats: " << numberOfSeats << endl;
        } else {
            cout << "Error opening file!" << endl;
        }
        outFile.close();
    }


    void display() override {
        Vehicle::display();
        cout << "Number of Seats: " << numberOfSeats << endl;
    }


    void inputCarDetails() {
        inputVehicleDetails();
        cout << "Enter Number of Seats: ";
        cin >> numberOfSeats;
    }
};


class Bike : public Vehicle {
private:
    int engineCapacity;

public:

    Bike(string regNum = "", string col = "", int capacity = 0) : Vehicle(regNum, col), engineCapacity(capacity) {}


    void writeToFile() override {
        ofstream outFile("vehicle_details.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "\n--- Bike Details ---" << endl;
            outFile << "Registration Number: " << registrationNumber << endl;
            outFile << "Color: " << color << endl;
            outFile << "Engine Capacity: " << engineCapacity << " cc" << endl;
        } else {
            cout << "Error opening file!" << endl;
        }
        outFile.close();
    }


    void display() override {
        Vehicle::display();
        cout << "Engine Capacity: " << engineCapacity << " cc" << endl;
    }


    void inputBikeDetails() {
        inputVehicleDetails();
        cout << "Enter Engine Capacity (in cc): ";
        cin >> engineCapacity;
    }
};


void displayVehicleDetailsFromFile() {
    ifstream inFile("vehicle_details.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}


int main() {
    int choice;
    char saveOption;

    while (true) {

        cout << "\n--- Vehicle Management System ---\n";
        cout << "1. Add Vehicle Details\n";
        cout << "2. Show Vehicle Details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            int vehicleType;

            cout << "Enter the type of vehicle (1 for Car, 2 for Bike): ";
            cin >> vehicleType;

            if (vehicleType == 1) {

                Car car;
                car.inputCarDetails();
                car.display();
                cout << "Do you want to save this vehicle's details to a file? (y/n): ";
                cin >> saveOption;
                if (saveOption == 'y' || saveOption == 'Y') {
                    car.writeToFile();
                    cout << "\nDetails have been saved to 'vehicle_details.txt'." << endl;
                } else {
                    cout << "\nVehicle details were not saved." << endl;
                }
            } else if (vehicleType == 2) {

                Bike bike;
                bike.inputBikeDetails();
                bike.display();
                cout << "Do you want to save this vehicle's details to a file? (y/n): ";
                cin >> saveOption;
                if (saveOption == 'y' || saveOption == 'Y') {
                    bike.writeToFile();
                    cout << "\nDetails have been saved to 'vehicle_details.txt'." << endl;
                } else {
                    cout << "\nVehicle details were not saved." << endl;
                }
            } else {
                cout << "Invalid vehicle type!" << endl;
            }
        } else if (choice == 2) {

            cout << "\nDisplaying vehicle details from file:\n";
            displayVehicleDetailsFromFile();
        } else if (choice == 3) {

            cout << "Exiting the Vehicle Management System." << endl;
            break;
        } else {
            cout << "Your Choice is Invalid! Please try again." << endl;
        }
    }

    return 0;
}
