#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
using namespace std;

class TreeNode
{
public:
	friend class BinTree;
	TreeNode(int a) {data = a; leftChild = rightChild = 0;};
private:
	int data;
	TreeNode *leftChild;
	TreeNode *rightChild;
};

class BinTree
{
public:
	void BuildTree(int[], int);
	void Inorder(TreeNode*);
	void Preorder(TreeNode*);
	void Postorder(TreeNode*);
	TreeNode *returnRoot() {return root;};
	void Plot();
private:
	TreeNode *root;
};

void BinTree::BuildTree(int data[], int n) {
	// set root
	root = new TreeNode(data[0]);
	TreeNode *current = root;
	for (int i = 1; i < n; i++) {
		TreeNode *current = root;
		while(true) {
			if (data[i] > current->data)
				if (current->rightChild == 0) {
					current->rightChild = new TreeNode(data[i]);
					break;
				}
				else
					current = current->rightChild;
			else if (data[i] < current->data)
				if (current->leftChild == 0) {
					current->leftChild = new TreeNode(data[i]);
					break;
				}
				else
					current = current->leftChild;
		}
	}
}

void BinTree::Inorder(TreeNode *currentNode)
{
	if (currentNode != NULL) {
		Inorder(currentNode->leftChild);
		cout << currentNode->data << " ";
		Inorder(currentNode->rightChild);
	}
}

void BinTree::Preorder(TreeNode *currentNode)
{
	if (currentNode != NULL) {
		cout << currentNode->data << " ";
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}

void BinTree::Postorder(TreeNode *currentNode)
{
	if (currentNode != NULL) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		cout << currentNode->data << " ";
	}
}

void BinTree::Plot() {
	int MAX_HEIGHT = 7, CHAR_SPACE = 2;
	int capacity = pow(2, MAX_HEIGHT);
	int arr[capacity] = {};
	queue<TreeNode*> q;
	queue<int> index_q;
	q.push(root);
	index_q.push(1);
	TreeNode *currentNode;
	int currentIndex, tail = 0;
	while(!q.empty()) {
		currentNode = q.front(); q.pop();
		currentIndex = index_q.front(); index_q.pop();
		arr[currentIndex] = currentNode->data;
		if (tail < currentIndex) tail = currentIndex;
		if (currentNode->leftChild) {
			q.push(currentNode->leftChild);
			index_q.push(currentIndex * 2);}
		if (currentNode->rightChild) {
			q.push(currentNode->rightChild);
			index_q.push(currentIndex * 2 + 1);}
	}
	int i, sps;
	int max_level = tail == 1 ? 1 : sqrt(tail) + 1;
	for (int lv = 1; lv <= max_level; lv++) {
		sps = pow(2, max_level - lv) * CHAR_SPACE;
		i = pow(2, lv - 1);
		cout << setw(sps);
		if (arr[i]) cout << arr[i]; else cout << " ";
		sps *= 2;
		for (i++; i <= pow(2, lv) - 1; i++) {
			cout << setw(sps);
			if (arr[i]) cout << arr[i]; else cout << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{   
    BinTree tree1;
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    //int n = 10;//8
    //int data[n] = {8, 4, 12, 2, 5, 3, 10, 11, 14, 13};//{4, 6, 5, 9, 7, 11, 2, 1};
    tree1.BuildTree(data, n);
	//tree1.Plot();
    tree1.Inorder(tree1.returnRoot()); cout << endl;
    tree1.Preorder(tree1.returnRoot()); cout << endl;
    tree1.Postorder(tree1.returnRoot()); cout << endl;
}
