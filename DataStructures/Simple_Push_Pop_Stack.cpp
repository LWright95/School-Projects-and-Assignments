#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;

class s()
{
public:
	int stack[5] = {};
	int top = -1;
}

void Push(int x)
{
	stack[++top] = x;
}

Pop()
{
	top--;
}

int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	cout << "stack: " << pop() <<" "<<pop() <<" "<<pop() << " " << pop() << " " << pop() << endl;

	system "Pause"
	return 0;
}
