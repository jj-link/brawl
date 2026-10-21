#include <types.h>
#pragma force_active on

class soArchiveDb {
public:
    static void* getManager(u32 index);
};

extern "C" int fn_80045DC0(void* manager, u32 id, u32 flag);

struct FnSelf {
    u8 m_0[0x10];
    u32 m_10;
    u32 m_14;
    u32 m_18;
    u8 m_1c[0xc];
    s32 m_28;
};

extern "C" bool fn_27_2B23F8(FnSelf* __restrict self) {
    s32 state = self->m_28;
    if (state < 0) {
        return true;
    }
    if (state > 0) {
        return false;
    }
    if (fn_80045DC0(soArchiveDb::getManager(2), self->m_18, 0) == 0) {
        return false;
    }
    if (self->m_14 != 0xffff) {
        if (fn_80045DC0(soArchiveDb::getManager(2), self->m_14, 0) == 0) {
            return false;
        }
    }
    if (fn_80045DC0(soArchiveDb::getManager(2), self->m_10, 0) == 0) {
        return false;
    }
    return true;
}
