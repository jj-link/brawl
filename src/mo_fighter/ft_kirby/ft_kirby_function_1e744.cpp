#pragma force_active on

struct Object;
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
    virtual int capacity();
    virtual bool isFull();
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
    virtual Object* get(int);
    virtual int getTopIndex();
    virtual int getLastIndex();
    virtual void setSize(int);
    int calc;
};
extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);
extern "C" Object* fn_96_1F8B8(Object*, const Object*);
extern "C" void fn_96_1E744(Container* self, int index, const Object* src) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, index, self->isFull(), self->size(), self->capacity(),
        self->getTopIndex(), self->getLastIndex());
    fn_96_1F8B8(self->get(pos), src);
    self->setSize(self->size() + 1);
}