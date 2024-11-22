#include <iostream>
using namespace std;

class Queue {
   public:
    int *arr, rear, front;

    Queue() {
        arr = new int[10];
        rear = -1;
        front = -1;
    }

    // The variable x is added to the back of the queue
    void Enqueue(int x) { arr[++rear] = x; }
    // The variable x is deleted to the back of the queue
    void Dequeue() { arr[++front] = 0; }

    // print all of number in array
    void PrintQueue() {
        for (int i = front + 1; i <= rear; i++)
            cout << arr[i] << " ";
    }
};

int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for (int i = 0; i < times; i++) {
        queue.Dequeue();
    }
    queue.PrintQueue();
}
