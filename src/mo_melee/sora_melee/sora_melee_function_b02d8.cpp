#include <types.h>
#pragma force_active on

class soIface {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc10(s16 value);
};

class soOuter {
public:
    u32 m_unk0;
    u32 m_unk4;
    soIface* m_iface;
};

extern "C" {
void fn_27_B02D8(soOuter* outer, s16 value) {
    outer->m_iface->vfunc10(value);
}
}
