#include <types.h>
#pragma force_active on

extern "C" void exit__6gfTaskFv(void*);
extern "C" void fn_8018E808(void*);

struct ObjPad {
    u8 pad[0x5c];
};

struct Obj : ObjPad {
    virtual void slot00(int);
    virtual void slot04(int);
    virtual void slot08(int);
};

struct Self {
    u8 pad0[0x40];
    u8 f40[4];
    u8 f44[4];
    void* f48;
    Obj* f4C;
    Obj* f50;
};

extern "C" void fn_23_5D8(Self* self) {
    exit__6gfTaskFv(self->f48);
    self->f48 = 0;
    fn_8018E808(&self->f40);
    fn_8018E808(&self->f44);
    Obj* a = self->f4C;
    if (a) {
        a->slot00(1);
    }
    self->f4C = 0;
    Obj* b = self->f50;
    if (b) {
        b->slot00(1);
    }
    self->f50 = 0;
}
