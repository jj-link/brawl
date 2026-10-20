#include <types.h>
#pragma force_active on

struct FnObj27 {
    u8 pad[0x14];
    s32 m_value;
};

extern "C" {
bool fn_27_A7B74(const FnObj27* obj, u32 id) {
    s32 v = obj->m_value;
    if (v < 0) {
        return false;
    }
    return (id - v) == 0;
}
}
