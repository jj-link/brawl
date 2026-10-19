#pragma force_active on
typedef struct Node {
    struct Node *next;
    int pad;
    unsigned int key;
} Node;

typedef struct List {
    unsigned int count;
    Node *head;
} List;

extern "C" void *fn_68_3FB8(void *unused, List *list, unsigned int key)
{
    unsigned int i;
    Node *n;

    if (list == 0) {
        return 0;
    }
    if (key == 0) {
        return 0;
    }
    n = list->head;
    for (i = 0; i != list->count; i++) {
        if (n->key == key) {
            return n;
        }
        n = n->next;
    }
    return 0;
}
