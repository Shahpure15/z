#include <iostream>
#include <string>
using namespace std;

// Node structure for Railway Reservation
struct Reservation {
    int pnr;              // Passenger Name Record
    string passengerName;
    int age;
    string trainNo;
    string trainName;
    string from;
    string to;
    string date;
    string seatNo;
    Reservation* next;
};

class RailwayReservation {
    Reservation* head;
    int pnrCounter;

public:
    RailwayReservation() {
        head = NULL;
        pnrCounter = 1000;  // Starting PNR number
    }

    // Insert new reservation
    void bookTicket() {
        Reservation* newRes = new Reservation;
        
        newRes->pnr = ++pnrCounter;
        
        cin.ignore();
        cout << "\nEnter Passenger Name: ";
        getline(cin, newRes->passengerName);
        cout << "Enter Age: ";
        cin >> newRes->age;
        cin.ignore();
        cout << "Enter Train Number: ";
        getline(cin, newRes->trainNo);
        cout << "Enter Train Name: ";
        getline(cin, newRes->trainName);
        cout << "Enter From Station: ";
        getline(cin, newRes->from);
        cout << "Enter To Station: ";
        getline(cin, newRes->to);
        cout << "Enter Journey Date (DD/MM/YYYY): ";
        getline(cin, newRes->date);
        cout << "Enter Seat Number: ";
        getline(cin, newRes->seatNo);

        newRes->next = NULL;

        // Insert at end
        if (head == NULL) {
            head = newRes;
        } else {
            Reservation* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newRes;
        }

        cout << "\n*** Ticket Booked Successfully! ***";
        cout << "\nYour PNR: " << newRes->pnr << "\n";
    }

    // Display all reservations
    void displayReservations() {
        if (head == NULL) {
            cout << "\nNo Reservations Found!\n";
            return;
        }

        Reservation* temp = head;
        cout << "\nRailway Reservations\n";
        while (temp != NULL) {
            cout << "\nPNR: " << temp->pnr;
            cout << "\nPassenger Name: " << temp->passengerName;
            cout << "\nAge: " << temp->age;
            cout << "\nTrain: " << temp->trainNo << " - " << temp->trainName;
            cout << "\nRoute: " << temp->from << " -> " << temp->to;
            cout << "\nDate: " << temp->date;
            cout << "\nSeat: " << temp->seatNo;
            temp = temp->next;
        }
        cout << endl;
    }

    // Search reservation by PNR
    void searchByPNR() {
        if (head == NULL) {
            cout << "\nNo Reservations Available!\n";
            return;
        }

        int pnr;
        cout << "\nEnter PNR to Search: ";
        cin >> pnr;

        Reservation* temp = head;
        while (temp != NULL) {
            if (temp->pnr == pnr) {
                cout << "\n--- Reservation Details ---";
                cout << "\nPNR: " << temp->pnr;
                cout << "\nPassenger: " << temp->passengerName;
                cout << "\nAge: " << temp->age;
                cout << "\nTrain: " << temp->trainNo << " - " << temp->trainName;
                cout << "\nRoute: " << temp->from << " -> " << temp->to;
                cout << "\nDate: " << temp->date;
                cout << "\nSeat: " << temp->seatNo << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "\nReservation Not Found!\n";
    }

    // Update reservation details
    void updateReservation() {
        if (head == NULL) {
            cout << "\nNo Reservations to Update!\n";
            return;
        }

        int pnr;
        cout << "\nEnter PNR to Update: ";
        cin >> pnr;

        Reservation* temp = head;
        while (temp != NULL) {
            if (temp->pnr == pnr) {
                cin.ignore();
                cout << "\nEnter New Passenger Name: ";
                getline(cin, temp->passengerName);
                cout << "Enter New Age: ";
                cin >> temp->age;
                cin.ignore();
                cout << "Enter New Date (DD/MM/YYYY): ";
                getline(cin, temp->date);
                cout << "Enter New Seat Number: ";
                getline(cin, temp->seatNo);

                cout << "\nReservation Updated Successfully!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "\nReservation Not Found!\n";
    }

    // Cancel reservation (delete)
    void cancelReservation() {
        if (head == NULL) {
            cout << "\nNo Reservations to Cancel!\n";
            return;
        }

        int pnr;
        cout << "\nEnter PNR to Cancel: ";
        cin >> pnr;

        Reservation *temp = head, *prev = NULL;

        // If head node is to be deleted
        if (temp != NULL && temp->pnr == pnr) {
            head = temp->next;
            delete temp;
            cout << "\nReservation Cancelled Successfully!\n";
            return;
        }

        // Search for the reservation to be deleted
        while (temp != NULL && temp->pnr != pnr) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "\nReservation Not Found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "\nReservation Cancelled Successfully!\n";
    }

    // Sort reservations by PNR
    void sortByPNR() {
        if (head == NULL || head->next == NULL) {
            cout << "\nNot enough reservations to sort!\n";
            return;
        }

        for (Reservation* i = head; i->next != NULL; i = i->next) {
            for (Reservation* j = i->next; j != NULL; j = j->next) {
                if (i->pnr > j->pnr) {
                    swap(i->pnr, j->pnr);
                    swap(i->passengerName, j->passengerName);
                    swap(i->age, j->age);
                    swap(i->trainNo, j->trainNo);
                    swap(i->trainName, j->trainName);
                    swap(i->from, j->from);
                    swap(i->to, j->to);
                    swap(i->date, j->date);
                    swap(i->seatNo, j->seatNo);
                }
            }
        }

        cout << "\nReservations Sorted by PNR!\n";
    }

    // List all reservations for a specific train
    void listByTrain() {
        if (head == NULL) {
            cout << "\nNo Reservations Available!\n";
            return;
        }

        string trainNo;
        cout << "\nEnter Train Number: ";
        cin.ignore();
        getline(cin, trainNo);

        Reservation* temp = head;
        bool found = false;

        cout << "\n--- Reservations for Train " << trainNo << " ---\n";
        while (temp != NULL) {
            if (temp->trainNo == trainNo) {
                cout << "\nPNR: " << temp->pnr;
                cout << "\nPassenger: " << temp->passengerName;
                cout << "\nSeat: " << temp->seatNo;
                cout << "\nDate: " << temp->date;
                cout << "\n-----------------------";
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "\nNo reservations found for this train!\n";
        }
    }
};

int main() {
    RailwayReservation rr;
    int choice;

    do {
        cout << "\n===== Railway Reservation System =====";
        cout << "\n1. Book Ticket";
        cout << "\n2. Display All Reservations";
        cout << "\n3. Search by PNR";
        cout << "\n4. Update Reservation";
        cout << "\n5. Cancel Reservation";
        cout << "\n6. Sort by PNR";
        cout << "\n7. List Reservations by Train";
        cout << "\n8. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: rr.bookTicket(); break;
            case 2: rr.displayReservations(); break;
            case 3: rr.searchByPNR(); break;
            case 4: rr.updateReservation(); break;
            case 5: rr.cancelReservation(); break;
            case 6: rr.sortByPNR(); break;
            case 7: rr.listByTrain(); break;
            case 8: cout << "\nThank You for Using Railway Reservation System!\n"; break;
            default: cout << "\nInvalid Choice!\n";
        }
    } while (choice != 8);

    return 0;
}
