#include <iostream>
using namespace std;

class ListNode {
   public:
    ListNode(int a) {
        data = a;
        link = 0;
    }

   private:
    int data;
    ListNode* link;
    friend class CircularList;
};

class CircularList {
   public:
    CircularList() { last = 0; }

    void InsertFirst(int x) {
        ListNode* newNode = new ListNode(x);

        // 鏈結串列為空的時候 last = newNode
        if (last == 0)
            last = newNode;
        newNode->link = last->link;  // 其實就等於 newNode->link = first
        last->link = newNode;        // first = newNode
    }
    void InsertLast(int x) {
        ListNode* newNode = new ListNode(x);
        if (last == 0)
            last = newNode;

        newNode->link = last->link;
        last->link = newNode;
        last = newNode;
    }
    int DeleteFirst() {
        ListNode* deleNode = last->link;
        int rt_num = deleNode->data;
        last->link = deleNode->link;

        if (last == deleNode)
            last = 0;

        return rt_num;
    }
    int DeleteLast() {
        ListNode* deleNode = last;
        int rt_num = deleNode->data;
        ListNode* currentNode = last->link;

        if (currentNode == deleNode)
            last = 0;
        else {
            while (currentNode->link != last) {
                currentNode = currentNode->link;
            }
            currentNode->link = last->link;
            last = currentNode;
        }

        delete deleNode;
        return rt_num;
    }
    void PrintList() {
        ListNode* currentNode = last->link;
        for (; currentNode != last; currentNode = currentNode->link)
            cout << currentNode->data << " ";
        cout << last->data;
    }

   private:
    ListNode* last;
};

int main(int argc, char* argv[]) {
    CircularList list;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        list.InsertFirst(input);
    }
    for (cin >> times; times > 0; times--)
        list.DeleteFirst();
    for (cin >> times; times > 0; times--) {
        cin >> input;
        list.InsertLast(input);
    }
    for (cin >> times; times > 0; times--)
        list.DeleteLast();
    list.PrintList();
}