
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

struct Node
{
	int value;
};

struct Heap
{
	vector<Node> nodes;
};

#define P_INDEX(i) static_cast<int>(floor((i)/2))
#define L_INDEX(i) ((i)*2)
#define R_INDEX(i) ((i)*2+1)

bool Swap(Heap* heap, int i0, int i1)
{
	bool status = true;

	Node copy = heap->nodes[i0 - 1];
	heap->nodes[i0 - 1] = heap->nodes[i1 - 1];
	heap->nodes[i1 - 1] = copy;

	return status;
}

bool Push(Heap* heap, Node node)
{
	bool status = true;

	heap->nodes.push_back(node);

	int index = heap->nodes.size();
	while (index != 1)
	{
		int p_index = P_INDEX(index);
		Node* parent = &heap->nodes[p_index - 1];

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

Node Pop(Heap* heap)
{
	Node ret = {};

	if (heap->nodes.size() > 0)
	{
		ret = heap->nodes[0];
		
		Swap(heap, 1, heap->nodes.size());
		heap->nodes.pop_back();

		int index = 1;
		while (true) // the element at the back has been placed at the top, bubble it down
		{
			int l_index = L_INDEX(index);
			int r_index = R_INDEX(index);
			int p_index = -1;

			if ((l_index <= heap->nodes.size()) && (heap->nodes[l_index - 1].value > heap->nodes[index - 1].value))
			{
				p_index = l_index;
			}

			if ((r_index <= heap->nodes.size()) && (heap->nodes[r_index - 1].value > heap->nodes[index - 1].value))
			{
				if (p_index == -1)
				{
					p_index = r_index;
				}
				else
				{
					p_index = (heap->nodes[r_index - 1].value > heap->nodes[p_index].value) ? r_index : p_index;
				}
			}

			if ((p_index == -1) || (heap->nodes[index - 1].value > heap->nodes[p_index - 1].value))
			{
				break;
			}
			else
			{
				Swap(heap, index, p_index);
				index = p_index;
			}
		}
	}

	return ret;
}

void Print(Heap* heap)
{
	for (unsigned int i = 0; i < heap->nodes.size(); i++)
	{
		printf("%i\n", heap->nodes[i].value);
	}
}

bool Check(const char* message, Node n, int value)
{
	bool status = n.value == value;
	printf("%s: %s\n", message, status ? "pass" : "fail");
	if (!status)
	{
		printf("error: expected %i, got %i\n", value, n.value);
	}
	return status;
}

bool Max_Heaps_Test1()
{
	bool status = true;

	Heap heap;
	if (status) { status = Push(&heap, { 2 }); }
	if (status) { status = Push(&heap, { 3 }); }
	if (status) { status = Push(&heap, { 1 }); }
	if (status) { status = Push(&heap, { 5 }); }

	if (status) { status = Check("Test 1", heap.nodes[0], 5); }
	if (status) { status = Check("Test 2", Pop(&heap), 5); }
	if (status) { status = Check("Test 3", heap.nodes[0], 3); }

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
