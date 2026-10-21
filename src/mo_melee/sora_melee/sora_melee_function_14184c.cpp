#pragma force_active on

struct Node {
    Node* next;
    char pad04[0x14];
    int key;
    char value[0x14];
    unsigned char type;
    unsigned char id;
    unsigned char kind;
    unsigned char flags : 7;
    unsigned char other : 1;
};

struct Owner {
    char pad[0x1088];
    Node* head;
    char pad108C[8];
    Node* fallback;
};

inline Node* findNode(Node* n, int key, int id, int kind, int flags,
                      unsigned int type) {
    while (n) {
        if ((n->id == 0xFF || n->id == id) &&
            (n->key == -1 || n->key == key) &&
            (n->type == 0xFF || n->type == type) &&
            (n->kind == 0xFF || n->kind == kind) &&
            n->flags == flags) {
            return n;
        }
        n = n->next;
    }
    return 0;
}

extern "C" Node* fn_27_14184C(Owner* self, int key, int id, int kind,
                             int flags, unsigned int type) {
    Node* n = findNode(self->head, key, id, kind, flags, type);
    if (!n) {
        n = findNode(self->fallback, key, id, kind, flags, type);
    }
    return n;
}
