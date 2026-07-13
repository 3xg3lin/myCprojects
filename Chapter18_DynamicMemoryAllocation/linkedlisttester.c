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

/*
 *  LinkedList              ListNode                ListNode                ListNode
 * +------------+         +----------+            +----------+            +----------+
 * | pFirstNode |-------->| pNext    |----------->| pNext    |----------->| pNext    |----> NULL
 * +------------+         +----------+            +----------+            +----------+
 * | nodeCount  |         | pData    |            | pData    |            | pData    |
 * +------------+         +----+-----+            +----+-----+            +----+-----+
 *                             |                       |                       |
 *                             v                       v                       v
 *                        +---------+             +---------+             +---------+
 *                        | ListData|             | ListData|             | ListData|
 *                        +---------+             +---------+             +---------+
 */

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

/*
 * BEFORE inserting pNode at the front:
 *
 *   LinkedList          ListNode(1)     ListNode(2)     ListNode(3)
 *   +----------+       +--------+      +--------+      +--------+
 *   |firstNode |------>| pNext  |----->| pNext  |----->| pNext  |----> NULL
 *   +----------+       +--------+      +--------+      +--------+
 *   |nodeCount |       | pData  |      | pData  |      | pData  |
 *   +----------+       +--------+      +--------+      +--------+
 *                           |               |               |
 *                           v               v               v
 *                       +--------+      +--------+      +--------+
 *                       |ListData|      |ListData|      |ListData|
 *                       +--------+      +--------+      +--------+
 *
 *   pNode
 *   +--------+
 *   | pNext  |----> NULL
 *   +--------+
 *   | pData  |
 *   +--------+
 *       |
 *       v
 *   +--------+
 *   |ListData|
 *   +--------+
 *   (a separate node, not linked to the list yet)
 *
 *
 * AFTER InsertNodeToFront: pFirstNode redirects to pNode [1],
 * and pNode->pNext redirects to the old first node [2].
 *
 *  LinkedList                      ListNode(1)    ListNode(2)
 *  +----------+                    +--------+     +--------+
 *  |firstNode ----. [1]     `----> | pNext  |---->| pNext  |----> NULL
 *  +----------+      |      |      +--------+     +--------+
 *  |nodeCount |      |      |      | pData  |     | pData  |
 *  +----------+      |      |      +--------+     +--------+
 *                    |      |          |
 *                    |      |          v
 *                    |      |      +--------+
 *                    |      |      |ListData|
 *                    |      |      +--------+
 *                    |      |
 *                    |      |
 *              pNode v      |
 *              +--------+   |
 *              | pNext  |----. [2]
 *              +--------+
 *              | pData  |
 *              +--------+
 *                  |
 *                  v
 *              +--------+
 *              |ListData|
 *              +--------+
 *
 * [1] pFirstNode now points to pNode
 * [2] pNode->pNext now points to the old first node (ListNode 1)
 */

void InsertNodeToFront(LinkedList* pList, ListNode* pNode){
    ListNode* pNext = pList->pFirstNode;  // The old first node must be saved BEFORE overwriting pFirstNode. This temp variable pNext is created for that purpose.
    pList->pFirstNode = pNode;            // Make pNode the new first node of the list.
    pNode->pNext = pNext;                 // Link the new node (pNode) to the old first node saved in the pNext variable created in the first line.
    pList->nodeCount++;                   // And update the count
}

