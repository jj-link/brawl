#pragma force_active on
typedef struct Node {
    char pad[0x1c];
    struct Node* parent;
    struct Node* first;
    struct Node* next;
} Node;

extern "C" void fn_40_38CE0(Node* self, Node* node) {
    node->parent = self;
    Node* cur = self->first;
    if (cur == 0) {
        self->first = node;
        return;
    }
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = node;
}
