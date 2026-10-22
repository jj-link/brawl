#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1BAD0[];
void fn_27_CE0BC(void);
void fn_27_25290(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 lo : 14;
        u32 value : 7;
        u32 flag : 1;
        u32 rest : 10;
    } bits;
};

struct Obj {
    void* unk0;
    void* unk4;
    Flags flags;
};

extern "C" Obj* fn_27_D00A0(Obj* self, u32 value) {
    Flags f;
    f.raw = self->flags.raw;
    self->unk0 = (void*)lbl_27_data_1BAD0;
    self->unk4 = (void*)(lbl_27_data_1BAD0 + 0x48);
    f.bits.lo = 0;
    f.bits.value = value;
    f.bits.flag = 0;
    self->flags = f;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 0x24);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 4, value, 0x24);
    return self;
}
