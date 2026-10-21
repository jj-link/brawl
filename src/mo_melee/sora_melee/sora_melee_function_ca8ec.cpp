#pragma force_active on
typedef unsigned long u32;

extern "C" {
extern char lbl_27_data_1F7D0[];
void fn_27_A6948(void*);
void fn_27_A6978(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

struct Object {
    void* vt0;
    void* vt1;
    u32 first : 10;
    u32 count : 5;
    u32 flag : 1;
    u32 rest : 16;
    char elems[15][0x24];
};

extern "C" Object* fn_27_CA8EC(Object* self, long count) {
    self->vt0 = lbl_27_data_1F7D0;
    self->vt1 = lbl_27_data_1F7D0 + 0x48;
    self->first = 0;
    self->count = count;
    self->flag = 0;
    __construct_array(self->elems, fn_27_A6948, fn_27_A6978, 0x24, 15);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->vt1, count, 15);
    return self;
}
