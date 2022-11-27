#include "BinaryTree.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HeapCreate(HP* php, HPDataType* a, int n)
{
	assert(php);
	assert(a);

	HeapInit(php);

	HPDataType* tmp = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	php->a = tmp;
	php->size = php->capacity = n;

	memcpy(php->a, a, sizeof(HPDataType) * n);

	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, i, n);
	}
}

void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(HPDataType* a, int parent, int n)
{
	while (parent * 2 + 1 < n)
	{
		int child = parent * 2 + 1;
		if (a[parent * 2 + 1] < a[parent * 2 + 2])
			child = parent * 2 + 2;
		if (a[parent] < a[child])
			Swap(&a[parent], &a[child]);
		else
			break;
		parent = child;
	}
}

void HeapPrint(HP* php, int n)
{
	assert(php);
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", php->a[i]);
	printf("\n");
}

void AdjustUp(HPDataType* a, int child)
{
	while (child > 0)
	{
		int parent = (child - 1) / 2;
		if (a[child] > a[parent])
			Swap(&a[child], &a[parent]);
		else
			break;
		child = parent;
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}

	php->a[php->size++] = x;
	AdjustUp(php->a, php->size - 1);
}

void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;

	AdjustDown(php->a, 0, php->size);
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

size_t HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}