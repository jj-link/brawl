#pragma force_active on

extern "C" void fn_41_2B52C(void* self, unsigned long node, unsigned long index, unsigned long mode);
extern const float lbl_41_rodata_DC8;

struct Node {
    unsigned long index; // +0
    unsigned long node;  // +4
};

struct NodeList {
    Node* nodes; // +0
    unsigned long count; // +4
};

struct VObj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual unsigned long slot17(unsigned long);
    virtual float slot18();
};

struct Sub {
    char pad0[0xc];
    VObj* a; // +0xc
    char pad1[0x64 - 0x10];
    VObj* b; // +0x64
};

struct Owner {
    char pad[0xd8];
    Sub* sub; // +0xd8
};

struct Self {
    char pad[0x54];
    Owner* owner; // +0x54
    NodeList* list; // +0x58
};

extern "C" void fn_41_2B630(Self* self, unsigned long arg1) {
    if (self->list != 0) {
        unsigned long n = self->list->count;
        float f31 = self->owner->sub->a->slot18();
        if (self->owner->sub->b->slot17(0x12000003) != 1 && lbl_41_rodata_DC8 == f31) {
            unsigned long i = 0;
            while (i < n) {
                fn_41_2B52C(self, self->list->nodes[n - 1 - i].node, self->list->nodes[i].index, arg1);
                i++;
            }
            return;
        }
        for (unsigned long i = 0; i < n; i++) {
            Node* p = &self->list->nodes[i];
            fn_41_2B52C(self, p->node, self->list->nodes[i].index, arg1);
        }
    }
}
