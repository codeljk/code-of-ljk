#include "List.h"

void ListInit(LN** ppHead)
{
	assert(*ppHead);
	*ppHead = BuyListNode(-1);
	(*ppHead)->next = (*ppHead);
	(*ppHead)->prev = (*ppHead);
}

void BuyListNode(LDataType x)
{
	LN* newNode = (LN*)malloc(sizeof(LN));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void ListPushBack(LN* pHead, LDataType x)
{
	assert(pHead);

	LN* newNode = BuyListNode(x);

	LN* tail = pHead->prev;
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = pHead;
}

void ListPrint(LN* pHead)
{
	assert(pHead);

	LN* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

void ListPopBack(LN* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	LN* tail = pHead->prev;
	LN* prev = tail->prev;

	prev->next = pHead;
	pHead->prev = prev;

	free(tail);
}

void ListPushFront(LN* pHead, LDataType x)
{
	assert(pHead);

	LN* newNode = BuyListNode(x);

	newNode->next = pHead->next;
	pHead->next->prev = newNode;

	pHead->next = newNode;
	newNode->prev = pHead;
}

void ListPopFront(LN* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	LN* del = pHead->next;

	pHead->next = del->next;
	del->next->prev = pHead;
}

LN* ListFind(LN* pHead, LDataType x)
{
	assert(pHead);
	assert(pHead->next != pHead);

	LN* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(LN* pos, LDataType x)
{
	assert(pos);

	LN* newNode = BuyListNode(x);
	LN* prev = pos->prev;

	newNode->next = pos;
	pos->prev = newNode;
	prev->next = newNode;
	newNode->prev = prev;
}

void ListErase(LN* pos)
{
	assert(pos);
	assert(pos->next != pos);

	LN* prev = pos->prev;
	LN* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);
}

void ListDestroy