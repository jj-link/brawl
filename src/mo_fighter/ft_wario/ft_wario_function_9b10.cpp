#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual u32* slot1(s32 index);
    virtual void slot2();
    virtual s32 slot3();
};

struct WarioArrayAggregate {
    void* vtable;
    u32 cache[3];
    Object_vptr_0* a;
    Object_vptr_0* b;
    Object_vptr_0* c;
};

struct WarioArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

extern "C" WarioArrayTriple fn_110_9B10(WarioArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        WarioArrayTriple result = { 0, 0, 0 };
        return result;
    }
    u32 c = 0;
    if (index < arrays->c->slot3()) {
        c = *arrays->c->slot1(index);
    }
    u32 a = 0;
    if (index < arrays->a->slot3()) {
        a = *arrays->a->slot1(index);
    }
    u32 b = 0;
    if (index < arrays->b->slot3()) {
        b = *arrays->b->slot1(index);
    }
    WarioArrayTriple result = { c, a, b };
    return result;
}
