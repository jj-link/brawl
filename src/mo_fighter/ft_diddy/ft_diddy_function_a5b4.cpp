#include <so/so_array.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual u32* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
};

struct DiddyArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct DiddyArrayAggregate {
    void* vtable;
    DiddyArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" DiddyArrayTriple fn_115_A5B4(DiddyArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        DiddyArrayTriple result = { 0, 0, 0 };
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

    DiddyArrayTriple result = { c, a, b };
    return result;
}
