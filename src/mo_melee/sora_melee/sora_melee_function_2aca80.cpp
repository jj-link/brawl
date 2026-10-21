#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

struct Node {
    u8 active : 1;
    u8 rest : 7;
    char pad[7];
    s8 prev;
    s8 next;
    char pad2[2];
};

struct Object {
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

extern "C" void fn_27_2ACA80(Object* self) {
    self->flags = ((self->flags & 0x07ffffff) | 0x07fe0000) & 0xfffe0fff;

    if (self->count() == 1) {
        self->nodes[0].prev = -1;
        self->nodes[0].next = -1;
        self->nodes[0].active = 0;
        return;
    }

    for (int i = 0; i < self->count(); ++i) {
        self->nodes[i].prev = i - 1;
        self->nodes[i].next = i + 1;
        self->nodes[i].active = 0;
    }

    Node* last = &self->nodes[self->count() - 1];
    last->next = -1;
}
