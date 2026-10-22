#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void cb(unsigned, unsigned, void*);
};

struct Self {
    char pad[0xcc];
    unsigned mask;
    char pad2[0x2888 - 0xd0];
    Obj* obj;
};

extern "C" void fn_801ABA14(void*, int, int, Obj*);

static inline int test(Self* s, unsigned a) {
    if (a < 9 && ((1 << (a - 1)) & s->mask)) return 1;
    return 0;
}

extern "C" void fn_801AC4A8(Self* self, int a, int b, Obj* c) {
    if (test(self, a) == 0) {
        switch (a) {
        case 0x10001:
            if (self->obj == c) {
                self->obj->cb(0x10003, 0, self);
                self->obj = 0;
                break;
            }
        default:
            fn_801ABA14(self, a, b, c);
        }
    }
}
