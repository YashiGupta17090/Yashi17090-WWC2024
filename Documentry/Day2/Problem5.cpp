//Q5: Design a train reservation system in C++ using linked lists to manage bookings for multiple trains, 
//each with several compartments. Each compartment has a fixed number of seats, and passengers can book, cancel, or check 
//the availability of seats for specific compartments. Additionally, the system should dynamically allocate memory for 
//new bookings and keep track of canceled seats efficiently.
#include <iostream>
#include <string>
using namespace std;

// Structure to represent a seat in a compartment
struct Seat {
    bool isBooked;
    Seat() : isBooked(false) {} // Seat is available by default
};

// Structure to represent a compartment in a train
struct Compartment {
    int compID;
    Seat* seats;
    int numSeats;
    Compartment* next;

    Compartment(int id, int seatCount) : compID(id), numSeats(seatCount), next(nullptr) {
        seats = new Seat[seatCount];  // Dynamically allocate seats
    }

    ~Compartment() {
        delete[] seats;  // Clean up dynamically allocated memory
    }

    // Check availability of a seat in this compartment
    bool checkAvailability(int seatNumber) {
        if (seatNumber < 0 || seatNumber >= numSeats) {
            cout << "Invalid seat number!" << endl;
            return false;
        }
        return !seats[seatNumber].isBooked;
    }

    // Book a seat
    bool bookSeat(int seatNumber) {
        if (checkAvailability(seatNumber)) {
            seats[seatNumber].isBooked = true;
            cout << "Seat " << seatNumber << " successfully booked!" << endl;
            return true;
        }
        cout << "Seat " << seatNumber << " is already booked." << endl;
        return false;
    }

    // Cancel a booking for a seat
    bool cancelSeat(int seatNumber) {
        if (seatNumber < 0 || seatNumber >= numSeats) {
            cout << "Invalid seat number!" << endl;
            return false;
        }
        if (!seats[seatNumber].isBooked) {
            cout << "Seat " << seatNumber << " is not booked." << endl;
            return false;
        }
        seats[seatNumber].isBooked = false;
        cout << "Booking for seat " << seatNumber << " canceled!" << endl;
        return true;
    }

    // Print compartment details
    void printCompartment() {
        cout << "Compartment ID: " << compID << "\nSeats: ";
        for (int i = 0; i < numSeats; i++) {
            cout << (seats[i].isBooked ? "Booked " : "Available ") << " ";
        }
        cout << endl;
    }
};

// Structure to represent a train
struct Train {
    int trainID;
    string trainName;
    Compartment* compartments;

    Train(int id, string name) : trainID(id), trainName(name), compartments(nullptr) {}

    // Add compartment to train
    void addCompartment(int compID, int numSeats) {
        Compartment* newCompartment = new Compartment(compID, numSeats);
        newCompartment->next = compartments;
        compartments = newCompartment;
    }

    // Find a compartment by ID
    Compartment* findCompartment(int compID) {
        Compartment* temp = compartments;
        while (temp) {
            if (temp->compID == compID) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; // Return null if compartment is not found
    }

    // Display train details
    void displayTrainInfo() {
        cout << "Train ID: " << trainID << ", Train Name: " << trainName << endl;
        Compartment* temp = compartments;
        while (temp) {
            temp->printCompartment();
            temp = temp->next;
        }
    }
};

int main() {
    Train train1(101, "Express Train");

    // Adding compartments to the train
    train1.addCompartment(1, 5);  // Compartment 1 with 5 seats
    train1.addCompartment(2, 4);  // Compartment 2 with 4 seats

    // Displaying the current train info
    train1.displayTrainInfo();

    // Booking a seat in compartment 1
    Compartment* comp = train1.findCompartment(1);
    if (comp) {
        comp->bookSeat(2);  // Book seat 2 in compartment 1
    }

    // Trying to book an already booked seat
    if (comp) {
        comp->bookSeat(2);  // Try booking seat 2 again
    }

    // Canceling a seat booking
    if (comp) {
        comp->cancelSeat(2);  // Cancel seat 2
    }

    // Displaying the updated train info
    train1.displayTrainInfo();

    // Checking availability
    if (comp) {
        if (comp->checkAvailability(2)) {
            cout << "Seat 2 is available for booking." << endl;
        } else {
            cout << "Seat 2 is not available." << endl;
        }
    }

    return 0;
}
