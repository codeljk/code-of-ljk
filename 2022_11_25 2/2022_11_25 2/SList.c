#include "SList.h"

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newNode = BuySLNode(x);

	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

SLTNode* BuySLNode(SLTDataType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPopBack(SLTNode** pphead)
{
	assert(*pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* cur = (*pphead)->next;
		SLTNode* prev = *pphead;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		free(cur);
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(*pphead);

	SLTNode* newNode = BuySLNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}
