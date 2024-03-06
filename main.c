#include <stdio.h>
#include "general_linked_list.h"
#include "struct_a.h"

void print_int(const void *p) {
    int *value = (int *) p;
    printf("%d", *value);
}

CompareResult compare_int(const void *a, const void *b) {
    int *value_a = (int *) a;
    int *value_b = (int *) b;

    if (*value_b == *value_a)
        return COMPARE_RESULT_EQUAL;

    return *value_a < *value_b ? COMPARE_RESULT_LESS : COMPARE_RESULT_GREATER;
}

void int_example() {
    printf("\nInt type\n\n");

    GeneralNode *int_list_header = create_list(compare_int, print_int);

    int a = 100, b = 200;
    list_insert_node(int_list_header, (void *) &a);
    list_insert_node(int_list_header, (void *) &b);
    print_list(int_list_header);

    printf("after delete %d:\n", b);
    list_delete_node(int_list_header, &b);

    print_list(int_list_header);

    printf("after delete %d:\n", a);
    list_delete_node(int_list_header, &a);
    print_list(int_list_header);
}

int main() {
    printf("a demo for general type of linked list\n");
    int_example();
    struct_a_example();
}
