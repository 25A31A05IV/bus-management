#include <iostream>
using namespace std;

struct Bus {
    int regNo;
    int busno;
    string name;
    string location;
    string route;
    Bus* next;
};

Bus* head = NULL,temp=NULL;

// Insert at end
void insertBus(int reg,int busno, string name, string loc, string route) {
    Bus* newBus = new Bus{reg,busno, name, loc, route, NULL};

    if (head == NULL) {
        head = newBus;
        return;
    }

    Bus* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newBus;
}

// Auto add 5 buses
void loadBuses() {
    insertBus(1, 1,"x", "kakinada", "ROUTE A");
    insertBus(1,  2,"x", "kakinada", "Route-B");
    insertBus(1, 3,"x", "pitapuram", "Route-C");
    insertBus(1, 4,"x", "samarlakota", "Route-D");
    insertBus(1, 5,"x", "rjy", "Route-E");
}

// Add manually
void addBus() {
    int reg,busno;
    string name;

    cout << "Enter Reg No: ";
    cin >> reg;
    cout <<"enter your name";
    cin >> name;
    cout << "Enter Bus no: ";
    cin >> busno;
    
    while (temp != NULL) {
        if (temp->busno == busno) {
            temp->reg=reg;
            temp->name=name;
            return;
        }
        temp = temp->next;
    }

    
    cout << "Bus added successfully!\n";
}

// Display buses
void display() {
    Bus* temp = head;

    if (temp == NULL) {
        cout << "No buses available\n";
        return;
    }

    cout << "\n--- Bus List ---\n";
    while (temp != NULL) {
        cout << "\nbus number: " << temp->busno;
        cout << "\nLocation: " << temp->location;
        cout << "\nRoute: " << temp->route << endl;

        temp = temp->next;
    }
}

// Search
void searchBus() {
    int reg;
    cout << "Enter Reg No to search: ";
    cin >> reg;

    Bus* temp = head;

    while (temp != NULL) {
        if (temp->regNo == reg) {
            cout << "\nBus Found!\n";
            cout << temp->name << " | " << temp->location 
                 << " | " << temp->busno << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Bus not found!\n";
}

// Main
int main() {
    loadBuses();

    int choice;

    do {
        cout << "\n--- College Bus Management ---\n";
        cout << "1. View Buses\n2. Add Bus\n3. Search Bus\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: display(); break;
            case 2: addBus(); break;
            case 3: searchBus(); break;
        }

    } while (choice != 4);

    return 0;
}
