#include <types.h>
#pragma force_active on

extern "C" void __dla__FPv(void*);
extern "C" void fn_8018E808(void*);

struct Base {
    char pad[0x5C];
};

struct Entry : Base {
    virtual void destroy(int);
    virtual void f1();
};

struct Sub8 {
    char pad[8];
};

struct Obj {
    char pad0[0x48];
    Sub8 m48;
    Entry* m50;
    Entry* m54;
    Entry* m58;
    char pad1[0x68 - 0x5C];
    void** m68;
    u32 m6C;
};

extern "C" void fn_24_1EC4(Obj* self) {
    u32 i = 0;
    s32 off = 0;
    while (i < self->m6C) {
        __dla__FPv(*(void**)((char*)self->m68 + off));
        i++;
        *(void**)((char*)self->m68 + off) = 0;
        off += 4;
    }
    __dla__FPv(self->m68);
    Entry* t = self->m50;
    self->m68 = 0;
    self->m6C = 0;
    if (t != 0) {
        t->destroy(1);
    }
    t = self->m54;
    self->m50 = 0;
    if (t != 0) {
        t->destroy(1);
    }
    t = self->m58;
    self->m54 = 0;
    if (t != 0) {
        t->destroy(1);
    }
    self->m58 = 0;
    fn_8018E808(&self->m48);
    fn_8018E808(&self->m48);
}
