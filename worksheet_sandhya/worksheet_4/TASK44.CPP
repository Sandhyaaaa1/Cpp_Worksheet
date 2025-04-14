#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head = nullptr;


    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }


    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }


    void insertAtPosition(int value, int pos) {
        Node* newNode = new Node(value);
        if (pos == 0) {
            insertAtStart(value);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Position exceeds list length!" << std::endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }


    void detectAndRemoveLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                std::cout << "Loop detected!" << std::endl;


                slow = head;
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = nullptr;
                std::cout << "Loop removed." << std::endl;
                return;
            }
        }

        std::cout << "No loop found." << std::endl;
    }


    void findNthNodeFromEnd(int n) {
        Node* mainPtr = head;
        Node* refPtr = head;

        for (int i = 0; i < n; i++) {
            if (refPtr == nullptr) {
                std::cout << "n is greater than the no. of nodes in list" << std::endl;
                return;
            }
            refPtr = refPtr->next;
        }

        while (refPtr != nullptr) {
            mainPtr = mainPtr->next;
            refPtr = refPtr->next;
        }

        if (mainPtr != nullptr) {
            std::cout << "Node no. " << n << " from the end is " << mainPtr->data << std::endl;
        }
    }


    void reverseInGroupsOfK(int k) {
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (current != nullptr) {
            Node* first = current;
            Node* last = current;


            for (int i = 0; i < k - 1 && current != nullptr; i++) {
                current = current->next;
            }

            if (current == nullptr) break;

            last = current;
            current = current->next;


            Node* prevGroup = nullptr;
            Node* nextGroup = nullptr;
            for (int i = 0; i < k; i++) {
                nextGroup = first->next;
                first->next = prevGroup;
                prevGroup = first;
                first = nextGroup;
            }


            if (head == last) {
                head = prevGroup;
            } else {
                Node* temp = head;
                while (temp->next != last) {
                    temp = temp->next;
                }
                temp->next = prevGroup;
            }

            last->next = current;
            prevGroup = last;
        }

        std::cout << "List reversed in groups of " << k << "." << std::endl;
        displayList();
    }


    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;


    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    std::cout << "Initial List: ";
    list.displayList();

    list.insertAtStart(0);
    std::cout << "After inserting at start: ";
    list.displayList();

    list.insertAtPosition(6, 3);
    std::cout << "After inserting at position: ";
    list.displayList();

    list.detectAndRemoveLoop();

    list.findNthNodeFromEnd(2);

    list.reverseInGroupsOfK(2);
    std::cout << "Final List: ";
    list.displayList();

    return 0;
}
