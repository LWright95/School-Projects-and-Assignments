#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

void cycShift(string a, int shift)
{
	unsigned int h = 0;
	for (int i = 0; i < 5; i++)
	{
		h = (h << shift) | (h >> 27);
		h = h + (unsigned int)a[i];
	}
	cout << h << endl;
}

int main()
{
	string a[] = ("abcde", "bacde", "abcdx");
	for (int i = 0; i < 3; i++)
	{
		//no shift
		cout << a[i];
		//shift 3
		cout << cycShift(a[i], 3) << endl;
		//shift 5 
		cout << cycShift(a[i], 5) << endl;
	}
	system("pause");
	return 0;
}
