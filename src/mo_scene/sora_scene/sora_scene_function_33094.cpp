#include <types.h>
#pragma force_active on
extern "C" {
extern signed char lbl_1_data_8000[];
extern signed char lbl_1_data_8034[];
extern u8* lbl_1_bss_1A64[];
extern u8* lbl_1_bss_1B08[];
}
struct Flags { u8 top : 3; u8 rest : 5; };
inline void copySlot(u8* base, u8* e, u8* out, s32 i) {
    if (i < ((base[0x21] >> 5) & 7)) {
        out[8 + i * 2] = base[0x50 + i * 0x38];
        out[9 + i * 2] = e[0x63 + i * 0x38];
    } else {
        out[8 + i * 2] = 0x3e;
        out[9 + i * 2] = 0;
    }
}
extern "C" void fn_1_33094(void* a0, s32 idx, s32 n, s32 type, u8* out) {
    u8* base;
    if (type == 1) base = lbl_1_bss_1A64[lbl_1_data_8000[idx]];
    else base = lbl_1_bss_1B08[lbl_1_data_8034[idx]];
    *(u32*)out = *(u32*)base;
    u8* e = base + n * 14;
    *(u16*)(out + 4) = *(u16*)(base + 0x1E);
    out[6] = base[0x20];
    ((Flags*)(out + 7))->top = ((Flags*)(base + 0x21))->top;
    for (s32 i = 0; i < 4; i++) copySlot(base, e, out, i);
}
