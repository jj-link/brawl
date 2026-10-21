#pragma force_active on
extern "C" char lbl_27_data_1BFA8[];
extern "C" void fn_27_CE0BC(void);
extern "C" void fn_27_25290(void);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* self, unsigned long arg, long count);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

struct SoBits {
    unsigned long a : 6;
    unsigned long b : 3;
    unsigned long c : 1;
    unsigned long d : 22;
};

extern "C" void* fn_27_CF8A8(void* self, unsigned long arg) {
    char* p = (char*)self;
    char* vt = lbl_27_data_1BFA8;
    *(char**)(p + 0x0) = vt;
    vt += 0x48;
    *(char**)(p + 0x4) = vt;
    SoBits* bits = (SoBits*)(p + 0x8);
    bits->a = 0;
    bits->b = arg;
    bits->c = 0;
    __construct_array(p + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 3);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(p + 0x4, arg, 3);
    return self;
}
