#pragma force_active on
typedef int s32;
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void shift(soArrayVectorCalcInterface& iface, bool b, long l1, long l2);
};

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v5();
    virtual soArrayVectorCalcInterface* v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual bool v15();
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
    virtual s32 v29();
    virtual void v30();
    virtual void v31(s32 n);
};

extern "C" void fn_27_EE9F4(Self* self) {
    s32 z;
    bool b;
    s32 a;
    a = self->v29();
    b = self->v15();
    soArrayVectorCalcInterface* it = self->v6();
    soArrayVectorCalculator* calc = (soArrayVectorCalculator*)((char*)self + 4);
    calc->shift(*it, b, a, z);
    s32 n = self->v5();
    self->v31(n - 1);
}
