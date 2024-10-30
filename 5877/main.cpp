#include <iostream>
#define CAPACITY 100
using namespace std;

class BinTree
{
public:
	void BuildTree(int[], int);
	void Print();
private:
	int arr[CAPACITY];
	int tail;
};

void BinTree::BuildTree(int data[], int n) {
	// initial
	for (int i = 0; i < CAPACITY; i++) arr[i] = 0;
	tail = 0;
	// set root
	arr[1] = data[0];
	
	for (int i = 1; i < n; i++) {
		int node = 1;
		// search placement
		while(arr[node] != 0) {
			if (data[i] > arr[node])
				node = 2 * node + 1;
			else
				node = 2 * node;
			// set tail
			if (tail < node) tail = node;
		}
		arr[node] = data[i];
	}
}

void BinTree::Print() {
	for (int i = 1; i <= tail; i++)
		cout << arr[i] << " ";
}

int main(int argc, char *argv[])
{   
    BinTree tree1;
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    //int n = 8;
    //int data[n] = {4, 6, 5, 9, 7, 11, 2, 1};
    tree1.BuildTree(data, n);
    tree1.Print();
}