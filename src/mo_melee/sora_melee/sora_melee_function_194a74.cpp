#include <types.h>
#pragma force_active on

extern "C" float fn_27_194828(u32 p, u32 a, u32 b, u32 c);
extern "C" extern const float lbl_27_rodata_26C0;
extern void* g_ftManager;

extern "C" float fn_27_194A74(u32 p) {
    float f = lbl_27_rodata_26C0;
    if (((u8*)g_ftManager)[0x68] == 1) {
        f *= fn_27_194828(p, 0xD25, 0xD27, 0xD26);
    }
    return f;
}
