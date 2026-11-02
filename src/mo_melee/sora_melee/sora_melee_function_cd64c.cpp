#pragma force_active on

extern "C" {
extern char lbl_27_data_1D710[];
void __construct_array(void*, void* (*)(void*), void* (*)(void*, short), int, int);
void* fn_27_CD5E0(void*);
void* fn_27_46700(void*, short);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
    void*, void*, int, int, int, int, int);
}

struct O {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int);
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual int v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual int v27();
    virtual int v28();

    void* p4;
    unsigned int f8;
    char arr[0x60];
};

extern "C" void* fn_27_CD64C(O* self, void* a, int arg2) {
    *(void**)self = lbl_27_data_1D710;
    self->p4 = lbl_27_data_1D710 + 0x48;
    self->f8 &= 0x01FFFFFF;
    __construct_array(self->arr, fn_27_CD5E0, fn_27_46700, 0x60, 1);
    int n = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
        &self->p4, a, self->v4(), self->v14(), self->v13(), self->v27(), self->v28());
    for (int i = 0; i < n; i++) {
        self->v10(arg2);
    }
    return self;
}
