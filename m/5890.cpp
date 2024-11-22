#include<iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* link;
    ListNode() : data(0), link(0) {}
    ListNode(int x) : data(x), link(0) {}
    ListNode(int x, ListNode* link) : data(x), link(link) {}

};

class LinkedList {
public:
    LinkedList() :first(NULL), last(NULL) {

    }
    void InsertFirst(int x) {
        ListNode* newNode = new ListNode(x);
        if (first == NULL) {
            last = newNode;
        }
        else {
            newNode->link = first;
        }
        first = newNode;
    }
    void InsertLast(int x) {
        ListNode* newNode = new ListNode(x);
        if (last == NULL) {
            first = newNode;
        }
        else {
            last->link = newNode;
        }
        last = newNode;
    }
    int DeleteFirst() {
        ListNode* delNode = first;
        int returnVal = delNode->data;

        if (first == NULL) {

        }
        else if (first == last) {
            first = NULL;
            last = NULL;
        }
        else {
            first = first->link;
        }


        delete delNode;
        return returnVal;
    }
    int DeleteLast() {
        ListNode* delNode = last;
        int returnVal = delNode->data;

        if (last == NULL) {

        }
        else if (last == first) {
            first = NULL;
            last = NULL;
        }
        else {
            ListNode* temp = first;

            while (temp->link != last) {
                temp = temp->link;
            }
            last = temp;
            last->link = NULL;
        }

        delete delNode;
        return returnVal;
    }
    void PrintList() {
        ListNode* temp = first;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
public:
    ListNode* first;
    ListNode* last;
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* tail = dummyHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int digit1 = (l1 != nullptr) ? l1->data : 0;
        int digit2 = (l2 != nullptr) ? l2->data : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode* newNode = new ListNode(digit);
        tail->link = newNode;
        tail = tail->link;

        l1 = (l1 != nullptr) ? l1->link : nullptr;
        l2 = (l2 != nullptr) ? l2->link : nullptr;
    }

    ListNode* result = dummyHead->link;
    delete dummyHead;
    return result;
}

int main() {
    int times, number;
    LinkedList l1, l2;

    cin >> times >> number;
    l1.InsertFirst(number);
    for (int i = 0; i < times - 1; ++i) {
        cin >> number;
        l1.InsertFirst(number);
    }
    cin >> times >> number;
    l2.InsertFirst(number);
    for (int i = 0; i < times - 1; ++i) {
        cin >> number;
        l2.InsertFirst(number);
    }

    ListNode* ans = addTwoNumbers(l1.first, l2.first);

    while (ans != NULL) {
        cout << ans->data;
        ans = ans->link;
    }
}
