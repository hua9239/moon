#include <math.h>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
   public:
    friend class BinTree;
    TreeNode(int a) {
        data = a;
        leftChild = rightChild = 0;
    };

   private:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

class BinTree {
   public:
    BinTree() { root = 0; }

    void BuildTree(vector<int> data, int n) {
        int tail = 0;  // tail 代表最後一個數值

        // step 1: 設定根結點，從 1 開始
        root = new TreeNode(data[0]);

        // step 2:for 是由 data數量決定
        for (int i = 1; i < n; i++) {
            TreeNode* currentNode = root;  // 所有都從根結點開始
            while (currentNode != 0) {
                // step 3: 遇到大的放右邊
                if (data[i] > currentNode->data)
                    if (currentNode->rightChild != 0)
                        currentNode = currentNode->rightChild;
                    else {
                        currentNode->rightChild = new TreeNode(data[i]);
                        break;
                    }

                // step 4: 遇到小的放左邊
                else if (data[i] < currentNode->data)
                    if (currentNode->leftChild != 0)
                        currentNode = currentNode->leftChild;
                    else {
                        currentNode->leftChild = new TreeNode(data[i]);
                        break;
                    }
            }
        }
    }
    void Plot();

   private:
    TreeNode* root;
};

void BinTree::Plot() {
    int MAX_HEIGHT = 7, CHAR_SPACE = 2;
    int capacity = pow(2, MAX_HEIGHT);
    vector<int> arr(capacity);
    queue<TreeNode*> q;
    queue<int> index_q;
    q.push(root);
    index_q.push(1);
    TreeNode* currentNode;
    int currentIndex, tail = 0;
    while (!q.empty()) {
        currentNode = q.front();
        q.pop();
        currentIndex = index_q.front();
        index_q.pop();
        arr[currentIndex] = currentNode->data;
        if (tail < currentIndex)
            tail = currentIndex;
        if (currentNode->leftChild) {
            q.push(currentNode->leftChild);
            index_q.push(currentIndex * 2);
        }
        if (currentNode->rightChild) {
            q.push(currentNode->rightChild);
            index_q.push(currentIndex * 2 + 1);
        }
    }
    int i, sps;
    int max_level = log(tail) / log(2) + 1;
    for (int lv = 1; lv <= max_level; lv++) {
        sps = pow(2, max_level - lv) * CHAR_SPACE;
        i = pow(2, lv - 1);
        cout << setw(sps);
        if (arr[i])
            cout << arr[i];
        else
            cout << " ";
        sps *= 2;
        for (i++; i <= pow(2, lv) - 1; i++) {
            cout << setw(sps);
            if (arr[i])
                cout << arr[i];
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    BinTree tree1;
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Plot();
}