#pragma force_active on
typedef signed int s32;

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
    virtual void* v4();
    virtual void v5();
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
    virtual s32 v27();
    virtual void v28();
    virtual void v29(s32 n);
};

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, void* b, s32 c, s32 d);

extern "C" void fn_48_66D4(Obj* self) {
    s32 b;
    s32 a;
    a = self->v27();
    b = self->v13();
    void* c = self->v4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, c, b, a);
    s32 n = self->v3();
    self->v29(n - 1);
}
