#pragma force_active on

struct Node {
    Node* next;
    char pad[0x1c];
};

struct Entry {
    unsigned char a, b, c;
    unsigned short d;
    int e;
};

struct Obj {
    char pad[0x84];
    Entry entries[8];
    short count;
    unsigned char flag;
    Node* nodes;
};

extern Entry lbl_80495380;

extern "C" void fn_8002C8C0(Obj* self, int count, Node* nodes) {
    Entry value;
    self->flag = 0;
    self->count = count;
    self->nodes = nodes;
    if (count != 0) {
        int i = 0;
        for (; i < count - 1; i++) {
            self->nodes[i].next = &self->nodes[i + 1];
        }
        self->nodes[count - 1].next = 0;
    }
    value = lbl_80495380;
    for (int j = 0; j < 8; j++) {
        self->entries[j] = value;
    }
}
