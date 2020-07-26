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
		cout << "Opening File" << endl;
	}

	else
	{
		cout << "Error";

	}

	while (sort >> i)
	{
		count++;
	};

	sort.close();
	return count;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int qSort(int arr[], int low, int high, int c1)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		qSort(arr, low, pi - 1, c1);
		qSort(arr, pi + 1, high, c1);
		c1++;
	}
	return c1;
};


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

}

int main()
{
	int a = 0;
	int c1, c2;
	a = countFile();

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


	c2 = qSort(arr, 0, a - 1, c1);
	cout << "count1:" << c2 << endl;
	printArray(arr, a);

	return 0;
}
