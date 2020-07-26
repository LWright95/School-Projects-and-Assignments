#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int countFile()
{
	int count = 0;
	int i;
	fstream sort;
	sort.open("Num64.txt");

	if (sort.good())
	{
		cout << "Opening File";
	}

	else
	{
		cout << "error";

	}

	while (sort >> i)
	{
		count++;
	};

	sort.close();
	return count;
}

int heapify(int arr[], int n, int i, int c2)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		c2++;

		heapify(arr, n, largest, c2);


	}
	return c2;
};


void hSort(int arr[], int a)
{
	int c1 = 0;
	int c2;
	int c3;
	int gg;
	for (int i = a / 2 - 1; i >= 0; i--)
		c2 = heapify(arr, a, i, c2);


	for (int i = a - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		c3 = heapify(arr, i, 0, c2);
		c1++;
	}
	gg = c2 + c3;
	cout << "count" << c1 << endl;
	cout << "count" << gg << endl;
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " ";

	};
	cout << endl;
}

int main()
{
	int a = 0;
	a = countFile();
	cout << "File: num" << a << endl;



	int arr[a];
	ifstream datfile;
	datfile.open("Num64.txt");
	if (datfile.is_open())
	{
		for (int n = 0; n<a; n++)
		{
			datfile >> arr[n];
		};
	};

	for (int i = 0; i<a; i++)
	{
		cout << arr[i] << " ";
	};
	cout << endl;

	hSort(arr, a);
	printArray(arr, a);

	return 0;
}
