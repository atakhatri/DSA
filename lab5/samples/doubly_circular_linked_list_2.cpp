/* Doubly Circular Linked List in C++.
Essential Operations for Doubly Circular Linked List

    Insert at Beginning

    Insert at End

    Insert After a Node (by key)

    Delete from Beginning

    Delete from End

    Delete by Value

    Search for a Value

    Display Forward

    Display Backward

    Exit


*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyCircularLinkedList {
    Node* head;
public:
    DoublyCircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head->prev = head;
        } else {
            Node* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head->prev = head;
        } else {
            Node* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
        cout << "Inserted " << value << " at end.\n";
    }

    void insertAfter(int key, int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(value);
                Node* nextNode = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = nextNode;
                nextNode->prev = newNode;
                cout << "Inserted " << value << " after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Key " << key << " not found.\n";
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node* last = head->prev;
            head = head->next;
            head->prev = last;
            last->next = head;
        }
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* last = head->prev;
        if (last == head) {
            head = nullptr;
        } else {
            Node* secondLast = last->prev;
            secondLast->next = head;
            head->prev = secondLast;
        }
        cout << "Deleted " << last->data << " from end.\n";
        delete last;
    }

    void deleteByValue(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                if (temp->next == temp) {
                    head = nullptr;
                } else {
                    Node* prevNode = temp->prev;
                    Node* nextNode = temp->next;
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    if (temp == head)
                        head = nextNode;
                }
                cout << "Deleted " << key << ".\n";
                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Value " << key << " not found.\n";
    }

    void search(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Value " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Value " << key << " not found.\n";
    }

    void displayForward() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Forward: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }

    void displayBackward() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head->prev;
        cout << "Backward: ";
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << "\n";
    }
};

int main() {
    DoublyCircularLinkedList dcll;
    int choice, value, key;
    while (true) {
        cout << "\n--- Doubly Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete by Value\n";
        cout << "7. Search\n8. Display Forward\n9. Display Backward\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dcll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dcll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dcll.insertAfter(key, value);
                break;
            case 4:
                dcll.deleteFromBeginning();
                break;
            case 5:
                dcll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                dcll.deleteByValue(value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                dcll.search(value);
                break;
            case 8:
                dcll.displayForward();
                break;
            case 9:
                dcll.displayBackward();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
