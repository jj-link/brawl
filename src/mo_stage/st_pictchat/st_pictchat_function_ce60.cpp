#pragma force_active on
class soArrayVectorCalcInterface {
public:
    char m_pad[4];
};

class soArrayVectorCalculator {
public:
    static void clear(soArrayVectorCalcInterface& calc);
};

class fnOwner {
public:
    virtual void v0(int);
    virtual void v1(int);
    virtual void v2(int);
    virtual void v3(int);
    virtual void v4(int);
    virtual void v5(int);
    virtual void v6(int);
    virtual void v7(int);
    virtual void v8(int);
    virtual void v9(int);
    virtual void v10(int);
    virtual void v11(int);
    virtual void v12(int);
    virtual void v13(int);
    virtual void v14(int);
    virtual void v15(int);
    virtual void v16(int);
    virtual void v17(int);
    virtual void v18(int);
    virtual void v19(int);
    virtual void v20(int);
    virtual void v21(int);
    virtual void v22(int);
    virtual void v23(int);
    virtual void v24(int);
    virtual void v25(int);
    virtual void v26(int);
    virtual void v27(int);
    virtual void v28(int);
    virtual void v29(int);
    virtual void v30(int);
    virtual void v31(int);

    soArrayVectorCalcInterface m_calc;
};

extern "C" void fn_73_CE60(fnOwner* self) {
    soArrayVectorCalculator::clear(self->m_calc);
    self->v29(0);
}
