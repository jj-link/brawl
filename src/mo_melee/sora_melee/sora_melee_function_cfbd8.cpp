#pragma force_active on
typedef unsigned int u32;

extern "C" {
    extern char lbl_27_data_1BDB8[];
    void fn_27_CE0BC(void);
    void fn_27_25290(void);
    void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
    void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, long);
}

struct ArrayVector {
    void* vt0;
    void* vt4;
    u32 top : 14;
    u32 size : 7;
    u32 flag : 1;
    u32 low : 10;
};

extern "C" void* fn_27_CFBD8(void* self, int arg) {
    ArrayVector* p = (ArrayVector*)self;
    p->top = 0;
    p->vt0 = lbl_27_data_1BDB8;
    p->vt4 = lbl_27_data_1BDB8 + 0x48;
    p->size = arg;
    p->flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 0x20);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 4, arg, 0x20);
    return self;
}
