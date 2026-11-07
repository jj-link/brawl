#include <types.h>
#include <it/it_manager.h>
#pragma force_active on

class soArchiveDb {
public:
    static void* getManager(u32 index);
};

extern "C" int fn_80045DC0(void* manager, u32 id, u32 flag);
extern "C" int fn_80046958(void* manager, u32 id);

struct FnSelf {
    u8 m_0[0x10];
    u32 m_10;
    u32 m_14;
    u32 m_18;
};

extern "C" int fn_27_2B24C4(FnSelf* __restrict self) {
    if (fn_80045DC0(soArchiveDb::getManager(2), self->m_18, 0) == 0) {
        return 0;
    }
    if (self->m_14 != 0xffff) {
        if (fn_80045DC0(soArchiveDb::getManager(2), self->m_14, 0) == 0) {
            return 0;
        }
    }
    if (fn_80045DC0(soArchiveDb::getManager(2), self->m_10, 0) == 0) {
        return 0;
    }
    if (self->m_14 != 0xffff) {
        if (fn_80046958(soArchiveDb::getManager(2), self->m_14) != 0) {
            return 0;
        }
    }
    if (((u8*)itManager::getInstance())[0x6d4] == 0) {
        return 0;
    }
    return 1;
}
