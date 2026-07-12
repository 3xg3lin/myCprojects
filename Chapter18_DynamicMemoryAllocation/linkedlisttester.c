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
