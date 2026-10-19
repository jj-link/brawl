#pragma force_active on
class soArrayVectorCalcInterface {
};

class soArrayVectorCalculator {
public:
    static void clear(soArrayVectorCalcInterface& iface);
};

class soKartArrayOwner {
public:
    virtual void v0();
    virtual void v1();
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
    virtual void v31(int flag);

    soArrayVectorCalcInterface m_iface;
};

extern "C" void fn_49_AD14(soKartArrayOwner* self) {
    soArrayVectorCalculator::clear(self->m_iface);
    self->v31(0);
}
