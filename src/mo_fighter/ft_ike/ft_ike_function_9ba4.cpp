#include <so/so_array.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual u32* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
};

struct Fn9BA4Triple {
    u32 a;
    u32 b;
    u32 c;
};

struct Fn9BA4Obj {
    u8 pad[0x10];
    Object_vptr_0* f10;
    Object_vptr_0* f14;
    Object_vptr_0* f18;
};

extern "C" Fn9BA4Triple fn_119_9BA4(Fn9BA4Obj* obj, s32 index) {
    if (index < 0) {
        Fn9BA4Triple zero = { 0, 0, 0 };
        return zero;
    }
    u32 a = 0;
    if (index < obj->f18->slot3()) {
        a = *obj->f18->slot1(index);
    }
    u32 b = 0;
    if (index < obj->f10->slot3()) {
        b = *obj->f10->slot1(index);
    }
    u32 c = 0;
    if (index < obj->f14->slot3()) {
        c = *obj->f14->slot1(index);
    }
    Fn9BA4Triple result = { a, b, c };
    return result;
}
