#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_1E728[];
extern char lbl_27_bss_298[];
void fn_27_2E818(void*);
void fn_27_2E888(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
void* fn_27_319E40(void*, void*, void*, void*, void*);
}

struct Flags {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 25;
};

struct Object {
    void* vtable;
    void* calcVtable;
    Flags flags;
    char array[0x44];
};

extern "C" Object* fn_27_314A30(Object* self, void* arg1, void* arg2) {
    self->calcVtable = lbl_27_data_1E728 + 0x48;
    self->flags.a = 0;
    self->flags.b = 1;
    self->flags.c = 0;
    self->vtable = lbl_27_data_1E728;
    __construct_array(self->array, fn_27_2E818, fn_27_2E888, 0x44, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calcVtable, 1, 1);
    fn_27_319E40((char*)self + 0x50, arg1, self, arg2, lbl_27_bss_298);
    return self;
}
