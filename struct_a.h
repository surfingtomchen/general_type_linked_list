//
// Created by tom on 05/03/24.
//

#ifndef GENERAL_LINKED_LIST_STRUCT_A_H
#define GENERAL_LINKED_LIST_STRUCT_A_H

#include <stdio.h>
#include "general_linked_list.h"

typedef struct StructA {
    int data;
    char *name;
} StructA;

CompareResult compare_struct_a(const void *a, const void *b);

void print_struct_a(const void *s);

/***
 * an example to show how to use the general_linked_list
 */
void struct_a_example();
#endif //GENERAL_LINKED_LIST_STRUCT_A_H
