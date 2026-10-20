#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_397F8[];
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* iface, long a, long b);
}

struct fnBits_27 {
    u32 a : 4;
    u32 b : 2;
    u32 c : 1;
    u32 d : 25;
};

extern "C" u32* fn_27_19A2DC(u32* self, u32 arg) {
    fnBits_27* bits = (fnBits_27*)(self + 2);
    self[0] = (u32)lbl_27_data_397F8;
    self[1] = (u32)(lbl_27_data_397F8 + 0x48);
    bits->a = 0;
    bits->b = arg;
    bits->c = 0;
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((void*)(self + 1), (long)arg, 1);
    return self;
}
