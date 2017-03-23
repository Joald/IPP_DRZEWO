#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TreeStruct *Tree;

struct TreeStruct
{
    Tree prev, next, firstChild, lastChild;
    int label;
};

void addChild(Tree newFather, Tree newChild);

void freeNode(Tree toDelete);

void addGuardians(Tree toAdd);

Tree addBrotherhood(Tree left, Tree right);
