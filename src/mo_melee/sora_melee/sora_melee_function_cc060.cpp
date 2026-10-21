#pragma force_active on
extern "C" {
extern char lbl_27_data_1E728[];
void fn_27_2E818(void*);
void fn_27_2E888(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
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

extern "C" Object* fn_27_CC060(Object* self, int count) {
    self->vtable = lbl_27_data_1E728;
    self->calcVtable = lbl_27_data_1E728 + 0x48;
    self->a = 0;
    self->b = count;
    self->c = 0;
    __construct_array(self->array, fn_27_2E818, fn_27_2E888, 0x44, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calcVtable, count, 1);
    return self;
}
