#pragma force_active on
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void* __ct__21soCollisionAttackPartFv(void*);
extern "C" void* __dt__21soCollisionAttackPartFv(void*, short);
extern "C" int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, void*, int, int, int, int, int);
extern char lbl_27_data_3B5B0[];

struct O {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int  v4();    // 0x18
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int); // 0x30
    virtual void v11();
    virtual void v12();
    virtual int  v13();   // 0x3C
    virtual int  v14();   // 0x40
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
    virtual int  v27();   // 0x74
    virtual int  v28();   // 0x78
    void* p4;
    unsigned int f8;
    char arr[0x120];
};

extern "C" void* fn_27_19CB88(O* self, void* a, int arg2) {
    *(void**)self = lbl_27_data_3B5B0;
    self->p4 = lbl_27_data_3B5B0 + 0x48;
    self->f8 &= 0x3FFFFF;
    __construct_array(self->arr, (void (*)(void*))__ct__21soCollisionAttackPartFv, (void (*)(void*))__dt__21soCollisionAttackPartFv, 0x90, 2);
    int n = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(&self->p4, a, self->v4(), self->v14(), self->v13(), self->v27(), self->v28());
    for (int i = 0; i < n; i++) self->v10(arg2);
    return self;
}
