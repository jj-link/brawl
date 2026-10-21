#include <types.h>
#pragma force_active on

struct FtSizedArray {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 size();
};

struct FtSizedAggregate {
    void* vtable;
    u32 cache[3];
    FtSizedArray* a;
    FtSizedArray* b;
    FtSizedArray* c;
};

extern "C" s32 fn_112_AB5C(FtSizedAggregate* arrays) {
    s32 size = arrays->c->size();
    if (size < arrays->a->size()) {
        size = arrays->a->size();
    }
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    return size;
}
