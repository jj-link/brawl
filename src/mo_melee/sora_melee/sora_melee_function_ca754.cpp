#pragma force_active on
typedef unsigned long u32;

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern char lbl_27_data_1F8C0[];
void fn_27_A6948(void*);
void fn_27_A6978(void*, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);

struct soBits8 {
    u32 a : 10;
    u32 b : 5;
    u32 c : 1;
    u32 d : 16;
};

char* fn_27_CA754(char* self, int arg) {
    soBits8* bits = (soBits8*)(self + 8);
    *(char**)self = lbl_27_data_1F8C0;
    *(char**)(self + 4) = lbl_27_data_1F8C0 + 0x48;
    bits->a = 0;
    bits->b = arg;
    bits->c = 0;
    __construct_array(self + 0xc, (void (*)(void*))fn_27_A6948, (void (*)(void*))fn_27_A6978, 0x24, 0xd);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(self + 4, arg, 0xd);
    return self;
}
}
