#pragma force_active on
#include <types.h>
#include <revolution/OS/OSError.h>
#include <st/loader/st_loader_manager.h>

extern "C" char lbl_1_data_128[];

extern "C" s32 fn_1_3134(s32 arg0, u32 arg1, u32 arg2) {
    const char* base = lbl_1_data_128;
    stLoaderManager* mgr = g_stLoaderManager;
    stLoaderPlayer* p;
    s32 slotId;
    p = mgr->m_loaderPlayers[arg0];
    slotId = p->m_slotId;
    if (slotId == -1) {
        return -1;
    }
    if (arg1 == ((u8*)p)[0x5a] && arg2 == ((u8*)p)[0x5b] && arg0 == slotId) {
        OSReport(base + 0x104);
        return arg0;
    }
    for (s32 i = 0; i < 4; i++) {
        p = mgr->m_loaderPlayers[i];
        if (p->m_slotId != -1 && arg1 == ((u8*)p)[0x5a] && arg2 == ((u8*)p)[0x5b]) {
            OSReport(base + 0x114);
            return i;
        }
    }
    stLoaderPlayer** pp = mgr->m_loaderPlayers;
    for (s32 i = 0; i < 4; i++) {
        stLoaderPlayer* q = *pp;
        s32 sid = q->m_slotId;
        if (sid != -1 && arg1 == ((u8*)q)[0x5a]) {
            OSReport(base + 0x128);
            return i;
        }
        pp++;
    }
    return -1;
}