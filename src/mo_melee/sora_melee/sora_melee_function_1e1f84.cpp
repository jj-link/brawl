#include <types.h>
#pragma force_active on

class IntfArray {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual s32 size();
};

struct FnArrayAggregate {
    void* vtable;
    u32 cache[3];
    IntfArray* a;
    IntfArray* b;
    IntfArray* c;
};

extern "C" s32 fn_27_1E1F84(FnArrayAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}
