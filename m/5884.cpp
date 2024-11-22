#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
using namespace std;
class TreeNode
{
public:
	friend class BinTree;
	TreeNode(char a) { data = a; leftChild = rightChild = 0; };
private:
	char data;
	TreeNode* leftChild;
	TreeNode* rightChild;
};
class BinTree
{
private:
	TreeNode* root=0;
public:
	void BuildTree(char[],int);
	void Plot();
};
void BinTree::BuildTree(char data[],int n)
{
	TreeNode* newNode = new TreeNode(data[0]);
	root = newNode;
	for (int i = 1; i < n; i++)
	{	
		TreeNode* current = root;
		while (true)
		{	
			if (data[i]>(current->data))
			{
				TreeNode* newNode = new TreeNode(data[i]);   // ?t?m?s???O????
				if(current->rightChild==0)
				{
					current->rightChild = newNode;
					break;	
				}
				current=current->rightChild;
			}
			else
			{
				TreeNode* newNode = new TreeNode(data[i]);   // ?t?m?s???O????
				if(current->leftChild==0)
				{	
					current->leftChild = newNode;
					break;
				}
				current=current->leftChild;
			}
		}
	}
}
void BinTree::Plot() {
	int MAX_HEIGHT = 7, CHAR_SPACE = 2;
	int capacity = pow(2, MAX_HEIGHT);
	char* arr = new char[capacity] {};
	queue<TreeNode*> q;
	queue<char> index_q;
	q.push(root);
	index_q.push(1);
	TreeNode* currentNode;
	int currentIndex, tail = 0;
	while (!q.empty()) {
		currentNode = q.front(); q.pop();
		currentIndex = index_q.front(); index_q.pop();
		arr[currentIndex] = currentNode->data;
		if (tail < currentIndex) tail = currentIndex;
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
		if (arr[i]) cout << arr[i] << " "; else cout << " ";
		sps *= 2;
		for (i++; i <= pow(2, lv) - 1; i++) {
			cout << setw(sps);
			if (arr[i]) cout << arr[i] << " "; else cout << " ";
		}
		cout << endl;
	}
}
int main(int argc, char* argv[])
{
	BinTree tree1;
	int n;
	cin >> n;
	char* data = new char[n];
	for (int i = 0; i < n; i++) 
	{
		int x;
		cin>>x;
		data[i]=char(x);
	}
	tree1.BuildTree(data, n);
	tree1.Plot();
}
