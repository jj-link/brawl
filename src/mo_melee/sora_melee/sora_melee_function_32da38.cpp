#include <types.h>
#pragma force_active on

struct fn_27_32DA38_Data {
    u8 pad0[0x18];
    s32 m_18;
    u8 pad1[0x50 - 0x1C];
    void* m_50[1];
};

extern "C" {
void* fn_27_32DA38(fn_27_32DA38_Data* p, s32 unused, s32 idx) {
    return p->m_50[idx - p->m_18];
}
}
