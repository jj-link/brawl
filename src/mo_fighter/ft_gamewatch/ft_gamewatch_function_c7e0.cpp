#include <so/so_array.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual u32* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
};

struct Gw107Triple {
    u32 a;
    u32 b;
    u32 c;
};

struct Gw107Src {
    void* vtable;
    u32 pad[3];
    Object_vptr_0* b;
    Object_vptr_0* c;
    Object_vptr_0* a;
};

extern "C" Gw107Triple fn_107_C7E0(Gw107Src* src, s32 index) {
    if (index < 0) {
        Gw107Triple zero = { 0, 0, 0 };
        return zero;
    }

    u32 a = 0;
    if (index < src->a->slot3()) {
        a = *src->a->slot1(index);
    }

    u32 b = 0;
    if (index < src->b->slot3()) {
        b = *src->b->slot1(index);
    }

    u32 c = 0;
    if (index < src->c->slot3()) {
        c = *src->c->slot1(index);
    }

    Gw107Triple result = { a, b, c };
    return result;
}
