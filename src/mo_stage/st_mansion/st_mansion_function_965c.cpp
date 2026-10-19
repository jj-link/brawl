#pragma force_active on
typedef unsigned int u32;

class soArrayVectorCalcInterface {
public:
    u32 m_dummy;
};

class soArrayVectorCalculator {
public:
    static void clear(soArrayVectorCalcInterface& iface);
};

class fn_47_Base {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
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
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31(int arg);
};

class fn_47_Obj : public fn_47_Base {
public:
    soArrayVectorCalcInterface m_calc;
};

extern "C" {
void fn_47_965C(fn_47_Obj* self) {
    soArrayVectorCalculator::clear(self->m_calc);
    self->v31(0);
}
}