/*
 * BEFORE InsertNodeToBack:
 * pCurr's node ends in NULL -- it's the actual last node of the list.
 * pNode is separate, not part of the list at all yet.
 *
 *                                                    pCurr                   pNode(separate)
 *                                                     |                       |
 *                                                     |                       |
 *                                                     v                       v
 *  LinkedList      ListNode        ListNode        ListNode                ListNode (pNode)
 *  +----------+    +--------+      +--------+      +--------+              +--------+
 *  |firstNode ---->| next   |----> | next   |----> | next   |----> NULL    | next   |
 *  +----------+    +--------+      +--------+      +--------+              +--------+
 *  |nodeCount |    | data   |      | data   |      | data   |              | data   |
 *  +----------+    +--------+      +--------+      +--------+              +--------+
 *                      |               |               |                       |
 *                      v               v               v                       v
 *                  +--------+      +--------+      +--------+              +--------+
 *                  |ListData|      |ListData|      |ListData|              |ListData|
 *                  +--------+      +--------+      +--------+              +--------+
 *
 *
 * AFTER InsertNodeToBack: pCurr->pNext now points to pNode.
 * pNode is now part of the list, and is the new last node (ends in NULL).
 *
 *                                                    pCurr          pNode
 *                                                     |              |
 *                                                     |              |
 *                                                     v              v
 *  LinkedList      ListNode        ListNode        ListNode       ListNode (pNode)
 *  +----------+    +--------+      +--------+      +--------+     +--------+
 *  |firstNode ---->| next   |----> | next   |----> | next   |---->| next   |----> NULL
 *  +----------+    +--------+      +--------+      +--------+     +--------+
 *  |nodeCount |    | data   |      | data   |      | data   |     | data   |
 *  +----------+    +--------+      +--------+      +--------+     +--------+
 *                      |               |               |              |
 *                      v               v               v              v
 *                  +--------+      +--------+      +--------+     +--------+
 *                  |ListData|      |ListData|      |ListData|     |ListData|
 *                  +--------+      +--------+      +--------+     +--------+
 */

void InsertNodeToBack(LinkedList* pList, ListNode* pNode){
    if (isEmpty(pList)){
        pList->pFirstNode = pNode;        // Empty list -> pNode is simply the first node.
    }
    else {
        // If it is not empty, walk to the last element of the list
        // using a temp variable pCurr, because we are inserting the node at the back.
        ListNode* pCurr = pList->pFirstNode;
        while (NULL != pCurr->pNext) {
            pCurr = pCurr->pNext;
        }
        pCurr->pNext = pNode;            // Attach new node after the last one
    }
    pList->nodeCount++;                  // And update the count
}

/*
 * (BEFORE RemoveNodeFromFront):
 * pCurr also points to pList->pFirstNode -- same node as firstNode, ListNode(1).
 *
 *  LinkedList        ListNode(1)     ListNode(2)     ListNode(3)     ListNode(4)
 *  +----------+      +--------+      +--------+      +--------+      +--------+
 *  |firstNode ---->  | next   |----> | next   |----> | next   |----> | next   |----> NULL
 *  +----------+ '--->+--------+      +--------+      +--------+      +--------+
 *  |nodeCount | |    | data   |      | data   |      | data   |      | data   |
 *  +----------+ |    +--------+      +--------+      +--------+      +--------+
 *               |        |               |               |               |
 *               |        v               v               v               v
 *               |    +--------+      +--------+      +--------+      +--------+
 *  +--------+   |    |ListData|      |ListData|      |ListData|      |ListData|
 *  | pCurr  |-.      +--------+      +--------+      +--------+      +--------+
 *  +--------+
 *
 *
 * (AFTER RemoveNodeFromFront):
 * firstNode now points to ListNode(2) -- it has become the new first node.
 * pCurr still points to ListNode(1), which is no longer part of the list.
 *
 *  LinkedList          ListNode(2)     ListNode(3)     ListNode(4)
 *  +----------+        +--------+      +--------+      +--------+
 *  |firstNode ----->   | next   |----> | next   |----> | next   |----> NULL
 *  +----------+        +--------+      +--------+      +--------+
 *  |nodeCount |        | data   |      | data   |      | data   |
 *  +----------+        +--------+      +--------+      +--------+
 *                          |               |               |
 *                          v               v               v
 *                      +--------+      +--------+      +--------+
 *                      |ListData|      |ListData|      |ListData|
 *                      +--------+      +--------+      +--------+
 *
 *                 ListNode(1)  (removed)
 *  +--------+     +--------+
 *  | pCurr  |---->| next   |   (not in list)
 *  +--------+     +--------+
 *                 | data   |
 *                 +--------+
 *                     |
 *                     v
 *                 +--------+
 *                 |ListData|
 *                 +--------+
 */

