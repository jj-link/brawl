#include <types.h>
#pragma force_active on

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    s32 resize(soArrayVectorCalcInterface& ref, s32 n, bool b1, bool b2, s32 l1, s32 l2, s32 l3);
};

extern "C" void clear__23soArrayVectorCalculatorFR26soArrayVectorCalcInterface(void* self, void* ref);
extern "C" s32 fn_27_C2A58(s32, s32, s32);
extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, s32 n, s32 b, s32 l);

s32 soArrayVectorCalculator::resize(soArrayVectorCalcInterface& ref, s32 n, bool b1, bool b2, s32 l1, s32 l2, s32 l3) {
    s32 t;
    s32 i;
    s32 a = (s32)&ref;

    if (a > (s32)b2) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a == 0) {
        clear__23soArrayVectorCalculatorFR26soArrayVectorCalcInterface((void*)this, (void*)a);
        return 0;
    }
    t = a - fn_27_C2A58(l1, l2, (s32)b2);
    if (t > 0) {
        return t;
    }
    for (i = 0; i < -t; i++) {
        pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)this, n, (s32)b2, l2);
    }
    return 0;
}
