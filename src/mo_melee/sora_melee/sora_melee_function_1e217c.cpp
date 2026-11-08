#include <so/so_array.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual u32* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
};

struct ArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct ArrayAggregate {
    void* vtable;
    ArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

static inline ArrayTriple getTriple(ArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        ArrayTriple result = { 0, 0, 0 };
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

    ArrayTriple result = { c, a, b };
    return result;
}

extern "C" ArrayTriple* fn_27_1E217C(ArrayAggregate* arrays, s32 index) {
    return &getTriple(arrays, index);
}
