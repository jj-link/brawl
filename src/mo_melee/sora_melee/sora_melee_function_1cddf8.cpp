#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void vf0();
    virtual fn27Inner* vf1();
    u32 m_value;
};

extern "C" u32 fn_27_1CDDF8(void* self) {
    fn27Inner* inner = (fn27Inner*)((char*)self + 0x10);
    return inner->vf1()->m_value;
}
