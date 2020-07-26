#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node
{
	char data;
	unsigned freq;
	Node* left;
	Node* right;
	Node(char data, unsigned freq)
	{
		left = NULL;
		right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(Node* l, Node* r)
	{
		return(l->freq > r->freq);
	}
};

void printCode(Node* root, string str)
{
	if (root == NULL)
		return;

	if (root->data == '$')
	{
		printCode(root->left, str + "0");
		printCode(root->right, str + "1");
	}

	if (root->data != '$')
	{
		cout << root->data << " : " << str << "\n";
		printCode(root->left, str + "0");
		printCode(root->right, str + "1");
	}
}

Node* top;

void huff(char data[], int freq[], int size)
{
	Node* left;
	Node* right;
	priority_queue<Node*, vector<Node*>, compare > minHeap;
	for (int i = 0; i < size; ++i)
	{
		minHeap.push(new Node(data[i], freq[i]));
	}

	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new Node('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	printCode(minHeap.top(), "");
}

int main()
{
	char a[] = { 'a','b','c','d','e','f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };
	int size = sizeof(a) / sizeof(a[0]);
	huff(a, freq, size);

	return 0;
}
