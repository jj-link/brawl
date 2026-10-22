#include <types.h>
#pragma force_active on

struct Elem {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(float f);
};

struct Owner {
    char pad[0x18];
    s32 count;
    Elem** arr;
};

extern "C" void fn_8019A0D4(Owner* self, float f) {
    for (s32 i = 0; i < self->count; i++) {
        Elem* e = self->arr[i];
        if (e != 0) {
            e->v7(f);
        }
    }
}
