#include <iostream>
using namespace std;

class Stack {
   public:
    // constructor
    Stack() {
        capacity = 10;
        array = new int[capacity];
        top = -1;
    }

    void Push(int x) {
        if (top + 1 < capacity)
            array[++top] = x;
    }

    int Pop() {
        if (top >= 0)
            return array[top--];
    }

    void PrintStack() {
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
    }

   private:
    int capacity;
    int* array;
    int top;
};

int main(int argc, char* argv[]) {
    Stack stack;
    int times, input;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> input;
        stack.Push(input);
    }
    cin >> times;
    for (int i = 0; i < times; i++) {
        stack.Pop();
    }
    stack.PrintStack();
}