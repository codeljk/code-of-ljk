#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

// 链表节点的创建
SLTNode* BuySLNode(SLTDataType x);

// 链表的尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);

// 链表的尾删
void SListPopBack(SLTNode** pphead);

// 链表的头插
void SListPushFront(SLTNode** pphead, SLTDataType x);

// 链表的头删
void SListPopFront(SLTNode** pphead);

// 链表的打印
void SListPrint(SLTNode* phead);

// 在链表中查找指定元素
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

// 在链表的指定位置之前进行插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

// 在链表的指定位置之后进行插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// 删除链表的指定节点位置
void SListErase(SLTNode** pphead, SLTNode* pos);

