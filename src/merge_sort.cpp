
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

void MergeSort_Merge(const int* src, int* dst, int m, int r)
{
	printf("merge %u %u: ", m, r);
	for (unsigned int i = 0; i <= r; i++) { printf("%u ", src[i]); }
	printf("\n");

	int i = 0;
	int j = m + 1;
	for (unsigned int k = 0; k <= r; k++)
	{
		// the left side has more elements left to copy AND either the right side has been fully consumed, or the left side's element is less than the right side's element.
		if ((i <= m) && ((j >= r) || src[i] <= src[j]))
		{
			dst[k] = src[i++];
		}
		else
		{
			dst[k] = src[j++];
		}
	}

	printf("merged: ");
	for (unsigned int i = 0; i <= r; i++) { printf("%u ", dst[i]); }
	printf("\n");
}

void MergeSort_Sort(const int* src, int* dst, int len)
{
	if (len == 1)
	{
		return;
	}
	else
	{
		int s = len / 2;

		MergeSort_Sort(src, dst, s);
		MergeSort_Sort(src + s, dst + s, len - s);

		MergeSort_Merge(src, dst, s, len - 1);
	}
}

void MergeSort(const vector<int>& src, vector<int>& dst)
{
	MergeSort_Sort(src.data(), dst.data(), src.size());
}

void print_int_vector(vector<int>& v);

bool Merge_Sort_Test1()
{
	bool result = true;
	vector<int> unsorted = { 5, 3, 1, 4, 2 };
	vector<int> sorted(5, 0);
	vector<int> answer = { 1, 2, 3, 4, 5 };

	MergeSort(unsorted, sorted);
	print_int_vector(sorted);

	for (unsigned int i = 0; i < sorted.size(); i++)
	{
		if (sorted[i] != answer[i])
		{
			printf("error at index %u: expected %i, got %i\n", i, answer[i], sorted[i]);
			result = false;
			break;
		}
	}

	return result;
}

bool Merge_Sort()
{
	bool result = true;

	result = Merge_Sort_Test1();

	return result;
}
