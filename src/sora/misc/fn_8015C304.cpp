#pragma force_active on
struct Node {
    struct Node* next;
    struct Node* prev;
};

struct List {
    int count;
    struct Node head;
};

extern "C" {
void fn_8015C304(struct List* list) {
    struct Node* head = &list->head;
    struct Node* node = list->head.next;
    while (node != head) {
        struct Node* next = node->next;
        struct Node* prev = node->prev;
        next->prev = prev;
        prev->next = next;
        list->count--;
        node->next = 0;
        node->prev = 0;
        node = next;
    }
}
}
