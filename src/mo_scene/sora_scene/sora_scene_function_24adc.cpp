#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__14gfSceneManagerFv();
void fn_8004D010(void* game);
extern void* g_GameGlobal;
extern void* g_gfApplication;
extern void* lbl_1_bss_1994;

struct Flags { unsigned char flag : 3; unsigned char pad : 5; };

void fn_1_24ADC(s32* self) {
    s32* p = self;
    p[8] = *(s32*)((char*)getInstance__14gfSceneManagerFv() + 0x31c);
    if (lbl_1_bss_1994 == NULL)
        lbl_1_bss_1994 = getInstance__14gfSceneManagerFv();
    if (p[8] == 0xFF) {
        p[2] = 0x18;
        p[4] = 0;
        p[8] = 0;
    } else {
        p[2] = 0;
        p[4] = 0;
        u32 v = *(u8*)((char*)g_gfApplication + 0x110);
        *(s8*)((char*)p + 0x2F) = (s8)(((-v) | v) >> 31);
        fn_8004D010(g_GameGlobal);
        Flags* q = (Flags*)((char*)*(void**)((char*)g_GameGlobal + 0x10) + 0x2E);
        q->flag = 1;
    }
}
}
