#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

extern "C" char lbl_27_data_1A108[];
extern "C" void fn_27_86D4C(void*, int);
extern "C" void fn_27_D3188(void*);
extern "C" void __construct_array(
    void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);

struct FnObj27Bits {
    u32 a : 4;
    u32 f : 2;
    u32 b : 1;
    u32 c : 25;
};

struct FnObj27 {
    void* m_vtbl;
    void* m_vtbl2;
    FnObj27Bits m_bits;
    u8 m_arr[0xA0];
};

extern "C" FnObj27* fn_27_D2FF0(FnObj27* self, long arg) {
    self->m_vtbl = lbl_27_data_1A108;
    self->m_vtbl2 = lbl_27_data_1A108 + 0x48;
    self->m_bits.a = 0;
    self->m_bits.f = arg;
    self->m_bits.b = 0;
    __construct_array(
        self->m_arr,
        (void (*)(void*))fn_27_D3188,
        (void (*)(void*))fn_27_86D4C,
        0xA0,
        1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->m_vtbl2, arg, 1);
    return self;
}
