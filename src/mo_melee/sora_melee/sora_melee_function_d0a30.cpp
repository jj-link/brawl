#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1B500[];
void fn_27_CE0BC(void);
void fn_27_25290(void);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, void*, long);
}

struct SoBits {
    u32 a : 14;
    u32 b : 7;
    u32 c : 1;
    u32 d : 10;
};

extern "C" void* fn_27_D0A30(void* self, u32 arg) {
    char* p = (char*)self;
    SoBits* s = (SoBits*)(p + 8);
    *(void**)p = lbl_27_data_1B500;
    *(void**)(p + 4) = lbl_27_data_1B500 + 0x48;
    s->a = 0;
    s->b = arg;
    s->c = 0;
    __construct_array(p + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 0x34);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(p + 4, (void*)arg, 0x34);
    return self;
}
