#pragma force_active on

extern "C" {
extern char lbl_27_data_39050[];
void __construct_array(void*, void* (*)(void*), void* (*)(void*, short), int, int);
void* __ct__18soCollisionHitPartFv(void*);
void* __dt__18soCollisionHitPartFv(void*, short);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
    void*, void*, int, int, int, int, int);
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
    char arr[0x340];
};

extern "C" Obj* fn_27_19BA54(Obj* self, void* arg1, int arg2) {
    *(void**)self = lbl_27_data_39050;
    self->p4 = lbl_27_data_39050 + 0x48;
    self->f8 &= 0xFFFF;

    __construct_array(self->arr, __ct__18soCollisionHitPartFv,
                      __dt__18soCollisionHitPartFv, 0x68, 8);

    int t31;
    int t30;
    int t29;
    int t28;
    t28 = self->v28();
    t29 = self->v27();
    t30 = self->v13();
    t31 = self->v14();
    int n = self->v4();

    int cnt = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
        &self->p4, arg1, n, t31, t30, t29, t28);

    for (int i = 0; i < cnt; i++) {
        self->v10(arg2);
    }

    return self;
}
