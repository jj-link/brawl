#pragma force_active on
struct Node {
    Node* next;
    unsigned int padding[2];
    float value;
};

struct List {
    unsigned int count;
    Node* first;
};

extern "C" const float lbl_74_rodata_90;

extern "C" Node* fn_74_2C98(Node* node, List* list, float delta) {
    if (!list)
        return node;

    unsigned int count = list->count;
    node = list->first;

    for (unsigned int i = 0; i != count; ++i) {
        node->value -= delta;
        if (node->value < lbl_74_rodata_90)
            node->value = lbl_74_rodata_90;
        node = node->next;
    }

    return node;
}
