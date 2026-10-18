#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Entry {
    u32 m_0;
    u32* m_4;
    u32 m_8;
};

struct utArchiveManager {
    u32* getPublicAddress(unsigned long, const char*, u16, unsigned long, unsigned long);
};

class soArchiveDb {
public:
    static utArchiveManager* getManager(unsigned long);
};

extern "C" {
extern void* g_ftSlotManager;
u32 fn_27_1222C8(void*, s32);
extern char lbl_27_data_2BBD8[];
extern Entry lbl_27_bss_3210[];
}

extern "C" u32 fn_27_1491DC(u32 unused, s32 p2)
{
    if (p2 == 5) {
        u32 slot = fn_27_1222C8(g_ftSlotManager, 0xf);
        utArchiveManager* mgr = soArchiveDb::getManager(0);
        u32* addr = mgr->getPublicAddress(slot, lbl_27_data_2BBD8, 0, 0, -1);
        return addr[4];
    }
    return *(u32*)((u8*)lbl_27_bss_3210[p2].m_0 + 0xb0);
}
