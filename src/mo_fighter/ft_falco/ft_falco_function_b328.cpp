#include <types.h>
#pragma force_active on

struct ArrayBase {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual int count() = 0;
};

struct FalcoArrayAggregate {
    void* vtable;
    u32 c;
    u32 a;
    u32 b;
    ArrayBase* arr_a;
    ArrayBase* arr_b;
    ArrayBase* arr_c;
};

extern "C" int fn_108_B328(const FalcoArrayAggregate* arrays) {
    int size = arrays->arr_c->count();
    if (size < arrays->arr_a->count()) {
        size = arrays->arr_a->count();
    }
    if (size < arrays->arr_b->count()) {
        size = arrays->arr_b->count();
    }
    return size;
}
