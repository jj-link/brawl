#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1C480[];
void fn_27_25290(void*, int);
void fn_27_CE0BC(void);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 12;
        u32 value : 6;
        u32 flag : 1;
        u32 rest : 13;
    } bits;
};

struct Obj {
    void* vt;
    void* calc;
    Flags flags;
};

extern "C" void* fn_27_CF0B0(void* self, u32 value) {
    Obj* s = (Obj*)self;
    s->vt = lbl_27_data_1C480;
    s->calc = lbl_27_data_1C480 + 0x48;
    s->flags.raw &= 0x000FFFFF;
    s->flags.bits.value = value;
    s->flags.bits.flag = 0;
    __construct_array((char*)s + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 0x19);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((char*)s + 4, value, 0x19);
    return self;
}
