#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_4610;

class soSubObj {
public:
    virtual void vf0() {}
    virtual void vf1() {}
    virtual void vf2() {}
    virtual void vf3() {}
    virtual void vf4() {}
    virtual void vf5() {}
    virtual void vf6() {}
    virtual void vf7() {}
    virtual void vf8() {}
    virtual void vf9() {}
    virtual void vf10() {}
    virtual void vf11() {}
    virtual float getValue(u32 id);
};

class soOwner {
public:
    u8 m_pad[0x2aac];
    soSubObj m_sub;
};

extern "C" {
bool fn_27_28E91C(soOwner* owner) {
    return owner->m_sub.getValue(0x1100000d) >= lbl_27_rodata_4610;
}
}
