//
// Created by tom on 05/03/24.
//

#include "struct_a.h"
#include <stdlib.h>

CompareResult compare_struct_a(const void *a, const void *b) {
    StructA *value_a = (StructA *) a;
    StructA *value_b = (StructA *) b;

    if (value_b->data == value_a->data) return COMPARE_RESULT_EQUAL;

    return value_a->data < value_b->data ? COMPARE_RESULT_LESS : COMPARE_RESULT_GREATER;
}

void print_struct_a(const void *s) {
    StructA *value = (StructA *) s;
    printf("%s: score %d", value->name, value->data);
}

void struct_a_example() {
    printf("\nstruct A example: \n\n");
    GeneralNode *header = create_list(compare_struct_a, print_struct_a);
    StructA *a = (StructA *) malloc(sizeof(StructA));
    StructA *b = (StructA *) malloc(sizeof(StructA));
    a->data = 100;
    a->name = "Tom";

    b->data = 89;
    b->name = "Jerry";

    list_insert_node(header, a);
    list_insert_node(header, b);
    print_list(header);

    list_delete_node(header, b);
    printf("after delete:\n");
    print_list(header);

    list_delete_node(header, b);
    printf("try to delete, but did nothing:\n");
    print_list(header);


    free(a);
    free(b);
}