ListNode* RemoveNodeFromFront(LinkedList* pList){
    if (isEmpty(pList)) {
        return NULL;
    }
    ListNode* pCurr = pList->pFirstNode;
    pList->pFirstNode = pList->pFirstNode->pNext;
    pList->nodeCount--;
    return pCurr;
}

/*
 * (BEFORE RemoveNodeFromBack):
 * pPrev points to ListNode(3), pCurr points to ListNode(4) -- the last node.
 *
 *                                                    pPrev           pCurr
 *                                                     |               |
 *                                                     |               |
 *                                                     v               v
 *  LinkedList      ListNode(1)     ListNode(2)     ListNode(3)     ListNode(4)
 *  +----------+    +--------+      +--------+      +--------+      +--------+
 *  |firstNode ---->| next   |----> | next   |----> | next   |----> | next   |----> NULL
 *  +----------+    +--------+      +--------+      +--------+      +--------+
 *  |nodeCount |    | data   |      | data   |      | data   |      | data   |
 *  +----------+    +--------+      +--------+      +--------+      +--------+
 *                      |               |               |               |
 *                      v               v               v               v
 *                  +--------+      +--------+      +--------+      +--------+
 *                  |ListData|      |ListData|      |ListData|      |ListData|
 *                  +--------+      +--------+      +--------+      +--------+
 *
 *
 *
 * (AFTER RemoveNodeFromBack):
 * pPrev->pNext (ListNode(3)'s next) is now NULL -- ListNode(3) is the new last node.
 * pCurr still points to ListNode(4), which is no longer part of the list.
 *
 *                                                    pPrev                       pCurr
 *                                                     |                           |
 *                                                     |                           |
 *                                                     v                           v
 *  LinkedList      ListNode(1)     ListNode(2)     ListNode(3)                 ListNode(4)  (removed)
 *  +----------+    +--------+      +--------+      +--------+                  +--------+
 *  |firstNode ---->| next   |----> | next   |----> | next   |----> NULL        | next   |   (not in list)
 *  +----------+    +--------+      +--------+      +--------+                  +--------+
 *  |nodeCount |    | data   |      | data   |      | data   |                  | data   |
 *  +----------+    +--------+      +--------+      +--------+                  +--------+
 *                      |               |               |                           |
 *                      v               v               v                           v
 *                  +--------+      +--------+      +--------+                  +--------+
 *                  |ListData|      |ListData|      |ListData|                  |ListData|
 *                  +--------+      +--------+      +--------+                  +--------+
 */


ListNode* RemoveNodeFromBack(LinkedList* pList){
    if (isEmpty(pList)) {
        return NULL;
    }
    ListNode* pCurr = pList->pFirstNode;
    ListNode* pPrev = NULL;
    while (NULL != pCurr->pNext) {
        pPrev = pCurr;
        pCurr = pCurr->pNext;
    }
    pPrev->pNext = NULL;
    pList->nodeCount--;
    return pCurr;
}

ListNode* GetNode(LinkedList* pList, int pos){
    ListNode* pCurr = pList->pFirstNode;
    if (NULL == pCurr) {
        return pList->pFirstNode;
    }
    else if (pos == 0) {
        return pList->pFirstNode;
    }
    else {
        int i = 0;
        while (NULL != pCurr->pNext) {
            if (i == pos) {
                return pCurr;
            }
            i++;
            pCurr = pCurr->pNext;
        }
        return pCurr;
    }
}

ListNode* CreateNode(ListData* pData){
    ListNode* pNewNode = (ListNode*)calloc(1, sizeof(ListNode));
    if (NULL == pNewNode) {
        OutOfStorage();
    }
    pNewNode->pData = pData;
    return pNewNode;
}

void DeleteNode(ListNode* pNode){
    free(pNode->pData);
    free(pNode);
}

/*
 * When we declare a pointer to a function, we need more than just an
 * address to store -- the pointer's declared return type and parameter
 * list must exactly match the function it will be used to call.
 *
 * void (*printData)(ListData* pData);   // function pointer:  void, takes ListData*
 * void  PrintInt(ListData* pData);      // function prototype: void, takes ListData*
 *
 * Same shape (void, one ListData* parameter), so this is valid:
 *     printData = PrintInt;
 */

void PrintNode(ListNode* pNode, void (*printData)(ListData* pData)){
    printData(pNode->pData);
}

