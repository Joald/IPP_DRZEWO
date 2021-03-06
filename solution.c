#include "list.h"

typedef char *String;

static int readInt() {
    int toReadInto;
    scanf("%d", &toReadInto);
    return toReadInto;
}

static void processTasks(List mainList) {
    String commandInput = malloc(sizeof(char)*20);

    while (scanf("%15s", commandInput) != EOF) {
        int parameter = readInt();

        if (!strcmp(commandInput, "ADD_NODE")) {
            addNode(parameter, mainList);
        }
        else if (!strcmp(commandInput, "DELETE_NODE")) {
            deleteNode(parameter, mainList);
        }
        else if (!strcmp(commandInput, "DELETE_SUBTREE")) {
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
			int numberOfNodes = 1 + mainList->lastAdded - mainList->deleted;
            fprintf(stderr, "NODES: %d\n", numberOfNodes);
        }

    }
    free(commandInput);

}

int main(int argc, char *argv[])
{
    bool ifDiagnostic = argc > 1;

    if (ifDiagnostic && strcmp(argv[1], "-v")) {
        printf("ERROR\n");
        return 1;
    }

    List mainList = newList(ifDiagnostic);

    processTasks(mainList);

    freeList(mainList);

    return 0;
}
