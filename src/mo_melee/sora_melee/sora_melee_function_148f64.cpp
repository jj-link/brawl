#include <types.h>
#pragma force_active on

struct Entry {
    void* m_0;
    u32 m_4;
    u32 m_8;
};

extern Entry lbl_27_bss_3210[];
extern char lbl_27_data_2BBD8[];
extern void* g_ftSlotManager;

class utArchiveManager {
public:
    void* getPublicAddress(u32, const char*, u16, u32, u32);
};

class soArchiveDb {
public:
    static utArchiveManager* getManager(u32);
};

extern "C" void* fn_27_1222C8(void*, u32);

extern "C" u32 fn_27_148F64(u32 p1, s32 p2) {
    if (p2 == 5) {
        void* p = fn_27_1222C8(g_ftSlotManager, 0xc);
        utArchiveManager* mgr = soArchiveDb::getManager(0);
        u32* addr = (u32*)mgr->getPublicAddress(reinterpret_cast<u32>(p), lbl_27_data_2BBD8, 0, 0, -1);
        return addr[4];
    }
    u32* e = (u32*)lbl_27_bss_3210[p2].m_0;
    return e[0x2b];
}
