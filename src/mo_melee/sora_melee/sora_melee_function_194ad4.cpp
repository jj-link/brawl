#include <types.h>
#pragma force_active on

extern "C" float fn_27_194828(u32 p, u32 a, u32 b, u32 c);
extern "C" extern const float lbl_27_rodata_26C0;
extern void* g_ftManager;

extern "C" float fn_27_194AD4(u32 p) {
    float f = lbl_27_rodata_26C0;
    if (((u8*)g_ftManager)[0x68] == 1) {
        f *= fn_27_194828(p, 0xD28, 0xD2A, 0xD29);
    }
    return f;
}
