#include <types.h>
#pragma force_active on

class fn_27_Vt {
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
    virtual void vf9();
    virtual void vf10();
    virtual void vf11(u32 id);
};

struct fn_27_Mid {
    u8 pad[0x40];
    fn_27_Vt* m_obj;
};

struct fn_27_Owner {
    u8 pad[0xd8];
    fn_27_Mid* m_mid;
};

extern "C" {
void fn_27_191F84(void* unused, fn_27_Owner* owner) {
    owner->m_mid->m_obj->vf11(0x109);
}
}
