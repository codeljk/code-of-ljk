#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapCreate(HP* php, HPDataType* a, int n);
void AdjustDown(HPDataType* a, int parent, int n);
void Swap(HPDataType* x, HPDataType* y);
void HeapPrint(HP* php, int n);
void HeapPush(HP* php, HPDataType x);
void AdjustUp(HPDataType* php, int child);
void HeapPop(HP* php);
bool HeapEmpty(HP* php);
size_t HeapSize(HP* php);
HPDataType HeapTop(HP* php);
