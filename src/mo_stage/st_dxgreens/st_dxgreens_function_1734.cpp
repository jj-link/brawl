#pragma force_active on
#pragma scheduling off

struct Node {
    Node* next;
};

struct List {
    unsigned count;
    Node* head;
};

extern "C" Node* fn_79_1734(void*, List* list) {
    Node* node = list->head;
    unsigned i = 0;
    unsigned count = list->count;

    for (; i != count; ++i) {
        if (i == count - 1)
            return node;
        node = node->next;
    }

    return 0;
}
