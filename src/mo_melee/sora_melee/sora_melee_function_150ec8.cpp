#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual float v30();
};

class Outer {
public:
    u8 m_pad000[0x14c];
    Inner* m_inner;
    u8 m_pad150[0x160 - 0x150];
    s32 m_flag;
};

extern "C" float fn_27_150EC8(Outer* self) {
    if (self->m_flag == 0) {
        return self->m_inner->v30();
    }
    return -self->m_inner->v30();
}
