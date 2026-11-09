#include <types.h>
#pragma force_active on

struct Node {
    u8 flag : 1;
    u8 flrest : 7;
    u8 pad[0xF];
    s8 prev;
    s8 next;
    u8 pad2[2];
    bool used() const { return flag != 0; }
};

struct Bits {
    int head : 5;
    int pad : 10;
    int count : 5;
    int rest : 12;
};

struct List {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int getMax();
    virtual u32 getState();
    Bits b;
    Node nodes[1];
    int getFreeIndex() const { return b.head; }
};

extern "C" int fn_27_2BC204(List* self, int idx) {
    if (self->getState() == 1) return -1;
    if (idx < 0) {
        int r = self->getFreeIndex();
        self->b.head = self->nodes[self->b.head].next;
        if (self->b.head > 0) self->nodes[self->b.head].prev = -1;
        self->b.count = self->b.count + 1;
        return r;
    }
    if (idx >= self->getMax()) return -1;
    Node* n = &self->nodes[idx];
    if ((u32)n->used() == 1) return -1;
    int q = n->next;
    int p = n->prev;
    if (p < 0 && q < 0) {
        self->b.head = -1;
    } else if (p < 0) {
        self->nodes[q].prev = -1;
        self->b.head = n->next;
    } else if (q < 0) {
        self->nodes[p].next = -1;
    } else {
        self->nodes[p].next = q;
        self->nodes[q].prev = p;
    }
    self->b.count = self->b.count + 1;
    return idx;
}