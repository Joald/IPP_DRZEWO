#include "list.h"

List newList(bool ifDiagnostic) {
    List toReturn = (List) malloc(sizeof(struct ListStruct));

    if (toReturn == NULL) {
        printf("Bad memory allocation.");
        exit(EXIT_FAILURE);
    }

    toReturn->lastAdded = -1;
    toReturn->deleted = 0;
    toReturn->diagnostic = ifDiagnostic;

    addNode(-1, toReturn);

    return toReturn;
}

void freeList(List toDelete) {
    for (int i = 0; i <= toDelete->lastAdded; ++i) {
        if (toDelete->nodeRandomAccess[i] != NULL) {
            freeNode(toDelete->nodeRandomAccess[i]);
        }
    }

    free(toDelete);
}

void addNode(int father, List mainList) {
    Tree newNode = (Tree) malloc(sizeof(struct TreeStruct));

    if (newNode == NULL) {
        printf("Bad memory allocation.");
        exit(EXIT_FAILURE);
    }

    addGuardians(newNode);

    newNode->label = ++mainList->lastAdded;
    mainList->nodeRandomAccess[mainList->lastAdded] = newNode;

    if (father >= 0) {
        addChild(mainList->nodeRandomAccess[father], newNode);
    }

}

void rightmostChild(int father, List mainList) {
    Tree fatherTree = mainList->nodeRandomAccess[father];

    if (fatherTree->lastChild->prev == fatherTree->firstChild) {
        printf("-1\n");
    }
    else {
        printf("%d\n",fatherTree->lastChild->prev->label);
    }
}

void deleteNode(int toDelete, List mainList) {
    Tree deletedTree = mainList->nodeRandomAccess[toDelete];

    Tree leftChild = deletedTree->firstChild;
    Tree rightChild = deletedTree->lastChild;
    Tree left = deletedTree->prev;
    Tree right = deletedTree->next;

    bool isChildless = leftChild->next == rightChild;

    if (isChildless) {
        left->next = right;
        right->prev = left;
    }
    else {
        left->next = leftChild->next;
        leftChild->next->prev = left;
        right->prev = rightChild->prev;
        rightChild->prev->next = right;
    }


    freeNode(deletedTree);
    mainList->nodeRandomAccess[toDelete] = NULL;
    mainList->deleted++;
}

void deleteSubtree(int toDelete, List mainList) {
    if (toDelete == -1) {
        return;
    }

    Tree deletedTree = mainList->nodeRandomAccess[toDelete];

    Tree leftChild = deletedTree->firstChild;
    Tree rightChild = deletedTree->lastChild;
    Tree left = deletedTree->prev;
    Tree right = deletedTree->next;

    left->next = right;
    right->prev = left;

    while (leftChild->next != rightChild) {
        deleteNode(leftChild->next->label, mainList);
    }

    freeNode(deletedTree);
    mainList->nodeRandomAccess[toDelete] = NULL;
    mainList->deleted++;
}

void splitNode(int parentNumber, int splitPointNumber, List mainList) {
    Tree parent = mainList->nodeRandomAccess[parentNumber];
    Tree splitPoint = mainList->nodeRandomAccess[splitPointNumber];

    Tree childrenStart = splitPoint->next;
    Tree childrenEnd = parent->lastChild->prev;

    if (childrenEnd == splitPoint) {
        addNode(parent->label, mainList);
    }
    else {
        addBrotherhood(splitPoint, parent->lastChild);

        addNode(parent->label, mainList);

        Tree newlyAdded = parent->lastChild->prev;

        addBrotherhood(newlyAdded->firstChild, childrenStart);
        addBrotherhood(childrenEnd, newlyAdded->lastChild);
    }
}
