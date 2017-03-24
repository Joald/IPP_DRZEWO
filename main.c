#include "list.h"

typedef char *String;

static String readString() {
    String toReadInto = malloc(15);

    if (scanf("%15s", toReadInto) != EOF) {
        return toReadInto;
    }
    else {
        return "";
    }
}

static int readInt() {
    int toReadInto;
    scanf("%d", &toReadInto);
    return toReadInto;
}

static void processTasks(List mainList) {
    String commandInput;

    while (true) {
        commandInput = readString();

        if (!strcmp(commandInput, "")) {
            return;
        }

        ///debug debug debug debug debug debug debug debug debug
        if(mainList->lastAdded > 11){break;}

        ///debug debug debug debug debug debug debug debug debug


        int parameter = readInt();

        if (!strcmp(commandInput, "ADD_NODE")) {
            addNode(parameter, mainList);
        }
        else if (!strcmp(commandInput, "DELETE_NODE")) {
            deleteNode(parameter, mainList);
        }
        else if (!strcmp(commandInput, "DELETE_SUBTREE")) {

            //Tree a = mainList->nodeRandomAccess[parameter];
            //printf("%d %d %d %d %d ", a->label, a->firstChild->label, a->firstChild->next->label,a->firstChild->next->next->label,a->firstChild->next->next->next->label);
            deleteSubtree(parameter, mainList);
        }
        else if (!strcmp(commandInput, "SPLIT_NODE")) {
            int secondParameter = readInt();
            splitNode(parameter, secondParameter, mainList);
        }

        if (!strcmp(commandInput, "RIGHTMOST_CHILD")) {
            rightmostChild(parameter, mainList);
        }
        else {
            printf("OK\n");
        }

        if (mainList->diagnostic) {
            printf("NODES: %d\n", mainList->lastAdded);
        }

    }

}

int main(int argc, char *argv[])
{
    bool ifDiagnostic = argc > 1;

    if (ifDiagnostic && !strcmp(argv[1], "-v")) {
        printf("ERROR\n");
        return 1;
    }

    List mainList = newList(ifDiagnostic);

    processTasks(mainList);

    freeList(mainList);

    return 0;
}
