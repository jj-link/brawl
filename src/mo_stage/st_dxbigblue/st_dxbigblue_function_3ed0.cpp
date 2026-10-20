#pragma force_active on
struct Node {
    Node* next;
    unsigned int unknown;
    unsigned char id;
};

struct List {
    unsigned int count;
    Node* head;
};

extern "C" Node* fn_81_3ED0(void*, unsigned int id, const List* list) {
    unsigned int count = list->count;
    Node* node = list->head;

    for (unsigned int i = 0; i != count; ++i) {
        if (id == node->id)
            return node;
        node = node->next;
    }

    return 0;
}
