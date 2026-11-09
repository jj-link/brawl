#pragma force_active on

#include <types.h>

struct Node {
    char pad[0xc];
    void* field0c;
};

struct Element;

class Array {
public:
    virtual void v08() = 0;
    virtual void v0C() = 0;
    virtual void v10() = 0;
    virtual s32 size() const = 0;
    virtual void v18() = 0;
    virtual void v1C() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2C() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
    virtual s32 v3C() = 0;
    virtual bool v40() = 0;
    virtual void v44() = 0;
    virtual void v48() = 0;
    virtual void v4C() = 0;
    virtual void v50() = 0;
    virtual void v54() = 0;
    virtual void v58() = 0;
    virtual void v5C() = 0;
    virtual void v60() = 0;
    virtual void v64() = 0;
    virtual void v68() = 0;
    virtual void v6C() = 0;
    virtual Element* v70(s32) = 0;
    virtual s32 v74() = 0;
    virtual s32 v78() = 0;
    virtual void v7C(s32) = 0;

    s32 calc;
};

extern "C" {
void fn_27_AB2E0(Node* dst, const Node* src);
int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

void fn_27_E1F20(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3C(), self->v74(), self->v78());
    Element* dst = self->v70(pos);
    fn_27_AB2E0((Node*)dst, (Node*)value);
    self->v7C(self->size() + 1);
}
}
