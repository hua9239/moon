#include <iostream>
#define CAPACITY 10
using namespace std;

class Queue {
   public:
    void Enqueue(int);
    int Dequeue();
    void PrintQueue();

   private:
    int arr[CAPACITY];
    int rear = 0;
    int front = 0;
};

// 1-10, 2-20, 3-30, 4-40, 5-50, 6-60, 7-70, 8-80, 9-90, 0-100, 1-110
void Queue::Enqueue(int x) {
    if ((rear + 1) % CAPACITY != front) {
        rear = (rear + 1) % CAPACITY;
        arr[rear] = x;
    }
}

int Queue::Dequeue() {
    if (front != rear) {
        front = (front + 1) % CAPACITY;
        return arr[front];
    }
}

void Queue::PrintQueue() {
    for (int i = front + 1; (rear < front) ? i <= rear + 10 : i <= rear; i++)
        cout << arr[i % 10] << " ";
    cout << "rear:" << rear << " front:" << front << endl;
}

int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        queue.Enqueue(input);
    }
    for (cin >> times; times > 0; times--)
        queue.Dequeue();
    for (cin >> times; times > 0; times--) {
        cin >> input;
        queue.Enqueue(input);
    }
    for (cin >> times; times > 0; times--)
        queue.Dequeue();
    queue.PrintQueue();
}