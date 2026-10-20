#include <types.h>
#pragma force_active on

class soKineticEnergy;

template <class T, u32 C>
class soInstanceManagerFullPropertyVector;

class soIMFPVPrimBase {
public:
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual void v9() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual u32 capacity() = 0;
    u32 m_a;
    u32 m_b;
    u32 m_c;
};

class soIMFPVSecBase {
public:
    virtual void s0() {}
    virtual void s1() {}
    virtual void s2() {}
    virtual void s3() {}
    virtual void s4() {}
    virtual void s5() {}
    virtual void s6() {}
    virtual void s7() {}
    virtual void s8() {}
    virtual void s9() {}
    virtual void s10() {}
    virtual void s11() {}
    virtual void s12() {}
    virtual u32 capacity() = 0;
};

template <>
class soInstanceManagerFullPropertyVector<soKineticEnergy*, 4> : public soIMFPVPrimBase, public soIMFPVSecBase {
public:
    virtual void keyFunc();
    virtual u32 capacity();
};

u32 soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::capacity() {
    soIMFPVSecBase& r = static_cast<soIMFPVSecBase&>(*this);
    return r.capacity();
}
