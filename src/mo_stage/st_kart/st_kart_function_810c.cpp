#pragma force_active on
struct soArrayVectorCalcInterface;
extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(void*, soArrayVectorCalcInterface&, bool, long, long);
struct V2 { float x, y; };
struct S2 { short a, b; };
struct Elem {
    int a; short b; short c; float d; float e; int f; float g; float h;
    int i[5]; char j[5];
};
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual bool v13();
    virtual soArrayVectorCalcInterface& v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual Elem* v26(int);
    virtual long v27();
    virtual long v28();
    virtual void v29(int);
    int calc;
};
extern "C" void fn_49_810C(Obj* o, Elem src) {
    *o->v26(push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(&o->calc, o->v14(), o->v13(), o->v27(), o->v28())) = src;
    o->v29(o->v3() + 1);
}
