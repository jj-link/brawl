#pragma force_active on
extern int lbl_805A0558;

class Obj_vptr_0 {
public:
    virtual void slot0();
    virtual int slot1(void* self, unsigned int a, unsigned int b);
};

class Child_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(int a, void* b, void* c);
};

struct Owner {
    unsigned char pad0[0xCC];
    unsigned int flags;
    unsigned char pad1[0xDC - 0xD0];
    Child_vptr_0** children;
    unsigned char pad2[0xE4 - 0xE0];
    unsigned int count;
};

extern "C" void fn_801AB8C0(Owner* self, void* arg1, Obj_vptr_0* arg2) {
    unsigned int flags = self->flags;
    int r = arg2->slot1(self, !(flags & 0x20000000), !(flags & 0x40000000));
    if (r == 0) {
        for (unsigned int i = 0; i < self->count; i++) {
            Child_vptr_0* c = self->children[i];
            c->slot1(5, arg1, arg2);
        }
    } else if (r == 1) {
        int saved = lbl_805A0558;
        lbl_805A0558 = 0;
        for (unsigned int i = 0; i < self->count; i++) {
            Child_vptr_0* c = self->children[i];
            c->slot1(5, arg1, arg2);
        }
        lbl_805A0558 = saved;
    }
}
