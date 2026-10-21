#pragma force_active on
extern "C" char lbl_27_data_1CC40[];
extern "C" void fn_27_CE0BC(void);
extern "C" void fn_27_25290(void);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, void*, long);

struct soBits {
    unsigned int top : 10;
    unsigned int f : 5;
    unsigned int c : 1;
    unsigned int low : 16;
};

extern "C" {
void* fn_27_CE3F0(void* self, int arg) {
    char* base = (char*)self;
    soBits* b = (soBits*)(base + 8);
    *(char**)(base + 0) = lbl_27_data_1CC40;
    *(char**)(base + 4) = lbl_27_data_1CC40 + 0x48;
    b->top = 0;
    b->f = arg;
    b->c = 0;
    __construct_array(base + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 0xE);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(base + 4, (void*)arg, 0xE);
    return self;
}
}
