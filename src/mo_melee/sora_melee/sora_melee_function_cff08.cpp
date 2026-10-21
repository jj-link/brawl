#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_1BBC8[];
void fn_27_CE0BC();
void fn_27_25290();
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, void*, long);

struct FnHdr {
    u32 hi : 14;
    u32 mid : 7;
    u32 b : 1;
    u32 lo : 10;
};

void* fn_27_CFF08(char* self, void* flag) {
    FnHdr* h = (FnHdr*)(self + 8);
    int count = 0x22;
    char* p = lbl_27_data_1BBC8;
    *(char**)(self + 0) = p;
    p += 0x48;
    *(char**)(self + 4) = p;
    h->hi = 0;
    h->mid = (u32)flag;
    h->b = 0;
    __construct_array(self + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, count);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(self + 4, flag, count);
    return self;
}
}
