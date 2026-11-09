#include <so/so_array.h>
#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual u32* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
};

struct CaptainTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct CaptainAggregate {
    void* vtable;
    CaptainTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" CaptainTriple fn_100_9B2C(CaptainAggregate* arrays, s32 index) {
    if (index < 0) {
        CaptainTriple result = { 0, 0, 0 };
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
    CaptainTriple result = { c, a, b };
    return result;
}
