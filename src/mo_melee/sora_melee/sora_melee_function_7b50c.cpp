#include <types.h>
#pragma force_active on

struct UnkFlagHolder {
    u8 pad[0x10];
    u32 m_flags0;
    u32 m_flags1;
};

extern "C" {
bool fn_27_7B50C(const UnkFlagHolder* self, s32 id, bool* out) {
    if (id <= -1 || id >= 0x11) {
        return false;
    }
    u32 mask = 1u << id;
    if (self->m_flags0 & mask) {
        *out = (self->m_flags1 & mask) != 0;
        return true;
    }
    return false;
}
}