/*
 * A function is a named location in memory. Normally we'd call it
 * directly by name, but here we don't know which function will be
 * used ahead of time -- the caller decides. So (*printData) is a pointer
 * variable holding that function's address instead of its name, and
 * we use that pointer later to actually call the function.
 */

void PrintList(LinkedList* pList, void (*printData)(ListData* pData)){
    printf("List has %2d entries: [", Size(pList));
    ListNode* pCurr = pList->pFirstNode;
    while (NULL != pCurr) {
        PrintNode(pCurr, printData);
        pCurr = pCurr->pNext;
    }
    printf("]\n");
}

void PrintInt(int* i){
    printf("%2d", i);
}

ListData* CreateData(ListData d){
    ListData* pD = (ListData*)calloc(1, sizeof(ListData));
    if (pD == NULL) {
        OutOfStorage();
    }
    *pD = d;
    return pD;
}

void TestCreateNodeAndInsert(LinkedList* pLL, ListData data, eWhere where){
    ListData* pData = CreateData(data);
    ListData* pNode = CreateNode(pData);

    switch (where) {
        case eFront:
            InsertNodeToFront(pLL, pNode);
            break;
        case eBack:
            InsertNodeToBack(pLL, pNode);
            break;
    }
}

ListData TestExamineNode(LinkedList* pLL, eWhere where){
    ListNode* pNode;
    switch (where) {
        case eFront:
            pNode = GetNode(pLL, 0);
            break;
        case eBack:
            pNode = GetNode(pLL, pLL->nodeCount);
            break;
    }
    ListData data = *(pNode->pData);
    return data;
}

ListData TestRemoveNodeAndFree(LinkedList* pLL, eWhere where){
    ListNode* pNode;
    switch (where) {
        case eFront:
            pNode = RemoveNodeFromFront(pLL);
            break;
        case eBack:
            pNode = RemoveNodeFromBack(pLL);
            break;
    }
    ListData data = *(pNode->pData);
    DeleteNode(pNode);
    return data;
}

void TestPrintOperation(LinkedList* pLL, eAction action, ListData data, eWhere where){
    switch (action) {
        case eLook:
            data = TestExamineNode(pLL, where);
            printf("Get %s node, see [%2d]. ", where == eFront ? "front" : "back", data);
            break;
        case eInsert:
            printf("Insert [%2d] to %s. ", data, where == eFront ? "front" : "back");
            TestCreateNodeAndInsert(pLL, data, where);
            break;
        case eDelete:
            data = TestRemoveNodeAndFree(pLL, where);
            printf("Remove [%2d] from %s. ", data, where == eFront ? "front" : "back" );
            break;
        default:
            printf("::ERROR:: unknown action\n");
            break;
    }
    PrintList(pLL, PrintInt);
}

int main(){
    LinkedList* pLL = CreateLinkedList();
    printf( "Input or operation         "
            "Current state of linked list\n"
            "=========================  "
            "======================================");
    printf( "\nUsing input{ 1  2  3  4 }. " );
    int data1[] = {1, 2, 3, 4};
    int data1Size = 4;

    // PrintInt is passed without parentheses -- printData inside PrintList
    // is waiting for an address, not a call. We're not calling PrintInt
    // here; we're just handing over its address for PrintList to call later.
    PrintList(pLL, PrintInt);

    for (int i = 0; i < data1Size; i++) {
        TestPrintOperation(pLL, eInsert, data1[i], eFront);
    }

    TestPrintOperation(pLL, eLook, 0, eFront);
    TestPrintOperation(pLL, eDelete, 0, eBack);

    printf("\nUsing input{ 31, 32, 33 }");
    PrintList(pLL, PrintInt);
    int data2[] = {31, 32, 33};
    int data2Size = 3;

    for (int i = 0; i < data2Size; i++) {
        TestPrintOperation(pLL, eInsert, data2[i], eBack);
    }
    TestPrintOperation(pLL, eLook, 0, eBack);

    int count = pLL->nodeCount;
    for (int i = 0; i < count; i ++) {
        TestPrintOperation(pLL, eDelete, 0, eFront);
    }
}
