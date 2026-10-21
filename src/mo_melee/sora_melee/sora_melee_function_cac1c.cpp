#pragma force_active on
typedef unsigned long u32;

extern "C" {
extern char lbl_27_data_1F5F0[];

void fn_27_A6948(void*);
void fn_27_A6978(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

struct Obj {
    void* vt0;
    void* vt1;
    u32 size : 8;
    u32 count : 4;
    u32 flag : 1;
    u32 rest : 19;
    char elems[7][0x24];
};

extern "C" Obj* fn_27_CAC1C(Obj* self, int n) {
    self->vt0 = lbl_27_data_1F5F0;
    self->vt1 = lbl_27_data_1F5F0 + 0x48;
    self->size = 0;
    self->count = n;
    self->flag = 0;
    __construct_array(self->elems, fn_27_A6948, fn_27_A6978, 0x24, 7);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->vt1, n, 7);
    return self;
}
