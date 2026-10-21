#include <types.h>
#pragma force_active on

class soArrayVectorCalcInterface {
};

namespace soArrayVectorCalculator {
void pop(soArrayVectorCalcInterface& interface, bool isEmpty, s32 capacity, s32 lastIndex);
}

class Obj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual s32 size() = 0;
    virtual bool isEmpty() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual s32 capacity() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual s32 getLastIndex() = 0;
    virtual void setSize(s32) = 0;
};

extern "C" void fn_50_7454(Obj* self) {
    soArrayVectorCalculator::pop(*(soArrayVectorCalcInterface*)((char*)self + 4), self->isEmpty(), self->capacity(), self->getLastIndex());
    self->setSize(self->size() - 1);
}
