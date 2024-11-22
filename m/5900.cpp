#include <iostream>
using namespace std;
class LinkedList;
class ListNode
{
public:
	ListNode(int a) {data = a; link = 0;}
private:
	int data;
	ListNode *link;
	friend class LinkedList;
};

class LinkedList
{
public:
	void InsertFirst(int);
	void InsertLast(int);
	int DeleteFirst();
	int DeleteLast();
	void PrintList();
private:
	ListNode *first = 0;
	ListNode *last = 0;
};

void LinkedList::InsertFirst(int x) {
	ListNode *newNode = new ListNode(x);
	newNode->link = first;
	first = newNode;
	if (last == 0) last = newNode;
}

void LinkedList::InsertLast(int x) {
	ListNode *newNode = new ListNode(x);
	if (last == 0)
		first = newNode;
	else
		last->link = newNode;
	last = newNode;
}

int LinkedList::DeleteFirst() {
	ListNode *oldNode = first;
	first = first->link;
	if (first == 0) last = 0;
	int rt_val = oldNode->data;
	delete oldNode;
	return rt_val;
}

int LinkedList::DeleteLast() {
	ListNode *oldNode = last;
	if (first == last) {
		first = 0;
		last = 0;
	}
	else {
		ListNode *current = first;
		while(current->link != last) {
			current = current->link;
		}
		current->link = 0;
		last = current;
	}
	int rt_val = oldNode->data;
	delete oldNode;
	return rt_val;
}

void LinkedList::PrintList() {
    ListNode *current = first;
    while (current != 0) {
    	cout << current->data << " ";
    	current = current->link;
	}
	cout << endl;
}

class Queue
{ 
public:
    void Enqueue(int);
	int Dequeue();
	void PrintQueue();
private:
	LinkedList list;
};

void Queue::Enqueue(int x) {
    list.InsertLast(x);
}

int Queue::Dequeue() {
    return list.DeleteFirst();
}

void Queue::PrintQueue() {
    list.PrintList();
}

int main(int argc, char *argv[])
{
    Queue queue;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; queue.Enqueue(input);}
    for(cin >> times; times > 0; times--) queue.Dequeue();
    queue.PrintQueue();
}
