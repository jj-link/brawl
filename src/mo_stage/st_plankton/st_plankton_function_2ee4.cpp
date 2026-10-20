#pragma force_active on
struct Node {
    Node* next;
};

struct List {
    unsigned int count;
    Node* first;
};

extern "C" Node* fn_74_2EE4(void*, List* list, unsigned int index) {
    if (!list)
        return 0;

    unsigned int count = list->count;
    Node* node = list->first;
    unsigned char i = 0;

    for (unsigned int j = 0; j != count; ++j) {
        if (i == index)
            return node;
        node = node->next;
        ++i;
    }

    return 0;
}
