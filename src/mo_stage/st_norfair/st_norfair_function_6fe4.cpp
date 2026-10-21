#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, void*, s32, s32);

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
    virtual void* v4();
    virtual void* v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual s32 v13();
    virtual void v14();
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
    virtual void v27();
    virtual s32 v28();
    virtual void v29(s32 n);
};

extern "C" void fn_54_6FE4(Obj* self) {
    s32 second;
    s32 first;
    first = self->v28();
    second = self->v13();
    void* c = self->v4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)((char*)self + 4), c, second, first);
    s32 n = self->v3();
    self->v29(n - 1);
}
