#include<iostream>
#include<cstdlib>
using namespace std;

class Tree
{
public:
	struct binaryTree
	{
		int data;
		binaryTree* left;
		binaryTree* right;
		binaryTree* root;
	};

	void insert(int data, binaryTree* a, binaryTree* b)
	{
		if (root == NULL)
		{
			new a(data)->root;
			a.left->NULL;
			a->right->NULL;
		}
		else if (data < a->data)
		{
			new b(data);
			a.left->b;
			b.left->NULL;
			b.right->NULL;
		}
		else if (data > a->data)
		{
			new b(data);
			a.right ->b;
			b.left->NULL;
			b.right->NULL;
		}
	};
	void preorder(binaryTree* root)
	{
		if (root == NULL)
			return;
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	Tree T;
	T.insert(50, alex);
	T.insert(30, alex, brandon);
	T.insert(15, brandon, charles);
	T.insert(40, brandon, barry);
	T.insert(80, alex, george);
	T.insert(70, george, gary);
	T.insert(90, george, luther);
	T.preorder(alex);
	T.preorder(brandon); 
	T.preorder(charles); 
	T.preorder(barry); 
	T.preorder(george);
	T.preorder(gary);
	T.preorder(luther);

	system("pause");
	return 0;
}
