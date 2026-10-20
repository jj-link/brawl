#include <types.h>
#pragma force_active on

struct Data;
struct Obj;

struct Provider {
    virtual void* v0();
    virtual Data* v1(s32);
};

struct Context {
    u8 pad0[0x30];
    Obj* obj;
    u8 pad34[0x24];
    Provider* provider;
};

extern "C" void fn_27_42954(Data*, Obj*, void*, void*);

extern "C" void fn_27_450D4(Context* self, void* a, void* b, s32 index) {
    Data* data = self->provider->v1(index);
    fn_27_42954(data, self->obj, a, b);
}
