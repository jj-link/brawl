#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_1F6E0[];
void fn_27_A6948(void*);
void fn_27_A6978(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, void*, long);
}

struct FlagWordBits {
    u32 a : 12;
    u32 b : 6;
    u32 c : 1;
    u32 d : 13;
};

extern "C" void* fn_27_CAA84(void* self, int arg) {
    u32* p = (u32*)self;
    union {
        u32 w;
        FlagWordBits f;
    } u;
    u.w = p[2];
    char* vt = lbl_27_data_1F6E0;
    p[0] = (u32)vt;
    vt += 0x48;
    p[1] = (u32)vt;
    u.f.a = 0;
    u.f.b = arg;
    u.f.c = 0;
    p[2] = u.w;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_A6948, (void (*)(void*))fn_27_A6978, 0x24, 0x11);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((char*)self + 4, (void*)arg, 0x11);
    return self;
}
