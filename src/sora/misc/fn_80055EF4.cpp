#pragma force_active on
#include <types.h>
#include <gm/gm_global.h>

struct ItemFlags { int unk0, unk4, unk8, unkC; };

extern "C" {
extern ItemFlags lbl_8042C958[];
extern ItemFlags lbl_8042CC88[];
extern ItemFlags lbl_804977E0;
extern u32 fn_8004F3BC(u8);

ItemFlags* fn_80055EF4(int arg0, int arg1) {
    if (arg1 == 1) {
        int* src = (int*)&lbl_8042C958[arg0];
        int* dst = (int*)&lbl_804977E0;
        *dst++ = *src++;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    if (arg1 == 2) {
        int* src = (int*)&lbl_8042CC88[arg0];
        int* dst = (int*)&lbl_804977E0;
        *dst++ = *src++;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    ItemFlags* p = &lbl_804977E0;
    if (*(u8*)((char*)g_GameGlobal->m_modeMelee + 0x13) != 1)
        p->unk0 &= 0xFFFFBFFF;
    if (fn_8004F3BC(0) == 0) p->unkC &= 0xFFFFFFF7;
    if (fn_8004F3BC(1) == 0) p->unkC &= 0xFFF7FFFF;
    if (fn_8004F3BC(2) == 0) p->unkC &= 0xFF7FFFFF;
    if (fn_8004F3BC(3) == 0) p->unkC &= 0xFFFFFFFD;
    if (fn_8004F3BC(4) == 0) p->unkC &= 0xFFFFFFFB;
    if (fn_8004F3BC(5) == 0) p->unkC &= 0xFFDFFFFF;
    return p;
}
}
