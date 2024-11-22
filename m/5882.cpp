#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode(int a) {data = a; link = 0;}
private:
	int data;
	ListNode *link;
	friend class CircularList;
};

class CircularList
{
public:
    CircularList() {last = 0;};
	void InsertFirst(int);
	void PrintList();
private:
	ListNode *last;
};

void CircularList::InsertFirst(int x) {
	ListNode *newNode = new ListNode(x);
	if (last == 0) last = newNode;
	newNode->link = last->link;
	last->link = newNode;
}

void CircularList::PrintList() {
	if (last != 0) {
	    ListNode *current = last;
	    do {
	    	current = current->link;
	    	cout << current->data << " ";
	    } while (current != last);
	}
}

int main(int argc, char *argv[])
{
    CircularList list;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; list.InsertFirst(input);}
    list.PrintList();
}
