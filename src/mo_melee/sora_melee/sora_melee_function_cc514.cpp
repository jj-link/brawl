#pragma force_active on
extern "C" void __construct_array(void*, void* (*)(void*), void* (*)(void*, short), unsigned long, int);
extern "C" void* __ct__18soCollisionHitPartFv(void*);
extern "C" void* __dt__18soCollisionHitPartFv(void*, short);
extern int lbl_27_data_1E418[];

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int f18();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void f30(void*);
    virtual void v11();
    virtual void v12();
    virtual int f3c();
    virtual int f40();
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
    virtual int f74();
    virtual int f78();
};
struct Obj : Base {
    void* p4;
    unsigned int f8;
};

extern "C" int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, void*, int, int, int, int, int);

extern "C" Obj* fn_27_CC514(Obj* self, void* a, void* b) {
    *(void**)self = lbl_27_data_1E418;
    self->p4 = (char*)lbl_27_data_1E418 + 0x48;
    self->f8 &= 0x3FFFFF;
    __construct_array((char*)self + 0xc, __ct__18soCollisionHitPartFv, __dt__18soCollisionHitPartFv, 0x68, 2);
    int n = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll((char*)self + 4, a, self->f18(), self->f40(), self->f3c(), self->f74(), self->f78());
    for (int i = 0; i < n; i++) self->f30(b);
    return self;
}
