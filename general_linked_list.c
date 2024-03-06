//
// Created by tom on 05/03/24.
//

#include <stdlib.h>
#include <stdio.h>
#include "general_linked_list.h"


GeneralNode *create_list(FuncPtrCompare compare, FuncPtrPrint print) {
    GeneralNode *head = (GeneralNode *) malloc(sizeof(GeneralNode));
    head->payload = head->next = NULL;
    head->func_compare = compare;
    head->func_print = print;

    return head;
}

GeneralNode *list_insert_node(GeneralNode *head, const void *payload) {
    GeneralNode *new_node = (GeneralNode *) malloc(sizeof(GeneralNode));
    new_node->payload = payload;
    new_node->func_print = NULL;
    new_node->func_compare = NULL;

    new_node->next = head->next;
    head->next = new_node;
    return new_node;
}

GeneralNode *list_delete_node(GeneralNode *head, const void *payload) {
    GeneralNode *p = head;
    while (p->next != NULL) {
        if (head->func_compare(p->next->payload, payload) == COMPARE_RESULT_EQUAL) {
            break;
        }
        p = p->next;
    }
    GeneralNode *found = p->next;
    if (found == NULL) return NULL;

    p->next = found->next;
    return found;
}

void print_list(GeneralNode *head) {
    GeneralNode *p = head;
    while (p != NULL) {
        if (p->payload != NULL) {
            head->func_print(p->payload);
            printf("\n|\n");
        }
        p = p->next;
    }
    printf("NULL\n");
}