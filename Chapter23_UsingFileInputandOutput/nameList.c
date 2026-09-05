#include "nameList.h"
#include <_stdio.h>
#include <stdlib.h>
#include <string.h>

ListNode* CreateListNode(char* pNameToAdd){
    ListNode* pNewNode = (ListNode*)calloc(1, sizeof(ListNode));
    if (pNewNode == NULL) {
        OutOfStorage();
    }

    pNewNode->pData = (char*)calloc(1, strlen(pNameToAdd) + 1);
    if (pNewNode->pData == NULL) {
        OutOfStorage();
    }
    strcpy(pNewNode->pData, pNameToAdd);
    return pNewNode;
}
