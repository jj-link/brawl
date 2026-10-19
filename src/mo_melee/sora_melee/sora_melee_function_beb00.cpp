#include <types.h>
#pragma force_active on

class soGeneralFlagOwner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 m_pad4;
    u8 m_flag5;
};

extern "C" {
int fn_27_BEB00(soGeneralFlagOwner* self) {
    if (((self->m_flag5 >> 7) & 1) == 0) {
        self->vf6();
    }
    return 1;
}
}
