#include <iostream>
#include <math.h>
#define CAPACITY 100
using namespace std;

class MinMaxHeap
{
public:
	void Insert(int);
	void Print();
private:
	int arr[CAPACITY] = {0};
	int tail = 0;
};

void MinMaxHeap::Insert(int x) {
	// assume that the root is level 1.
	int current = ++tail;
	int parent;
	int parentLevel;
	int is_odd = true;  // min-heap levels
	if (current != 1) {
		parent = current / 2;
		parentLevel = log(current) / log(2);
		if (x > arr[parent]) is_odd = false;
		while (parent > 0) {
			if (parentLevel % 2 == is_odd && x < arr[parent] == is_odd) {
				arr[current] = arr[parent];
				current = parent;
			}
			parent /= 2;
			parentLevel--;
		}
	}
	arr[current] = x;
}

void MinMaxHeap::Print() {
	for (int i = 1; i <= tail; i++)
		cout << arr[i] << " ";
}

int main(int argc, char *argv[])
{   
    MinMaxHeap tree1;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; tree1.Insert(input);}
	tree1.Print();
}
