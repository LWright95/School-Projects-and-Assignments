#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Node
{
	public:
		Node(){}
		void setName(string n) { name = n; }
		void setNext(Node* ptr) { next = ptr; }
		void setPrev(Node* ptr) { prev = ptr; }
		string getName() { return name; }
		Node* getNext() { return next; }
		Node* getPrev() { return prev; }

	private:
		string name;
		Node* next;
		Node* prev;
};

typedef Node* NodePtr;
NodePtr Insert(Node* a, Node* b, string n) 
{
	a = new Node;
	a->setName(n);
	a->setNext(NULL);
	a->setPrev(b);
	return b;
};


int main()
{
	NodePtr head;
	NodePtr middle;
	NodePtr tail;
	head = new Node;
	head->setName("Marvin");
	head->setNext(NULL);
	head->setPrev(NULL);

	
    Insert(middle, head, "Gary");
    
    Insert(tail, middle, "Linda");
    
	system("pause");
    return 0;
}


