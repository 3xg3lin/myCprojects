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

void AddName(NameList *pNames, char *pNameToAdd){
    ListNode* pNewName = CreateListNode(pNameToAdd);
    if (IsEmpty(pNames)) {
        pNames->pFirstNode = pNewName;
        (pNames->nodeCount)++;
        return;
    }
    (pNames->nodeCount)++;
    ListNode* curr;
    ListNode* prev;
    curr = prev = pNames->pFirstNode;
    while (curr) {
        if (strcmp(pNewName->pData, curr->pData) < 0) {
            if (curr == pNames->pFirstNode) {
                pNames->pFirstNode = pNewName;
                pNewName->pNext = curr;
            }
            else {
                prev->pNext = pNewName;
                pNewName->pNext = curr;
            }
            return;
        }
        prev = curr;
        curr = prev->pNext;
    }
    prev->pNext = pNewName;
}

void PrintNames(FILE *outputDesc, NameList *pNames){
    ListNode* curr = pNames->pFirstNode;
    while (curr != NULL) {
        fputs(curr->pData, outputDesc);
        fputc('\n', outputDesc);
        curr = curr->pNext;
    }
}

void DeleteNames(NameList *pNames){
    while (pNames->pFirstNode != NULL) {
        ListNode* temp = pNames->pFirstNode;
        pNames->pFirstNode = pNames->pFirstNode->pNext;
        free(temp->pData);
        free(temp);
    }
}
