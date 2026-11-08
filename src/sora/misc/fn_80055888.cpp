#include <types.h>
#pragma force_active on
extern "C" void* fn_8004E5C4(void*);
extern "C" void* g_GameGlobal;

inline u32 findEntry(s32 a, s32 b, s32 i) {
    for (s32 j = b; j < 3; j++) {
        u32* p = (u32*)((u8*)fn_8004E5C4(g_GameGlobal) + 0x32c + (a - 1) * 0x264 + j * 0xcc + i * 4);
        if (*p >> 30) return 1;
    }
    return 0;
}

extern "C" s32 fn_80055888(s32 a, s32 b) {
    s32 count = 0;
    for (s32 i = 0; i < 0x33; i++) {
        if (findEntry(a, b, i) == 1) count++;
    }
    return count;
}