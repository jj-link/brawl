#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_46F8[];
void __ct__16soCollisionGroupFv(void*);
void* fn_27_37D3C(void*, s32);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, u32, s32);
}

struct SoBits {
    u32 a : 4;
    u32 f : 2;
    u32 g : 1;
    u32 b : 25;
};

extern "C" void* fn_27_CB6E0(void* self, u32 arg) {
    u8* p = (u8*)self;
    SoBits* bits = (SoBits*)(p + 0x8);
    *(u8**)(p + 0x0) = lbl_27_data_46F8;
    *(u8**)(p + 0x4) = lbl_27_data_46F8 + 0x48;
    bits->a = 0;
    bits->f = arg;
    bits->g = 0;
    __construct_array(p + 0xC, __ct__16soCollisionGroupFv,
                      (void (*)(void*))fn_27_37D3C, 0x78, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        p + 0x4, arg, 1);
    return self;
}
