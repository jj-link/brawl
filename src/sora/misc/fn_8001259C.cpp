#pragma force_active on
struct Node {
    Node* next;
    char pad[0x18];
    unsigned char flags;
    unsigned char kind;
};
struct Tree {
    char pad[0x18];
    Tree* children[4];
    int count;
    Node* head;
};
class Class_8042B6D0 {
public:
    virtual void fn_8004805C(Node*);
};
extern "C" void fn_8001259C(void* self, Tree* tree, Class_8042B6D0* callback, unsigned int kind) {
    unsigned int i = 0;
    Tree* cursor = tree;
    for (; i < 4; i++, cursor = (Tree*)((char*)cursor + 4)) {
        if (cursor->children[0])
            fn_8001259C(self, cursor->children[0], callback, kind);
    }
    if (tree->count) {
        Node* head = (Node*)&tree->head;
        Node* node = tree->head;
        while (node != head) {
            if (((node->flags >> 7) & 1) && kind == node->kind)
                callback->fn_8004805C(node);
            node = node->next;
        }
    }
}