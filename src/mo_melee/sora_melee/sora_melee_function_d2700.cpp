#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_1A780[];
void fn_27_8655C(void*);
void fn_27_D2680(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
}

struct Data {
    void* vtable;
    void* calcVtable;
    unsigned int a : 10;
    unsigned int b : 5;
    unsigned int c : 1;
    unsigned int d : 16;
    unsigned char array[8 * 0x34];
};

extern "C" Data* fn_27_D2700(Data* self, int count) {
    self->vtable = lbl_27_data_1A780;
    self->calcVtable = lbl_27_data_1A780 + 0x48;
    self->a = 0;
    self->b = count;
    self->c = 0;
    __construct_array(self->array, fn_27_D2680, fn_27_8655C, 0x34, 8);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calcVtable, count, 8);
    return self;
}
