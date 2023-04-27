#include <iostream>
#include <stack>

using namespace std;

// Define a structure for the data to be stored in the stack
struct Data {
    int id;
    string name;
    int age;
};

// Function to add a new item to the stack
void add(stack<Data>& s) {
    Data newData;
    cout << "Enter id: ";
    cin >> newData.id;
    cout << "Enter name: ";
    cin >> newData.name;
    cout << "Enter age: ";
    cin >> newData.age;
    s.push(newData);
    cout << "New item added to the stack!" << endl;
}

// Function to delete an item from the stack based on ID
void deleteItem(stack<Data>& s) {
    int id;
    cout << "Enter the ID of the item to delete: ";
    cin >> id;

    stack<Data> tempStack;
    

    // Pop items from the original stack and push them onto a temporary stack
    // until the item to be deleted is found
    while (!s.empty()) {
        Data currData = s.top();
        s.pop();
        if (currData.id == id) {
            cout << "Item with ID " << id << " deleted from the stack!" << endl;
            break;
        }
        else {
            tempStack.push(currData);
        }
    }

    // Pop items from the temporary stack and push them back onto the original stack
    while (!tempStack.empty()) {
        Data currData = tempStack.top();
        tempStack.pop();
        s.push(currData);
    }

    if (s.empty()) {
        cout << "Item with ID " << id << " not found in the stack." << endl;
    }
}

// Function to update an item in the stack based on ID
void update(stack<Data>& s) {
    int id;
    cout << "Enter the ID of the item to update: ";
    cin >> id;

    stack<Data> tempStack;

    // Pop items from the original stack and push them onto a temporary stack
    // until the item to be updated is found
    while (!s.empty()) {
        Data currData = s.top();
        s.pop();
        if (currData.id == id) {
            cout << "Enter new name: ";
            cin >> currData.name;
            cout << "Enter new age: ";
            cin >> currData.age;
            tempStack.push(currData);
            cout << "Item updated!" << endl;
            break;
        }
        else {
            tempStack.push(currData);
        }
    }

    // Pop items from the temporary stack and push them back onto the original stack
    while (!tempStack.empty()) {
        Data currData = tempStack.top();
        tempStack.pop();
        s.push(currData);
    }

    if (s.empty()) {
        cout << "Item with ID " << id << " not found in the stack." << endl;
    }
}

// Function to search for an item in the stack based on ID
void search(stack<Data>& s) {
    int id;
    cout << "Enter the ID of the item to search for: ";
    cin >> id;

    stack<Data> tempStack;

    // Pop items from the original stack and push them onto a temporary stack
    // until the item to be searched for is found
    while (!s.empty()) {
        Data currData = s.top();
        s.pop();
        if (currData.id == id) {
            cout << "Item found:" << endl;
            cout << "ID: " << currData.id << endl;
            cout << "Name: " << currData.name << endl;
            cout << "Age: " << currData.age << endl;
            tempStack.push(currData);
            break;
        }
        else {
            tempStack.push(currData);
        }
    }

    // Pop items from the temporary stack and push them back onto the original stack
    while (!tempStack.empty()) {
        Data currData = tempStack.top();
        tempStack.pop();
        s.push(currData);
    }

    if (s.empty()) {
        cout << "Item with ID " << id << " not found in the stack." << endl;
    }
}

// Function to sort the items in the stack based on ID
void sort(stack<Data>& s) {
    if (s.empty()) {
        return;
    }

    stack<Data> tempStack;

    while (!s.empty()) {
        Data currData = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top().id > currData.id) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(currData);
    }

    // Pop items from the temporary stack and push them back onto the original stack
    while (!tempStack.empty()) {
        Data currData = tempStack.top();
        tempStack.pop();
        s.push(currData);
    }

    cout << "Stack sorted by ID!" << endl;
}

int main() {
    stack<Data> myStack;
    int choice;

    do {
        cout << "MENU" << endl;
        cout << "1. Add item" << endl;
        cout << "2. Delete item" << endl;
        cout << "3. Update item" << endl;
        cout << "4. Search item" << endl;
        cout << "5. Sort stack" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            add(myStack);
            break;
        case 2:
            deleteItem(myStack);
            break;
        case 3:
            update(myStack);
            break;
        case 4:
            search(myStack);
            break;
        case 5:
            sort(myStack);
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}