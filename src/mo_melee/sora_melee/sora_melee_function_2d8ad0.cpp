#pragma force_active on
#include <snd/snd_system.h>
#include <st/stage.h>

extern "C" {
extern u8* g_GameGlobal;
extern u8* g_IfAdvMngr;
extern Stage* lbl_27_bss_5668;
extern u8 lbl_27_rodata_6338[];
void* fn_800DFC68(void);
void fn_801079C0(void*);
void fn_8010C0C4(void*, void*);
void fn_8010C0DC(void*, void*);
}

inline int map_id(int n) { if (n < 0 || n > 0x2b) return 0x23; return lbl_27_rodata_6338[n]; }

extern "C" void fn_27_2D8AD0(s32 r3, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    u8* p;
    u8* q;
    u8* m;
    u32 var;
    u32 bit;
    s32 idx;
    s32 i;
    s32 j;

    switch (a2) {
    case 0x49:
        p = *(u8**)(g_GameGlobal + 0x30);
        idx = (s8)p[0x5fa];
        if (idx < 0x62) {
            *(s32*)(p + (idx << 3) + 0x2e0) = 1;
            var = 1;
            *(u8*)(p + (((s8)p[0x5fa]) << 3) + 0x2e4) = 0xFF;
            p[0x5fa] = p[0x5fa] + 1;
        } else {
            var = 0;
        }
        if (var == 1) {
            m = g_IfAdvMngr;
            if (m != 0) {
                fn_801079C0(m);
                if (!((*(u8**)(g_GameGlobal + 0x30))[0x606] >> 7 & 1)) {
                    m = g_IfAdvMngr;
                    m[0x48] = m[0x48] | 0x40;
                    if (*(s32*)(m + 0x104) != 0) {
                        bit = ((u32)(m[0x48] >> 6)) & 1;
                        if (bit == 1) {
                            fn_8010C0C4(*(void**)(m + 0x104), fn_800DFC68());
                        } else {
                            fn_8010C0DC(*(void**)(m + 0x104), fn_800DFC68());
                        }
                    }
                }
            }
            p = *(u8**)(g_GameGlobal + 0x30);
            q = *(u8**)(g_GameGlobal + 8);
            if (p[0x2B4] <= p[0x2B5]) {
                p[0x2B5] = 0;
            }
            i = map_id((s8)(p + p[0x2B5])[0x2B9]);
            j = map_id(q[0x98]);
            if (i == j) {
                p[0x2B5] = *(s8*)(p + 0x2B5) + 1;
            }
        }
        g_sndSystem->playSE((SndID)0x2290, -1, 0, 0, -1);
        break;
    }
    if (lbl_27_bss_5668 != 0) {
        lbl_27_bss_5668->stAdventureEventGetItem(a1, (itKind)a2, a3, a4, a5);
    }
}
