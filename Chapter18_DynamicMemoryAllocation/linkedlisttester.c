#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    eFront = 0,
    eBack,
} eWhere;

typedef enum {
    eLook = 0,
    eInsert,
    eDelete
} eAction;

typedef int ListData;

void OutOfStorage(void){
    fprintf(stderr, "### FATAL RUNTIME ERROR ### No Memory Available");
    exit(EXIT_FAILURE);
}

typedef struct _Node {
    struct _Node* pNext;
    ListData* pData;
} ListNode;

typedef struct {
    ListNode* pFirstNode;
    int nodeCount;
} LinkedList;

LinkedList* CreateLinkedList() {
    LinkedList* pLL = (LinkedList*)calloc(1, sizeof(LinkedList));
    if (pLL == NULL) {
        OutOfStorage();
    }
    return pLL;
}

bool isEmpty(LinkedList* pList) {
    return (0 == pList->nodeCount);
}

int Size(LinkedList* pList){
    return pList->nodeCount;
}

void InsertNodeToFront(LinkedList* pList, ListNode* pNode){
    ListNode* pNext = pList->pFirstNode;
    pList->pFirstNode = pNode;
    pNode->pNext = pNext;
    pList->nodeCount++;
}
