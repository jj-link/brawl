#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

struct Node {
    u8 active : 1;
    u8 other : 7;
    char pad[19];
    s8 prev;
    s8 next;
    char pad2[2];
};

struct Self {
    virtual void v0();
    virtual void v1();
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
    virtual int count();

    u32 flags;
    Node nodes[1];
};

extern "C" void fn_27_C8C68(Self* self) {
    self->flags = ((self->flags & 0x07FFFFFF) | 0x07FE0000) & 0xFFFE0FFF;

    if (self->count() == 1) {
        self->nodes[0].prev = -1;
        self->nodes[0].next = -1;
        self->nodes[0].active = 0;
    } else {
        Node* node = self->nodes;
        for (int i = 0; i < self->count(); i++, node++) {
            self->nodes[i].prev = i - 1;
            self->nodes[i].next = i + 1;
            node->active = 0;
        }
        Node* last = self->nodes + (self->count() - 1);
        last->next = -1;
    }
}
