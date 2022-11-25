#include "SList.h"

void test()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);

	SListPopBack(&phead);
	SListPopBack(&phead);

	SListPushFront(&phead, 100);
	SListPushFront(&phead, 200);
	SListPushFront(&phead, 300);
	SListPushFront(&phead, 400);

	SListPrint(phead);
}

int main()
{
	test();
	return 0;
}