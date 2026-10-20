#pragma force_active on
struct Node {
    Node* next;
    int pad;
    unsigned char id;
};
struct List {
    unsigned int count;
    Node* head;
};
extern "C" Node* fn_79_16FC(void* unused, unsigned int id, List* list) {
    Node* n = list->head;
    unsigned int c = list->count;
    for (unsigned int i = 0; i != c; i++) {
        if (id == n->id) return n;
        n = n->next;
    }
    return 0;
}
