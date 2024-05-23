#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Note {
    string lastName;
    string firstName;
    string phoneNumber;
    int birthDate[3];
};

struct Node {
    Note data;
    Node* next;
};

void createList(Node*& head, Node*& tail) {
    head = nullptr;
    tail = nullptr;

    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Note person;
        cout << "Enter data for person " << i + 1 << ":" << endl;
        cout << "Last name: ";
        getline(cin, person.lastName);
        cout << "First name: ";
        getline(cin, person.firstName);
        cout << "Phone number: ";
        getline(cin, person.phoneNumber);
        cout << "Birth date (day month year): ";
        cin >> person.birthDate[0] >> person.birthDate[1] >> person.birthDate[2];
        cin.ignore();

        Node* newNode = new Node();
        newNode->data = person;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void printPersonInfo(Node* head, const string& phoneNumber) {
    Node* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data.phoneNumber == phoneNumber) {
            found = true;
            cout << "Last Name: " << current->data.lastName << endl;
            cout << "First Name: " << current->data.firstName << endl;
            cout << "Phone Number: " << current->data.phoneNumber << endl;
            cout << "Birth Date: " << current->data.birthDate[0] << "/" << current->data.birthDate[1] << "/" << current->data.birthDate[2] << endl;
            break;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Person with phone number '" << phoneNumber << "' not found." << endl;
    }
}

bool compareBirthDates(const Note& person1, const Note& person2) {
    for (int i = 2; i >= 0; --i) {
        if (person1.birthDate[i] != person2.birthDate[i]) {
            return person1.birthDate[i] < person2.birthDate[i];
        }
    }
    return false;
}

void sortList(Node*& head) {
    vector<Note> people;
    Node* current = head;
    while (current != nullptr) {
        people.push_back(current->data);
        current = current->next;
    }
    sort(people.begin(), people.end(), compareBirthDates);
    current = head;
    for (const auto& person : people) {
        current->data = person;
        current = current->next;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    createList(head, tail);

    cout << "\nSorted list by birth dates:" << endl;
    sortList(head);
    Node* current = head;
    while (current != nullptr) {
        cout << "Last Name: " << current->data.lastName << endl;
        cout << "First Name: " << current->data.firstName << endl;
        cout << "Phone Number: " << current->data.phoneNumber << endl;
        cout << "Birth Date: " << current->data.birthDate[0] << "/" << current->data.birthDate[1] << "/" << current->data.birthDate[2] << "\n" << endl;
        current = current->next;
    }

    string searchPhoneNumber;
    cout << "\nEnter phone number to search for: ";
    getline(cin, searchPhoneNumber);
    printPersonInfo(head, searchPhoneNumber);

    current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
