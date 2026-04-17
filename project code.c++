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

Bus* head = NULL,*temp=head;

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
    insertBus(0, 1,"x", "kakinada", "ROUTE A");
    insertBus(0,  2,"x", "kakinada", "Route-B");
    insertBus(0, 3,"x", "pitapuram", "Route-C");
    insertBus(0, 4,"x", "samarlakota", "Route-D");
    insertBus(0, 5,"x", "rjy", "Route-E");
}

// Add manually
void addmember() {
    int reg,busno;
    string name;

    cout << "Enter Reg No: ";
    cin >> reg;
    cout <<"enter your name";
    cin >> name;
    cout << "Enter Bus no: ";
    cin >> busno;
    int ch=0;
    while (temp != NULL) {
        if (temp->busno == busno) {
            temp->regNo=reg;
            temp->name=name;
            ch=1;
            return;
        }
        temp = temp->next;
    }
if(ch)
{ cout << "Bus added successfully!\n";}
    else
{ cout<<"\ninvalid bus number\n";}
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
    cout<<"\nenter bus number to view all the stops\n";
    cin>>ch;
    switch(ch){
        case 1:cout<<"1:gathicenter\n2: jagganaikpur \n3:balajicheruvu\n";break;
        case 2:cout<<"1:sarpavaram\n2:srinagar \n3:main road\n";break;
        case 3:cout<<"1:simhadripuram\n2: municipalhighscool\n3:pitapuram temple\n";break;
        case 4:cout<<"1:jaggampeta\n2:ganapathinagar\n3:peddapuram";break;
        case 5:cout<<"1:rtc colony\n2:lalachruvu\n3:divan chreuvu";break;
    }
}

// Search
void viewdetails() {
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
        cout << "1. View Buses\n2. Add a member to bus\n3. view deatails of member\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: display(); break;
            case 2: addmember(); break;
            case 3: viewdetails(); break;
        }

    } while (choice != 4);

    return 0;
}
