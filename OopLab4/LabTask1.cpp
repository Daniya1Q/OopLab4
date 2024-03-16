#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

  
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Search
    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Reverse
    void reverse() {
        Node* prev = nullptr, * current = head, * nextNode = nullptr;
        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    // Display
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    cout << "Original list: ";
    list.display();

    // Search for value
    int value;
    cout << "Enter a value to search for: ";
    cin >> value;
    cout << "Search for value " << value << ": " << (list.search(value) ? "Found" : "Not Found") << endl;

    // Reverse the list
    list.reverse();
    cout << "Reversed list: ";
    list.display();

    return 0;
}
