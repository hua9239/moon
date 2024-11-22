#include <iostream>
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
	void Preorder(TreeNode*);
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
				else current = current->rightChild;
			else if (data[i] < current->data)
				if (current->leftChild == 0) {
					current->leftChild = new TreeNode(data[i]);
					break;
				}
				else current = current->leftChild;
		}
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

int main(int argc, char *argv[])
{   
    BinTree tree1;
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Preorder(tree1.returnRoot());
}
