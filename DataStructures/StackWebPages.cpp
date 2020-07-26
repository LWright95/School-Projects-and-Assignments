#include<iostream>
#include<cstdlib>
#include<stack>
#include<string>
#include<fstream>
using namespace std;

int main ()
{
	stack<string>webpage;

	ofstream a;
	a.open("webpage1.html");
	a << "<html>webpage one\n</html>";
	a.close();

	ofstream b;
	b.open("webpage2.html");
	b << "<html>webpage two\n</html>";
	b.close();

	ofstream c;
	c.open("webpage3.html");
	c << "<html>webpage three\n</html>";
	c.close();
		
	webpage.push(a);
	webpage.push(b);
	webpage.push(c);

	for (int i = 0; i < 3; i++)
	{
		cout << webpage.top() << endl;
		webpage.pop();
	}
	
	system("pause");
	return 0;

}
