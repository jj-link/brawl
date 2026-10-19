#include <types.h>
#pragma force_active on

struct fn27FtEntryMgr {
    u8* m_base;
};

extern fn27FtEntryMgr* g_ftEntryManager;

struct fn27Obj {
    u8 pad_0[0x50];
    s32 m_50;
    u8 pad_54[0x4];
    void* m_58;
};

struct fn27Entry {
    u8 pad_0[0x58];
    void* m_58;
};

extern "C" void* fn_27_116FC4(fn27Obj* p1, u32 p2) {
    if (p2 == 1 && p1->m_50 != -1) {
        u8* base = g_ftEntryManager->m_base;
        u8 idx = (u8)p1->m_50;
        fn27Entry* e = (fn27Entry*)(base + idx * 0x244);
        return e->m_58;
    }
    return p1->m_58;
}
