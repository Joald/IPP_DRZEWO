#include "tree.h"


/*
    This function forms the parental link between nodes.

    If the father has no children, we add one as both
    the first and the last. Otherwise we just need
    to form the 'brotherly' connection between the
    previous oldest child and the one we add.
*/
void addChild(Tree newFather, Tree newChild) {
    if (newFather->firstChild->next == newFather->lastChild) {
        newFather->firstChild->next = newChild;
        newFather->lastChild->prev = newChild;

        newChild->prev = newFather->firstChild;
        newChild->next = newFather->lastChild;
    }
    else {
        newChild->prev = newFather->lastChild->prev;
        newChild->next = newFather->lastChild;

        newFather->lastChild->prev->next = newChild;
        newFather->lastChild->prev = newChild;
    }
}

//The function assumes that the Node has no children except for the guardians.
void freeNode(Tree toDelete) {
    free(toDelete->firstChild);
    free(toDelete->lastChild);
    free(toDelete);
}

//Adds guardians for children so that there is no need to remember the father.
void addGuardians(Tree toAdd) {
    Tree leftGuardian = (Tree) malloc(sizeof(struct TreeStruct));
    Tree rightGuardian = (Tree) malloc(sizeof(struct TreeStruct));

    if (leftGuardian == NULL || rightGuardian == NULL) {
        printf("Bad memory allocation.");
        exit(EXIT_FAILURE);
    }

    leftGuardian->prev = leftGuardian->firstChild =
        leftGuardian->lastChild = rightGuardian->next =
        rightGuardian->firstChild = rightGuardian -> lastChild = NULL;

    leftGuardian->next = rightGuardian;
    rightGuardian->prev = leftGuardian;

    leftGuardian->label = -1;
    rightGuardian->label = -1;

    toAdd->firstChild = leftGuardian;
    toAdd->lastChild = rightGuardian;
}

Tree addBrotherhood(Tree left, Tree right) {
    left->next = right;
    right->prev = left;
}
