//
// Created by tom on 05/03/24.
//

#ifndef GENERAL_LINKED_LIST_GENERAL_LINKED_LIST_H
#define GENERAL_LINKED_LIST_GENERAL_LINKED_LIST_H

#define COMPARE_RESULT_EQUAL 0
#define COMPARE_RESULT_LESS (-1)
#define COMPARE_RESULT_GREATER 1

typedef int CompareResult;

typedef CompareResult (*FuncPtrCompare)(const void *, const void *);

typedef void (*FuncPtrPrint)(const void *);

typedef struct GeneralNode {
    void *payload;
    struct GeneralNode *next;

    FuncPtrCompare func_compare;
    FuncPtrPrint func_print;

} GeneralNode;

/**
 * to create a empty node as the list head
 *
 * @param compare
 * @param print
 * @return
 */
GeneralNode *create_list(FuncPtrCompare compare, FuncPtrPrint print);

/**
 *
 *  to insert a node after head and before all other nodes
 *
 * @param head
 * @param payload
 * @return
 */
GeneralNode *list_insert_node(GeneralNode *head, const void *payload);

/**
 * to print the whole list
 *
 * @param head
 */
void print_list(GeneralNode *head);

/**
 * to delete node
 * @param head
 * @param payload
 * @return the deleted node or NULL if not found
 */
GeneralNode *list_delete_node(GeneralNode *head, const void *payload);

#endif //GENERAL_LINKED_LIST_GENERAL_LINKED_LIST_H
