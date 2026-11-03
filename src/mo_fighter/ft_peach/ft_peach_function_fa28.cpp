#include <types.h>
#pragma force_active on

class Obj;

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, void*, int, int, int, int, int);

class Obj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int size();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void vA();
    virtual void vB();
    virtual void vC();
    virtual void vD();
    virtual void vE();
    virtual int v3C();
    virtual int v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual f32* get(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    int calc;
};

extern "C" void fn_103_FA28(Obj* self, void* iface, f32* src) {
    int index = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, iface, self->v40(), self->size(), self->v3C(), self->v74(), self->v78());
    f32* elem = self->get(index);
    *elem = *src;
    self->v7C(self->size() + 1);
}