#pragma force_active on
struct Node { Node* next; int pad; unsigned int key; };
struct List { unsigned int count; Node* head; };
extern "C" Node* fn_74_2EA4(void* self, List* list, unsigned int key) {
    if (list == 0) return 0;
    Node* n = list->head;
    for (unsigned int i = 0; i != list->count; i++) {
        if (key == n->key) return n;
        n = n->next;
    }
    return 0;
}
