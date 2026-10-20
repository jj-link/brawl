#include <types.h>
#pragma force_active on

struct Obj {
    virtual void* v0();
    virtual void* v1(s32);
};

struct Data {
    u8 pad[4];
    s16 m4;
    s16 m6;
};

extern "C" void fn_27_41770(void*, void*, void*);

extern "C" {
void fn_27_42954(Data* d, Obj* obj, void* a, void* b) {
    for (s32 i = 0; i < d->m6; i++) {
        fn_27_41770(obj->v1(d->m4 + i), a, b);
    }
}
}
