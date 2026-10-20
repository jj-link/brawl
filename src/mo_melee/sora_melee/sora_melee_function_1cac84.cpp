#include <types.h>
#pragma force_active on

struct fnResult {
    u32 m_unk0;
    u32 m_value;
};

class fnInterface {
public:
    virtual void fn0();
    virtual fnResult* fn1();
};

struct fnOwner {
    u32 m_pad[4];
    fnInterface m_interface;
};

extern "C" {
u32 fn_27_1CAC84(fnOwner* owner) {
    return owner->m_interface.fn1()->m_value;
}
}
