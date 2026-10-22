#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void call(f32 f);
};

struct Foo {
    char pad[0x18];
    s32 count;
    void** arr;
};

extern "C" void fn_8019A1B0(Foo* self, f32 f) {
    s32 offset = 0;
    s32 i = 0;
    while (i < self->count) {
        Obj* obj = (Obj*)*(void**)((char*)self->arr + offset);
        if (obj) {
            obj->call(f);
        }
        offset += 4;
        i++;
    }
}
