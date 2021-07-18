
#include <cstdio>
#include <vector>

using namespace std;

void print_int_vector(vector<int>& v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		printf("%i ", v[i]);
	}
	printf("\n");
}
