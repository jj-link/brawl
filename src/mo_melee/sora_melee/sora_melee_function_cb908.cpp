#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1EED8[];
extern "C" void* fn_27_37D3C(void*, s32);
extern "C" void __ct__16soCollisionGroupFv(void*);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, s32, s32);

struct soFlagsWork {
    u32 a : 8;
    u32 b : 4;
    u32 c : 1;
    u32 d : 19;
};

extern "C" void* fn_27_CB908(void* self, s32 arg) {
    u8* p = (u8*)self;
    soFlagsWork* w = (soFlagsWork*)(p + 0x8);
    *(char**)(p + 0x0) = lbl_27_data_1EED8;
    *(char**)(p + 0x4) = lbl_27_data_1EED8 + 0x48;
    w->a = 0;
    w->b = arg;
    w->c = 0;
    __construct_array(p + 0xC, (void (*)(void*))__ct__16soCollisionGroupFv,
                      (void (*)(void*))fn_27_37D3C, 0x78, 5);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(p + 0x4, arg, 5);
    return self;
}
