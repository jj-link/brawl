#include <types.h>
#pragma force_active on

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 flags;
};

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* a, void* b, Obj* c);
};

extern "C" {
void fn_27_4CA78(Base* self, void* a, void* b, Obj* c) {
    if ((c->flags >> 9) & 1) {
        return;
    }
    self->v4(a, b, c);
}
}
