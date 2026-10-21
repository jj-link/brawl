#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" char lbl_27_data_5F4B0[];
extern "C" void fn_27_86D4C(void*, int);
extern "C" void fn_27_D3188(void* p);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* self, long a, long b);

struct FnObj27Bits {
    u32 a : 6;
    u32 f : 3;
    u32 b : 1;
    u32 c : 22;
};

struct FnObj27 {
    void* m_vtbl;
    void* m_vtbl2;
    FnObj27Bits m_bits;
    u8 m_arr[0xA0 * 3];
};

extern "C" FnObj27* fn_27_2919C8(FnObj27* self, long arg) {
    self->m_vtbl = lbl_27_data_5F4B0;
    self->m_vtbl2 = lbl_27_data_5F4B0 + 0x48;
    self->m_bits.a = 0;
    self->m_bits.f = arg;
    self->m_bits.b = 0;
    __construct_array(self->m_arr, (void (*)(void*))fn_27_D3188, (void (*)(void*))fn_27_86D4C, 0xA0, 3);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->m_vtbl2, arg, 3);
    return self;
}
