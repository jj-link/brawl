#include <types.h>
#pragma force_active on
class ftManager { public: int getEntryId(int); };
extern "C" void fn_800E4D28(void* p, s32 x);
extern "C" void fn_80075F1C(void*, s32, s32);
extern "C" s32 g_IfMngr;
extern ftManager* g_ftManager;
extern void* g_sndSystem;
extern "C" const float lbl_27_rodata_4144;

struct S {
    u8 pad0[0x44];
    u8* base;
    u8 pad48[0x64 - 0x48];
    u8 a[7];
    u8 b[7];
    u8 c[7];
    u8 pad79[3];
    s32 d[7];
    float e[7];
    u8 g[7];
    u8 padbb[0x114 - 0xBB];
    s32 snd;
};

extern "C" void fn_27_255F98(S* a) {
    for (int i = 0; i < 7; i++) {
        a->a[i] = 0; a->b[i] = 0; a->c[i] = 0;
        a->d[i] = 0;
        a->e[i] = lbl_27_rodata_4144;
        a->g[i] = 0;
    }
    if (g_IfMngr != 0 && g_ftManager != 0) {
        for (s32 i = 0; i < 7; i++) {
            if (g_ftManager->getEntryId(i) != -1) {
                u8 id = (a->base + i * 0x5C)[0x9A];
                s32 e = *(s32*)(g_IfMngr + (*(u8*)(g_IfMngr + id + 0x68) << 2) + 0x4c);
                if (*(u8*)(e + 0x350) != 0) fn_800E4D28((void*)e, 0);
                e = *(s32*)(g_IfMngr + (*(u8*)(g_IfMngr + id + 0x68) << 2) + 0x4c);
                if (*(s32*)(e + 0x2b0) != 0) *(s32*)(e + 0x2b0) = 0;
            }
        }
    }
    if (a->snd >= 0) {
        fn_80075F1C(g_sndSystem, a->snd, 0);
        a->snd = -1;
    }
}
