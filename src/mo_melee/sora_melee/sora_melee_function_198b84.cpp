#include <types.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_3A428[];
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

struct Elem {
    s8 v;
    Elem() : v(-1) { }
};

struct Obj {
    void* vt0;
    void* vt1;
    u32 top : 3;
    u32 last : 3;
    u32 size : 3;
    u32 isFull : 1;
    Elem elems[2];

    Obj(s32 sz) : vt0(lbl_27_data_3A428), vt1(lbl_27_data_3A428 + 0x48), top(0), last(0), size(sz), isFull(false) {
        postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&vt1, sz, 2);
    }
};

extern "C" Obj* fn_27_198B84(Obj* self, s32 sz) {
    return new (self) Obj(sz);
}
