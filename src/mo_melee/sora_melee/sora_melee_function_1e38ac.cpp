#pragma force_active on
extern "C" {
extern char lbl_27_data_1E728[];
extern char lbl_27_bss_298[];
void fn_27_2E818(void*);
void fn_27_2E888(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
void fn_27_2556C(void*, void*, void*, void*, void*);
}

struct Object {
    void* vtable;
    void* calcVtable;
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 25;
    char array[0x44];
};

extern "C" Object* fn_27_1E38AC(Object* self, void* arg1, void* arg2) {
    self->calcVtable = lbl_27_data_1E728 + 0x48;
    self->a = 0;
    self->b = 1;
    self->vtable = lbl_27_data_1E728;
    self->c = 0;
    __construct_array(self->array, fn_27_2E818, fn_27_2E888, 0x44, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calcVtable, 1, 1);
    fn_27_2556C((char*)self + 0x50, arg1, self, arg2, lbl_27_bss_298);
    return self;
}
