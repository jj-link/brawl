#include <types.h>
#pragma force_active on

extern char lbl_27_data_1E938[];
extern "C" void fn_27_9FA50(void*, int);
extern "C" void fn_27_9FA44(void*);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), u32, int);

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void postInitialize(soArrayVectorCalcInterface& iface, long n, long m);
};

struct SoArrayVectorBits {
    u32 a : 4;
    u32 b : 2;
    u32 c : 1;
    u32 d : 25;
};

extern "C" void* fn_27_CBEC8(void* self, void* iface) {
    char* p = (char*)self;
    SoArrayVectorBits* bits = (SoArrayVectorBits*)(p + 8);
    char* vt = lbl_27_data_1E938;
    *(char**)(p + 0) = vt;
    vt += 0x48;
    *(char**)(p + 4) = vt;
    bits->a = 0;
    bits->b = (u32)iface;
    bits->c = 0;
    __construct_array(p + 0xC, (void (*)(void*))fn_27_9FA44, (void (*)(void*))fn_27_9FA50, 0x2C, 1);
    long unusedSecond;
    ((soArrayVectorCalculator*)(p + 4))->postInitialize(*(soArrayVectorCalcInterface*)iface, 1, unusedSecond);
    return self;
}
