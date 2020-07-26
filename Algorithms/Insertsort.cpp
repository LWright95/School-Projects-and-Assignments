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


void iSort(int *arr, int n)
{
	int count1 = 0, count2 = 0;
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		count1++;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			count2++;
		}

		arr[j + 1] = key;
	}
	cout << "sorted" << endl;
	cout << "count1:" << count1 << endl;
	cout << "count2:" << count2 << endl;
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

	iSort(arr, a);
	printArray(arr, a);

	return 0;
}
