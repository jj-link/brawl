#include <so/so_array.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual u32* slot1(int);
    virtual void slot2();
    virtual int slot3();
};

struct WolfArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct WolfArrayAggregate {
    void* vtable;
    WolfArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" WolfArrayTriple fn_125_B4D8(WolfArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        WolfArrayTriple result = { 0, 0, 0 };
        return result;
    }

    u32 c = 0;
    if (index < arrays->c->size()) {
        c = arrays->c->at(index);
    }

    u32 a = 0;
    if (index < arrays->a->size()) {
        a = arrays->a->at(index);
    }

    u32 b = 0;
    if (index < arrays->b->size()) {
        b = arrays->b->at(index);
    }

    WolfArrayTriple result = { c, a, b };
    return result;
}
