#pragma force_active on
typedef unsigned int u32;

union Flags {
    u32 raw;
    struct {
        u32 top : 14;
        u32 f : 7;
        u32 g : 1;
        u32 low : 10;
    } bits;
};

extern "C" {
extern char lbl_27_data_1B8E0[];
void fn_27_CE0BC(void);
void fn_27_25290(void);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);

void* fn_27_D03D0(void* self, unsigned long arg) {
    char* p = (char*)self;
    *(void**)(p + 0x0) = lbl_27_data_1B8E0;
    *(void**)(p + 0x4) = lbl_27_data_1B8E0 + 0x48;
    Flags fl;
    fl.raw = *(u32*)(p + 0x8);
    fl.bits.top = 0;
    fl.bits.f = arg;
    fl.bits.g = 0;
    *(u32*)(p + 0x8) = fl.raw;
    __construct_array(p + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 0x26);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(p + 0x4, arg, 0x26);
    return self;
}
}
