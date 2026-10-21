#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, void*, s32, s32);

class Obj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual s32 v5();
    virtual void* v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual s32 v15();
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
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual s32 v30();
    virtual void v31(s32 n);
};

extern "C" void fn_79_9228(Obj* self) {
    s32 b;
    s32 a;
    a = self->v30();
    b = self->v15();
    void* c = self->v6();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)((char*)self + 4), c, b, a);
    self->v31(self->v5() - 1);
}
