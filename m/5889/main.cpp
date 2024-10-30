#include <iostream>
using namespace std;

class ListNode
{
public:
  ListNode(int a):data(a),link(0) {}
private:
  int data;
  ListNode* link;
  friend class LinkedList;
};

class LinkedList
{
public:
  LinkedList():first(0),last(0) {}
  void InsertFirst(int x) {
    ListNode* newNode = new ListNode(x);
    newNode->link = first;
    first = newNode;
    if (last == 0) last = newNode;
  }
  void Insert(int location, int x) {
    ListNode* newNode = new ListNode(x);
    ListNode* temp = first;

    if (location == 0)
      InsertFirst(x);
    else {
      for (int i = 0; i < location -1; ++i)
        temp = temp->link;
      newNode->link = temp->link;
      temp->link = newNode;
    }
  }
  void PrintList() {
    ListNode* current = first;
    while (current != 0) {
      cout << current->data << " ";
      current = current->link;
    }
  }
private:
  ListNode* first;
  ListNode* last;
};

int main(int argc, char* argv[])
{
  LinkedList list;
  int times, input, location;
  for (cin >> times; times > 0; times--) {
    cin >> input; 
    list.InsertFirst(input); 
  }
  cin >> location >> input;
  list.Insert(location, input);
  list.PrintList();
}