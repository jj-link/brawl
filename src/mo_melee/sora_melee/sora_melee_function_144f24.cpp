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
    char pad[0x1094];
    Node* head;
};

extern "C" int fn_27_700D0(void*, int, int, int, int, int);

inline Node* findNode(Owner* self, int id, int flags, int key,
                      unsigned char type, int kind) {
    Node* n = self->head;
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

extern "C" int fn_27_144F24(Owner* self, int id, int flags, int key,
                           int a, int b, int c) {
    Node* n = findNode(self, id, flags, key, 0xFF, 0xFF);
    if (n) {
        return fn_27_700D0(n->value, 1, a, c, 0, b);
    }
    return 0;
}
