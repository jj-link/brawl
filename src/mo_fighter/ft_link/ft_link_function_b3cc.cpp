#include <types.h>
#pragma force_active on

class SizedArray {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual s32 size();
};

struct SizedArrayAggregate {
    void* vtable;
    u32 cache[3];
    SizedArray* a;
    SizedArray* b;
    SizedArray* c;
};

extern "C" s32 fn_93_B3CC(SizedArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}
