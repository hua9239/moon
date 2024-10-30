#include <iostream>
using namespace std;

class Queue {
   public:
    int *arr, rear, front;

    Queue() {
        arr = new int[10];
        rear = 0;
        front = 0;
    }

    // The variable x is added to the back of the queue
    void Enqueue(int x) {
        if (rear == 9)
            rear = -1;

        arr[++rear] = x;
    }
    // The variable x is deleted to the back of the queue
    void Dequeue() {
        if (front == 9)
            front = -1;
        arr[++front] = 0;
    }

    // print all of number in array
    void PrintQueue() {
        int i;
        for ((front == 9) ? i = 0 : i = front + 1; i != rear + 1;
             (i < 9) ? i++ : i = 0)
            cout << arr[i] << " ";
        cout << "rear:" << rear << " front:" << front;
    }
};

int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;
    for (int i = 0; i < 2; i++) {
        cin >> times;
        for (int j = 0; j < times; j++) {
            cin >> input;
            queue.Enqueue(input);
        }
        cin >> times;
        for (int j = 0; j < times; j++) {
            queue.Dequeue();
        }
    }
    queue.PrintQueue();
}