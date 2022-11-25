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

// ����ڵ�Ĵ���
SLTNode* BuySLNode(SLTDataType x);

// �����β��
void SListPushBack(SLTNode** pphead, SLTDataType x);

// �����βɾ
void SListPopBack(SLTNode** pphead);

// �����ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);

// �����ͷɾ
void SListPopFront(SLTNode** pphead);

// ����Ĵ�ӡ
void SListPrint(SLTNode* phead);

// �������в���ָ��Ԫ��
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

// �������ָ��λ��֮ǰ���в���
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

// �������ָ��λ��֮����в���
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// ɾ�������ָ���ڵ�λ��
void SListErase(SLTNode** pphead, SLTNode* pos);

