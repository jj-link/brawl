#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_1EFC8[];
void __ct__16soCollisionGroupFv(void*);
void* fn_27_37D3C(void* p, s32 n);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* self, u32 iface, s32 a);
}

struct SoBits {
    u32 a : 6;
    u32 f : 3;
    u32 g : 1;
    u32 b : 22;
};

extern "C" void* fn_27_CB770(void* self, u32 arg) {
    u8* p = (u8*)self;
    SoBits* bits = (SoBits*)(p + 0x8);
    *(u8**)(p + 0x0) = lbl_27_data_1EFC8;
    *(u8**)(p + 0x4) = lbl_27_data_1EFC8 + 0x48;
    bits->a = 0;
    bits->f = arg;
    bits->g = 0;
    __construct_array(p + 0xC, (void (*)(void*))__ct__16soCollisionGroupFv, (void (*)(void*))fn_27_37D3C, 0x78, 2);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(p + 0x4, arg, 2);
    return self;
}
