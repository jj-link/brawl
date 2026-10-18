#include <types.h>
#pragma force_active on

struct SoraEntry {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;
};

extern SoraEntry lbl_1_data_4FE8[];
extern SoraEntry lbl_1_bss_1738;

extern "C" void fn_1_1A5A0(void* unused, u8* src) {
    s32 t = (src[8] >> 2) & 0x3F;
    SoraEntry* p;
    if (t >= 0 && t <= 34) {
        p = &lbl_1_data_4FE8[t];
    } else {
        p = nullptr;
    }
    if (p != nullptr) {
        lbl_1_bss_1738 = *p;
    } else {
        lbl_1_bss_1738 = lbl_1_data_4FE8[0];
    }
}
