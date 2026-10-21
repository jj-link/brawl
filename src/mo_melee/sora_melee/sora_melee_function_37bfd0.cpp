#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_B215C(void*, void*, void*, void*, void*, void*);
void fn_27_B15E8(void*);
void fn_27_B164C(void*);
extern char lbl_27_data_1F0B8[];
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
}

struct Bits {
    unsigned int top : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 25;
};

struct Obj {
    void* vt;
    void* calc;
    Bits flags;
    char arr[0x44];
};

extern "C" void* fn_27_37BFD0(Obj* self, void* a, void* b, void* c, void* d) {
    unsigned int one = 1;
    self->vt = lbl_27_data_1F0B8;
    self->calc = lbl_27_data_1F0B8 + 0x48;
    self->flags.top = 0;
    self->flags.b = one;
    self->flags.c = 0;
    __construct_array(self->arr, fn_27_B15E8, fn_27_B164C, 0x44, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, 1, 1);
    fn_27_B215C((char*)self + 0x50, a, self, b, c, d);
    return self;
}
