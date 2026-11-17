#include <types.h>
#include <so/so_array_vector_calculator.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" char lbl_27_data_150C8[];

struct Elem {
    s8 v;
    Elem() : v(-1) { }
};

struct Obj {
    void* vt0;
    void* vt1;
    u32 top : 2;
    u32 last : 2;
    u32 size : 2;
    u32 isFull : 1;
    Elem elems[1];

    Obj(s32 sz) : vt0(lbl_27_data_150C8), vt1(lbl_27_data_150C8 + 0x48), top(0), last(0), size(sz), isFull(false) {
        soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&vt1, sz, 1);
    }
};

extern "C" Obj* fn_27_C9FE4(Obj* self, s32 sz) {
    return new (self) Obj(sz);
}
