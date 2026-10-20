#include <types.h>
#pragma force_active on

class fn27Target {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 f3();
};

class fn27Owner {
public:
    u8 m_pad[0x4c];
    fn27Target* m_target;
    u8 m_pad50;
    u8 m_flag;
};

extern "C" {
s32 fn_27_49930(fn27Owner* p) {
    if (p->m_flag != 0) {
        return p->m_target->f3();
    }
    return 0;
}
}
