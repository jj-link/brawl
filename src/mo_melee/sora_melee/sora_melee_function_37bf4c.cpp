#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

union Flags {
    u32 raw;
    struct {
        u32 pad : 8;
        u32 value : 4;
        u32 flag : 1;
        u32 rest : 19;
    } bits;
};

struct Obj {
    void* m_vtbl;
    void* m_iface;
    Flags m_flags;
};

extern "C" {
extern u8 lbl_27_data_3CC78[];
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
void fn_27_6A244(void*, void*, void*);

void* fn_27_37BF4C(void* self, void* arg) {
    u8* base = lbl_27_data_3CC78;
    Obj* o = (Obj*)self;
    o->m_vtbl = base;
    o->m_iface = base + 0x48;
    o->m_flags.raw &= 0x00ffffff;
    o->m_flags.bits.value = 7;
    o->m_flags.bits.flag = 0;
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &o->m_iface, 7, 7);
    fn_27_6A244((char*)self + 0x178, arg, self);
    return self;
}
}
