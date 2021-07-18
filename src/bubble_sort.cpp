
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& v)
{
	while (true)
	{
		bool swapped = false;

		for (unsigned int i = 0; i < v.size() - 1; i++)
		{
			if (v[i] > v[i + 1])
			{
				swap(v[i], v[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}

void print_int_vector(vector<int>& v);

bool Bubble_Sort_Test1()
{
	bool result = true;
	vector<int> v0 = { 5, 3, 1, 4, 2 };
	vector<int> v1 = { 1, 2, 3, 4, 5 };

	BubbleSort(v0);

	for (unsigned int i = 0; i < v0.size(); i++)
	{
		if (v0[i] != v1[i])
		{
			printf("error at index %u: expected %i, got %i\n", i, v1[i], v0[i]);
			result = false;
			break;
		}
	}

	return result;
}

bool Bubble_Sort()
{
	bool result = true;

	result = Bubble_Sort_Test1();

	return result;
}
