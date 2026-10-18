#include <types.h>
#pragma force_active on

class gfSlowManager {
public:
    static u8 getSlowRate(const u8& rate);
};

struct fn_27_5C2FC_Target {
    u8 pad[0x2c];
    u8 m_slowRate;
};

extern "C" {
u32 fn_27_5C2FC(const fn_27_5C2FC_Target* self) {
    if (self->m_slowRate != 0xFF) {
        u8 rate = self->m_slowRate;
        return (u8)gfSlowManager::getSlowRate(rate);
    } else {
        return 1;
    }
}
}
