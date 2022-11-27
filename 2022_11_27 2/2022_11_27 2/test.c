#include "BinaryTree.h"

void test()
{
	int arr[] = { 12,5,16,25,37,65,42,3,8,17,32 };
	HP hp;
	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]));

	HeapPush(&hp, 100);

	HeapPop(&hp);

	HeapPrint(&hp, sizeof(arr) / sizeof(arr[0]));

	int k = 5;
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}

int main()
{
	test();
	return 0;
}