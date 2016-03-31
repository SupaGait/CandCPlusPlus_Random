#include "List.h"

List *newList(compFun fun, prFun fun1) {
    // Allocate the memory, set the functions for printing and comparing
    List* newList = (List*)malloc(sizeof(List));
    if(newList)
    {
        newList->comp = fun;
        newList->pr = fun1;
    }
    return newList;
}

void delList(List *list) {
    // Remove the nodes from the list
    Node *nodeTmp = list->head;
    while (nodeTmp) {
        nodeTmp = nodeTmp->next;
        free(list->head);
        list->head = nodeTmp;
    }
    // Cleanup the final list
    free(list);
}

status nthInList(List *list, int i, void **pVoid) {
    Node *node = list->head;
    for (int pos = 0; pos < i && node; ++pos) {
        node = node->next;
    }
    if(node) {
        *pVoid = node;
        return OK;
    }
    else
        return ERRINDEX;
}

status addListAt(List *list, int i, void *pVoid) {
    // Iterate through the list, up to given element
    Node *node = list->head;
    for (int pos = 0; pos < i && node; ++pos) {
        node = node->next;
    }
    if(node)
    {
        // Save next node
        node = node->next;
        node->next = (Node*)malloc(sizeof(node));
    }

    return ERRUNABLE;
}

status remFromListAt(List *list, int i, void **pVoid) {
    return ERRUNABLE;
}

status remFromList(List *list, void *pVoid) {
    return ERRUNABLE;
}

status displayList(List *list) {
    return ERRUNABLE;
}

void forEach(List *list, void (*pFunction)(void *)) {

}

int lengthList(List *list) {
    return 0;
}

status addList(List *list, void *pVoid) {
    return ERRUNABLE;
}

Node *isInList(List *list, void *pVoid) {
    return NULL;
}
