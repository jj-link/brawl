#include <stddef.h>
#pragma force_active on

typedef struct Node {
    char pad[0x18];
    int value;
    char pad2[4];
    struct Node *next;
} Node;

typedef struct Outer {
    char pad[0x440];
    Node *head;
} Outer;

int fn_8036EF30(Outer **arg0, Node **arg1, int arg2) {
    Node *node = (*arg0)->head;
    while (node) {
        if (node->value == arg2) {
            if (arg1)
                *arg1 = node;
            return 1;
        }
        node = node->next;
    }
    if (arg1)
        *arg1 = NULL;
    return 0;
}
