#include <types.h>
#pragma force_active on

extern "C" {
u32 exchangeGmCharacterKindToMuCharKind__6muMenuFiii(s32 a);
void* fn_8004E5D8(void* g, s32 kind);
void fn_800548D0(void* a, s32 b, void* p);
extern void* g_GameGlobal;
}

extern "C" void fn_80055058(u8* a) {
    u8* e;
    s32 off;
    u8* f;
    u8* q;
    u8* base = a + 0x24;
    s32 oi;
    s32 ii;
    u8* g;
    e = base;
    for (oi = 0, off = 0; oi < 4; oi++) {
        if (e[1] == 0) {
            u8 kind = (u8)exchangeGmCharacterKindToMuCharKind__6muMenuFiii(e[0]);
            g = (u8*)fn_8004E5D8(g_GameGlobal, kind);
            f = base;
            q = e;
            for (ii = 0; ii < 4; ii++) {
                if (oi != ii && f[1] != 3) {
                    if (!(e[1] == 1 && f[1] == 1)) {
                        if (!(a[2] == 1 && e[6] == f[6])) {
                            u16 r21 = *(u16*)(q + 0x1a);
                            u8 t2 = (u8)exchangeGmCharacterKindToMuCharKind__6muMenuFiii(f[0]);
                            u16* slot = (u16*)g + t2;
                            bool overflow;
                            s32 v = *slot;
                            overflow = true;
                            if (v <= 0xFFFF - r21) overflow = false;
                            *slot = overflow ? 0xFFFF : (u16)(v + r21);
                        }
                        u16 w = *(u16*)((u32)off + (u32)f + 0x1a);
                        bool overflow;
                        s32 cur = *(u16*)(g + 0x46);
                        overflow = true;
                        if (cur <= 0xFFFF - w) overflow = false;
                        *(u16*)(g + 0x46) = overflow ? 0xFFFF : (u16)(cur + w);
                    }
                }
                f += 0x2ac;
                q += 2;
            }
            fn_800548D0(a, oi, g + 0x48);
        }
        e += 0x2ac;
        off += 2;
    }
}
