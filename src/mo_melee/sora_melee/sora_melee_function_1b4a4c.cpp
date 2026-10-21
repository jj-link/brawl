#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, s32 a, s32 b, s32 c);

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
    virtual s32 v4();
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
    virtual s32 v28();
    virtual void v29(s32 n);
};

extern "C" void fn_27_1B4A4C(Obj* self) {
    s32 r31;
    s32 r30 = self->v28();
    r31 = self->v13();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, self->v4(), r31, r30);
    s32 n = self->v3();
    self->v29(n - 1);
}
