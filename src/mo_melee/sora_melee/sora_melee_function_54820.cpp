#pragma force_active on

#include <types.h>
#include <so/so_array_vector_calculator.h>

struct Item {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
};

class Obj {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual s32 size();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual s32 v3C();
    virtual bool v40();
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
    virtual Item* get(s32);
    virtual s32 v74();
    virtual s32 v78();
    virtual void v7C(s32);

    s32 calc;
};

extern "C" void fn_27_54820(Obj* self, s32 index, const Item* src) {
    s32 pos = soArrayVectorCalculator::insert(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc), index, self->v40(), self->size(),
        self->v3C(), self->v74(), self->v78());
    *self->get(pos) = *src;
    self->v7C(self->size() + 1);
}
