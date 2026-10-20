#include <types.h>
#pragma force_active on

extern "C" void* getManager__11soArchiveDbFUl(u32 index);
extern "C" int fn_80045DC0(void* mgr, u32 id, u32 flag);

struct SoArchiveRefHolder {
    u8 pad_00[0x10];
    u32 m_10;
    u32 m_14;
    u32 m_18;
    u8 pad_1C[0xC];
    s32 m_28;
};

extern "C" void fn_27_2B2358(SoArchiveRefHolder* self) {
    if (self->m_28 < 0) {
        return;
    }
    void* mgr = getManager__11soArchiveDbFUl(2);
    if (fn_80045DC0(mgr, self->m_18, 0) == 0) {
        return;
    }
    if (self->m_14 != 0xFFFF) {
        mgr = getManager__11soArchiveDbFUl(2);
        if (fn_80045DC0(mgr, self->m_14, 0) == 0) {
            return;
        }
    }
    mgr = getManager__11soArchiveDbFUl(2);
    if (fn_80045DC0(mgr, self->m_10, 0) != 0) {
        self->m_28 = self->m_28 - 1;
    }
}
