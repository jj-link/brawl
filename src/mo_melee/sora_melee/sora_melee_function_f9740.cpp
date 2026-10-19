#include <types.h>
#pragma force_active on

class fn_27_F9740Sub {
public:
    virtual void vf0();
    virtual u32* vf1();
    virtual void vf2();
    virtual void vf3();
};

struct fn_27_F9740Owner {
    u32 m_pad[4];
    fn_27_F9740Sub m_sub;
};

extern "C" u32 fn_27_F9740(fn_27_F9740Owner* self) {
    return self->m_sub.vf1()[1];
}
