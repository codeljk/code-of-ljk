#include "List.h"

void test()
{
	LN* pHead = NULL;
	ListInit(&pHead);

	ListPushBack(pHead, 100);
	ListPushBack(pHead, 200);
	ListPushBack(pHead, 300);
	ListPushBack(pHead, 400);

	ListPrint(pHead);
}

int main()
{
	test();
	return 0;
}