#pragma force_active on
extern "C" void fn_27_5A09C(void* ptr, int count);
extern "C" void fn_27_59FD4(void* p);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* self, void* iface, long n);
extern char lbl_27_data_39D98[];

struct FldBits {
    unsigned int hi : 4;
    unsigned int a : 2;
    unsigned int b : 1;
    unsigned int rest : 25;
};

extern "C" void* fn_27_19982C(char* self, int arg) {
    FldBits* f = (FldBits*)(self + 8);
    *(char**)self = lbl_27_data_39D98;
    *(char**)(self + 4) = lbl_27_data_39D98 + 0x48;
    f->hi = 0;
    f->a = arg;
    f->b = 0;
    __construct_array(self + 0xc, (void (*)(void*))fn_27_59FD4, (void (*)(void*))fn_27_5A09C, 0x8c, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(self + 4, (void*)arg, 1);
    return self;
}
