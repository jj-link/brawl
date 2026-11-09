#pragma force_active on
typedef struct Node {
    char pad[0x24];
    struct Node *next;
} Node;
typedef struct List {
    Node *head;
    Node *tail;
    int count;
} List;

int fn_80387A3C(List *list, Node *node) {
    Node *cur = list->head;
    Node *prev = 0;
    while (cur != 0) {
        if (cur == node) {
            if (prev != 0) {
                prev->next = cur->next;
            }
            if (list->head == cur) {
                list->head = cur->next;
            }
            if (list->tail == cur) {
                list->tail = prev;
            }
            list->count--;
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}