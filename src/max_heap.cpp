
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

struct Node
{
	int value;
	int priority;
};

struct Heap
{
	vector<Node> nodes;
};

// Parent Index
#define P_INDEX(i) static_cast<int>(floor((i)/2))

bool Swap(Heap* heap, int i0, int i1)
{
	bool status = true;

	Node copy = heap->nodes[i0];
	heap->nodes[i0] = heap->nodes[i1];
	heap->nodes[i1] = copy;

	return status;
}

bool Insert(Heap* heap, Node node)
{
	bool status = true;
	int index = heap->nodes.size();

	heap->nodes.push_back(node);
	

	while (index != 0)
	{
		int p_index = P_INDEX(index);
		Node* parent = &heap->nodes[p_index];

		if (node.value > parent->value)
		{
			Swap(heap, index, p_index);
			index = p_index;
		}
		else
		{
			break;
		}
	}

	return status;
}

void Print(Heap* heap)
{
	for (unsigned int i = 0; i < heap->nodes.size(); i++)
	{
		printf("(%i, %i)\n", heap->nodes[i].value, heap->nodes[i].priority);
	}
}

bool Max_Heaps_Test1()
{
	bool status = true;

	Heap heap;
	if (status) { status = Insert(&heap, { 2, 2 }); }
	if (status) { status = Insert(&heap, { 3, 3 }); }
	if (status) { status = Insert(&heap, { 1, 1 }); }

	Print(&heap);

	return status;
}

bool Max_Heaps()
{
	bool status = true;

	if (status)
	{
		status = Max_Heaps_Test1();
	}

	return status;
}
