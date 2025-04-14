#include <iostream>

const int MAX_SIZE = 10;

class Queue {
public:
    int data[MAX_SIZE];
    int front = 0;
    int rear = -1;
    int size = 0;


    void enqueue(int value) {
        if (size < MAX_SIZE) {
            rear = (rear + 1) % MAX_SIZE;
            data[rear] = value;
            size++;
            std::cout << "Enqueued: " << value << std::endl;
        } else {
            std::cout << "Queue is full!" << std::endl;
        }
    }


    void dequeue() {
        if (size > 0) {
            std::cout << "Dequeued: " << data[front] << std::endl;
            front = (front + 1) % MAX_SIZE;
            size--;
        } else {
            std::cout << "Queue is empty!" << std::endl;
        }
    }


    void reverseFirstK(int k) {
        if (k > size) {
            std::cout << "Not enough elements to reverse!" << std::endl;
            return;
        }

        int start = front;
        int end = (front + k - 1) % MAX_SIZE;

        while (start < end) {
            int temp = data[start];
            data[start] = data[end];
            data[end] = temp;

            start = (start + 1) % MAX_SIZE;
            if (start == end) break;
            end = (end - 1 + MAX_SIZE) % MAX_SIZE;
        }

        std::cout << "First " << k << " elements reversed." << std::endl;
        displayQueue();
    }


    void interleaveHalves() {
        if (size <= 1) {
            std::cout << "Not enough elements to interleave!" << std::endl;
            return;
        }

        int mid = size / 2;
        int temp[MAX_SIZE];

        int i = front;
        int j = (front + mid) % MAX_SIZE;
        int k = 0;

        while (k < size) {
            temp[k++] = data[i];
            i = (i + 1) % MAX_SIZE;

            if (k < size) {
                temp[k++] = data[j];
                j = (j + 1) % MAX_SIZE;
            }
        }

        for (int i = 0; i < size; i++) {
            data[(front + i) % MAX_SIZE] = temp[i];
        }

        std::cout << "Halves interleaved." << std::endl;
        displayQueue();
    }


    void displayQueue() {
        std::cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            std::cout << data[(front + i) % MAX_SIZE] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue queue;


    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.displayQueue();

    queue.reverseFirstK(3);

    queue.interleaveHalves();

    queue.dequeue();
    queue.dequeue();

    queue.displayQueue();

    return 0;
}
