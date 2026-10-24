#pragma force_active on

extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void* __ct__18soCollisionHitPartFv(void*);
extern "C" void __dt__18soCollisionHitPartFv(void*, short);
extern "C" int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, int, int, int, int, int, int);
extern char lbl_27_data_1E510[];

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
};

extern "C" void* fn_27_CC298(void* arg0, int arg1, int arg2) {
    char* p = (char*)arg0;
    unsigned flags = ((unsigned*)arg0)[2];
    *(void**)p = lbl_27_data_1E510;
    *(void**)(p + 4) = lbl_27_data_1E510 + 0x48;
    *(unsigned*)(p + 8) = flags & 0xFFFF;

    __construct_array(
        p + 0xC,
        (void (*)(void*))__ct__18soCollisionHitPartFv,
        (void (*)(void*))__dt__18soCollisionHitPartFv,
        0x68,
        10
    );

    Obj* self = (Obj*)arg0;
    int a, b, c, d;
    d = self->v28();
    c = self->v27();
    b = self->v13();
    a = self->v14();
    int e = self->v4();

    int n = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
        p + 4, arg1, e, a, b, c, d
    );

    for (int i = 0; i < n; ++i) {
        self->v10(arg2);
    }

    return arg0;
}
