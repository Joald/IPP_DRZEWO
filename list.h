#pragma once

#include "tree.h"

struct ListStruct
{
    int lastAdded;
    int deleted;
    Tree nodeRandomAccess[(1<<20) + 5];
    bool diagnostic;
};

typedef struct ListStruct *List;

List newList(bool ifDiagnostic);

void freeList(List toDelete);

void addNode(int n, List);

void rightmostChild(int father, List mainList);

void deleteNode(int toDelete, List mainList);

void deleteSubtree(int toDelete, List mainList);

void splitNode(int parent, int splitPoint, List mainList);
