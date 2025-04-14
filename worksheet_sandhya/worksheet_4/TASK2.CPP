#include <iostream>

const int MAX_SIZE = 10;

class Stack {
public:
    int data[MAX_SIZE];
    int top = -1;

    void push(int value) {
        if (top < MAX_SIZE - 1) {
            top++;
            data[top] = value;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
    }

    int findMiddle() {
        if (top >= 0) {
            return data[top / 2];
        }
        return -1;
    }

    void reverseBottomHalf() {
        if (top >= 0) {
            int middle = top / 2;
            for (int i = 0; i < middle; i++) {
                int temp = data[i];
                data[i] = data[middle - i - 1];
                data[middle - i - 1] = temp;
            }
        }
    }

    void displayStack() {
        for (int i = 0; i <= top; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(4);
    stack.push(6);
    stack.push(8);


    std::cout << "Stack: ";
    stack.displayStack();

    std::cout << "Middle element: " << stack.findMiddle() << std::endl;

    stack.reverseBottomHalf();

    std::cout << "After reversing bottom half: ";
    stack.displayStack();

    stack.pop();
    stack.pop();

    std::cout << "After popping two elements: ";
    stack.displayStack();

    return 0;
}
