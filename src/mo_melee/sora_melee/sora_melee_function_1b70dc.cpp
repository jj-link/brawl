#pragma force_active on

#include <types.h>
#include <so/so_array_vector_calculator.h>

struct Elem {
    s32 m_a;
    s32 m_b;
    s32 m_c;
    s32 m_d;
    s32 m_e;
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
    virtual Elem* get(s32);
    virtual s32 v74();
    virtual s32 v78();
    virtual void v7C(s32);

    s32 calc;
};

extern "C" void fn_27_1B70DC(Obj* self, s32 index, const Elem* src) {
    s32 pos = soArrayVectorCalculator::insert(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc), index, self->v40(), self->size(),
        self->v3C(), self->v74(), self->v78());
    Elem* dst = self->get(pos);
    s32 d;
    dst->m_a = src->m_a;
    if (&dst->m_b != &src->m_b) {
        if (&dst->m_b != &src->m_b) {
            if (&dst->m_c != &src->m_c)
                dst->m_c = src->m_c;
            d = src->m_d;
            dst->m_d = d;
            dst->m_e = src->m_e;
            if (d == 0)
                dst->m_e = 0;
        }
    }
    self->v7C(self->size() + 1);
}
