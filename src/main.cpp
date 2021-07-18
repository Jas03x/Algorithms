
bool AVL_Trees();
bool Max_Heaps();
bool Bubble_Sort();
bool Merge_Sort();

int main(int argc, char* argv[])
{
	bool status = true;

	if (status)
	{
		// status = AVL_Trees();
	}

	if (status)
	{
		// status = Max_Heaps();
	}

	if (status)
	{
		// status = Bubble_Sort();
	}

	if (status)
	{
		status = Merge_Sort();
	}

	return status ? 0 : -1;
}
