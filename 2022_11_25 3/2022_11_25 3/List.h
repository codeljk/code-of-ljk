#pragma once

typedef int LDataType;

typedef struct ListNode
{
	LDataType data;
	struct List* prev;
	struct List* next;
}LN;

LN* BuyListNode(LDataType x);
void ListInit(LN* pHead);
