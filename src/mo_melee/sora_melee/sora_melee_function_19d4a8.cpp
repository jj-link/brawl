#pragma force_active on
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void* fn_27_CD2F8(void*);
extern "C" void fn_27_4D8E0(void*, short);
extern "C" int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, void*, int, int, int, int, int);
extern char lbl_27_data_38A80[];

struct O {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual int s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(void*);
    virtual void s11(); virtual void s12();
    virtual int s13(); virtual int s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual int s27(); virtual int s28();
    void* p4;
    unsigned int f8;
    char arr[0xC0];
};

extern "C" void* fn_27_19D4A8(O* self, void* a, void* b) {
    *(void**)self = lbl_27_data_38A80;
    self->p4 = lbl_27_data_38A80 + 0x48;
    self->f8 &= 0x3FFFFF;
    __construct_array(self->arr, (void (*)(void*))fn_27_CD2F8, (void (*)(void*))fn_27_4D8E0, 0x60, 2);
    int n = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(&self->p4, a, self->s4(), self->s14(), self->s13(), self->s27(), self->s28());
    for (int i = 0; i < n; i++) self->s10(b);
    return self;
}