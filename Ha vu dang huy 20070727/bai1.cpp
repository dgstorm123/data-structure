//bai1
#include <iostream>
using namespace std;

// Removing all nodes
struct Node {
    int data;
    Node *next;
};

Node* removeNodes(Node* head, int key) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) {
        if(curr->data == key) {
            if(prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

//Adding a node to a linked list
Node* addNode(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

//Deleting all nodes 
Node* deleteNodesGreaterThan(Node* head, int value) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) {
        if(curr->data > value) {
            if(prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

//Reversing
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//Searching algorithm
bool search(Node* head, int key) {
    Node* curr = head;
    while(curr != NULL) {
        if(curr->data == key) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

//Sorting algorithm
void sortList(Node* head) {
    if(head == NULL || head->next == NULL) {
        return;
    }
    Node* curr = head;
    while(curr != NULL) {
        Node* minNode = curr;
        Node* temp = curr->next;
        while(temp != NULL) {
            if(temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        }
        int tempData = curr->data;
        curr->data = minNode->data;
        minNode->data = tempData;
        curr = curr->next;
    }
}


void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, new Node{2, NULL}}}}}};
    
    cout << "Original List: ";
    printList(head);
    
    
    head = removeNodes(head, 5);
    
    cout << "\nRemove List: ";
    printList(head);
    
    cout << "---------------- \n";
    
    head = addNode(head, 8);
    cout << "Add List: ";
    printList(head);
    
    cout << "---------------- \n";
    
	head = deleteNodesGreaterThan(head, 8); 
	cout << "Delete List: ";
    printList(head);
cout << "---------------- \n";
    
    head = reverseList(head);
    cout << "Reverse List: ";
    printList(head);
    
    cout << "---------------- \n";
    
    cout << "Search ----\n";
    int key = 8;
    if(search(head, key)) {
        cout << "Key " << key << " found in the list." << endl;
    } else {
        cout << "Key " << key << " not found in the list." << endl;
    }
    
    key = 5;
    if(search(head, key)) {
        cout << "Key " << key << " found in the list." << endl;
    } else {
        cout << "Key " << key << " not found in the list." << endl;
    }
    
    cout << "--------------\n ";
    
    cout << "Unsorted list: ";
    printList(head);

    // Sorting the list
    sortList(head);

    // Printing the sorted list
    cout << "Sorted list: ";
    printList(head);
    
    return 0;
}
