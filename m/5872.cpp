#include <iostream>
using namespace std;

class ListNode {
   public:
    ListNode(int a) {
        // 代表node所儲存資料
        data = a;

        // link 還未連接
        link = 0;
    }

   private:
    int data;
    ListNode* link;
    friend class LinkedList;
};

class LinkedList {
   public:
    LinkedList() {
        first = 0;
        last = 0;
    }

    //開頭新增值為x的資料
    void InsertFirst(int x) {
        // 有一個node儲存著資料x
        ListNode* newNode = new ListNode(x);
        if (last == 0)
            last = newNode;
        newNode->link = first;  // 取代原先的first, 順序會為 newNode -> first
        first = newNode;
    }

    //最後新增值為x的資料
    void InsertLast(int x) {
        // 有一個node儲存著資料x
        ListNode* newNode = new ListNode(x);

        // 還未任何資料
        if (last == 0)
            first = newNode;
        // 有資料了
        else
            last->link = newNode;

        last = newNode;
    }

    //刪除開頭一筆資料，並回傳刪除資料的值
    int DeleteFirst() {
        ListNode* deleNode = first;
        int rt_Num = first->data;  // 預計回傳的值

        // 若沒有下一個節點了 = 只有一個節點的話，也將last 清空 = 此鏈結串鍊清空
        if (first == last) {
            last = 0;
            first = 0;
        } else
            first = first->link;  // first　轉為下一個節點

        delete deleNode;
        return rt_Num;
    }

    //刪除最後一筆資料，並回傳刪除資料的
    int DeleteLast() {
        ListNode* deleNode = last;
        int rt_Num = last->data;

        // 只有一個節點
        if (first == last) {
            first = 0;
            last = 0;
        } else {
            ListNode* currentNode = first;

            // 直到下一個是last 之前一直執行 = 會獲得倒數第二個node
            while (currentNode->link != last) {
                currentNode = currentNode->link;
            }
            currentNode->link = 0;
            last = currentNode;
        }

        delete deleNode;
        return rt_Num;
    }

    void Reverse() {
        ListNode *current = first, *prev = 0, *next = 0;

        while (current != 0) {
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }
        first = prev;
    }
    //過Traversal的方式將所有資料依序印出。
    void PrintList() {
        ListNode* currentNode = first;
        while (currentNode != 0) {
            cout << currentNode->data << " ";
            currentNode = currentNode->link;
        }
        cout << endl;
    }
    /*
        void PrintList() {
            ListNode* d_temp = first;
            for (; d_temp; d_temp = d_temp->link)
                cout << d_temp->data << " ";
            cout << endl;
        }
    */
   private:
    ListNode* first;  // 第一個節點
    ListNode* last;   //最後一個節點
};

class Stack {
   public:
    Stack() {}

    void Push(int x) { stack.InsertLast(x); }
    int Pop() {
        int num = stack.DeleteLast();
        return num;
    }
    void PrintStack() { stack.PrintList(); }

   private:
    LinkedList stack;
};
int main(int argc, char* argv[]) {
    Stack stack;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        stack.Push(input);
    }
    for (cin >> times; times > 0; times--)
        stack.Pop();
    stack.PrintStack();
}
