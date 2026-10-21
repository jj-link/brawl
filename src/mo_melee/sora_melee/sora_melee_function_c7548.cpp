#include <types.h>
#pragma force_active on

class soTimerObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 vf6();
    virtual void vf7();
    virtual void vf8();

    soTimerObj* m_04;
    s32 m_08;
    s32 m_0c;
};

extern "C" void fn_27_C7548(soTimerObj* self) {
    if (self->vf6() == 0) {
        if (self->m_0c > 0) {
            self->m_0c--;
            if (self->m_0c <= 0) {
                self->m_08 = 0;
            } else {
                self->m_08 += 0x10;
            }
        } else if (self->m_04 != 0) {
            self->m_04->vf8();
        }
    }
}
