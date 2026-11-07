#pragma force_active on

struct Vec2 {
    float x;
    float y;
};

class soArrayVectorCalcInterface;

struct Container {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int size();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual int v3c();
    virtual bool v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual Vec2* get(int);
    virtual int v74();
    virtual int v78();
    virtual void v7c(int);
    int calc;
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, void*, bool, int, int, int, int);

extern "C" void fn_113_BC00(Vec2* dst, const Vec2* src);

extern "C" void fn_113_12138(Container* self, soArrayVectorCalcInterface* iface, const Vec2* src) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, iface, self->v40(), self->size(), self->v3c(), self->v74(), self->v78());
    fn_113_BC00(self->get(pos), src);
    self->v7c(self->size() + 1);
}