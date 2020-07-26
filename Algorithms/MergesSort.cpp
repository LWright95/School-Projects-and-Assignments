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

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2)
	{

		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;

	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mSort(arr, l, m);
		mSort(arr, m + 1, r);

		merge(arr, l, m, r);

	}
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

	mSort(arr, 0, a - 1);
	printArray(arr, a);

	return 0;
}
