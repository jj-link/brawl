#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1FAA0[];
void fn_27_A6948(void*);
void fn_27_A6978(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
}

struct Obj {
    char* p0;
    char* p4;
    u32 size : 10;
    u32 capacity : 5;
    u32 flag : 1;
    u32 rest : 16;
};

extern "C" Obj* fn_27_CA3B8(Obj* self, int n) {
    self->p0 = lbl_27_data_1FAA0;
    self->p4 = lbl_27_data_1FAA0 + 0x48;
    self->size = 0;
    self->capacity = n;
    self->flag = 0;
    __construct_array((char*)self + 0xc, fn_27_A6948,
                      (void (*)(void*))fn_27_A6978, 0x24, 11);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 4, n, 11);
    return self;
}
