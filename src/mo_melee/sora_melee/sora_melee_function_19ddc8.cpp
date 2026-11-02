#pragma force_active on

extern "C" {
extern char lbl_27_data_3D138[];
void* fn_27_CD5E0(void*);
void fn_27_46700(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, void*, int, int, int, int, int, int);
}

struct Obj {
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
    char arr[0x5a0];
};

extern "C" void* fn_27_19DDC8(Obj* self, void* arg1, int arg2) {
    int t14;
    int t13;
    int t27;
    int t28;
    int n;
    int extra;

    *(void**)self = lbl_27_data_3D138;
    self->p4 = lbl_27_data_3D138 + 0x48;
    self->f8 &= 0xFFFF;
    __construct_array(self->arr, (void (*)(void*))fn_27_CD5E0, (void (*)(void*))fn_27_46700, 0x60, 0xf);
    t28 = self->v28();
    t27 = self->v27();
    t13 = self->v13();
    t14 = self->v14();
    n = self->v4();
    int cnt = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(&self->p4, arg1, n, t14, t13, t27, t28, extra);
    for (int i = 0; i < cnt; i++) {
        self->v10(arg2);
    }
    return self;
}
