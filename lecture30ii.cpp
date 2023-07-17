#include <iostream>
using namespace std;

class Queue {
public:
    int queue[1000];
    int size;
    int front;
    int rear;
    int max_capacity;

    Queue() {
        this->front = 0;
        this->rear = -1;
        this->max_capacity = 1000;
        this->size = 0;
    }

    void enqueue(int data) {
        if (size == max_capacity) {
            cout << "Maximum capacity has been reached." << endl;
            return;
        }

        rear = (rear + 1) % max_capacity;
        queue[rear] = data;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "The size of the queue is 0, and there are no more elements." << endl;
            return;
        }

        cout << "The element to be dequeued is " << queue[front] << endl;
        front = (front + 1) % max_capacity;
        size--;
    }

    void peekQueue() {
        if (size == 0) {
            cout << "The queue is empty." << endl;
            return;
        }

        cout << "The element at the front of the queue is " << queue[front] << endl;
    }

    void sizeOfQueue() {
        cout << "The queue currently has " << size << " element(s) in it." << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(1);

    q.dequeue();
    q.dequeue();

    q.peekQueue();

    q.dequeue();

    q.peekQueue();

    q.dequeue();

    q.sizeOfQueue();

    return 0;
}
