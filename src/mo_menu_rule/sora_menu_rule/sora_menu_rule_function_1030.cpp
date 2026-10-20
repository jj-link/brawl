#include <types.h>
#pragma force_active on

struct Pad {
    char pad[0x668];
};

struct Obj : public Pad {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32 arg);
};

extern "C" void fn_18_1030(void* self, u32 arg) {
    char* p = (char*)self;
    for (int i = 0; i < 4; i++) {
        Obj* o = *(Obj**)(p + 0x268);
        o->f5(arg);
        p += 4;
    }
}
