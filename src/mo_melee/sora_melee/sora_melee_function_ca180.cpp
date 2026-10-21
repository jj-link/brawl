#include <types.h>
#pragma force_active on

struct Flags {
    u32 a : 5;
    u32 b : 5;
    u32 count : 5;
    u32 flag : 1;
    u32 rest : 16;
};

extern "C" {
void fn_27_A6948(void*);
void fn_27_A6978(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
extern char lbl_27_data_1FB90[];

char* fn_27_CA180(char* self, int count) {
    *(void**)self = lbl_27_data_1FB90;
    *(void**)(self + 4) = lbl_27_data_1FB90 + 0x48;

    Flags* flags = (Flags*)(self + 8);
    flags->a = 0;
    flags->b = 0;
    flags->count = count;
    flags->flag = 0;

    __construct_array(self + 0xC, fn_27_A6948,
                      (void (*)(void*))fn_27_A6978, 0x24, 10);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        self + 4, count, 10);
    return self;
}
}
