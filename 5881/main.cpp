#include <iostream>
#define CAPACITY 100
using namespace std;

class MaxHeap
{
public:
	void Insert(int);
	int Delete();
	void Print();
private:
	int arr[CAPACITY];
	int tail = 0;
};

void MaxHeap::Insert(int x) {
	int current = ++tail;
	while (current != 1 && arr[current / 2] < x) {				
		arr[current] = arr[current / 2];				
		current /= 2;
	}
	arr[current] = x;
}

int MaxHeap::Delete() {
	int rt_val = arr[1];
	// Move the last element to the first
	arr[1] = arr[tail];
	arr[tail--] = 0;
	
	int current = 1;
	while (current < tail && (arr[current] < arr[current*2] || arr[current] < arr[current*2+1])) {
		if (arr[current*2] > arr[current*2+1]) {
			swap(arr[current], arr[current*2]);
			current = current * 2;
		}
		else {
			swap(arr[current], arr[current*2+1]);
			current = current * 2 + 1;
		}
	}
	return rt_val;
}

void MaxHeap::Print() {
	for (int i = 1; i <= tail; i++)
		cout << arr[i] << " ";
}

int main(int argc, char *argv[])
{   
    MaxHeap tree1;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; tree1.Insert(input);}
    for(cin >> times; times > 0; times--) {tree1.Delete();}
	tree1.Print();
}