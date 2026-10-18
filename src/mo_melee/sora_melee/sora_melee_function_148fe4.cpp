#pragma force_active on
typedef int s32;
typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Obj {
    u8 pad[0xb0];
    s32 m_b0;
};

struct Entry {
    Obj* m_0;
    s32 m_4;
    s32 m_8;
};

struct PubAddr {
    u8 pad[0x14];
    s32 m_14;
};

class utArchiveManager {
public:
    PubAddr* getPublicAddress(u32 id, const char* name, u16 a, u32 b, u32 c);
};

class soArchiveDb {
public:
    static utArchiveManager* getManager(u32 idx);
};

extern "C" u32 fn_27_1222C8(void* mgr, u32 id);

extern Entry lbl_27_bss_3210[];
extern char lbl_27_data_2BBD8[];
extern void* g_ftSlotManager;

extern "C" {
s32 fn_27_148FE4(s32 p0, s32 p1) {
    s32 r;
    if (p1 == 5) {
        u32 id = fn_27_1222C8(g_ftSlotManager, 0xc);
        utArchiveManager* mgr = soArchiveDb::getManager(0);
        r = mgr->getPublicAddress(id, lbl_27_data_2BBD8, 0, 0, -1)->m_14;
    } else {
        r = lbl_27_bss_3210[p1].m_0->m_b0;
    }
    return r;
}
}
