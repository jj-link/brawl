#pragma force_active on

struct Node {
    void* vtable;
    unsigned short size;
    unsigned short refs;
};

struct SoHeapAllocator {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual Node* alloc(unsigned long, int);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern int lbl_80487290[6];

struct Object {
    Node* entries[64];
    Node* value;
};

extern "C" Object* fn_802CAD5C(Object* self) {
    Node* node = lbl_805A0EB8->alloc(8, 0x1F);
    node->size = 8;
    if (node) {
        node->refs = 1;
        node->vtable = &lbl_80487290;
    }
    self->value = node;
    for (int i = 0; i < 64; ++i) {
        self->entries[i] = self->value;
    }
    return self;
}
