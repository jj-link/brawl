#include <types.h>
#pragma force_active on

extern "C" s32 fn_8005680C(void);

struct FlagData {
    u8 padding[0xD58];
    u16 flags[1];
};

struct GameGlobal {
    u8 padding[0x24];
    FlagData* data;
};

extern GameGlobal* g_GameGlobal;

extern "C" void fn_80052C24(void* unused, u32 flag) {
    s32 idx = fn_8005680C();
    u16* arr = g_GameGlobal->data->flags;
    u16 v = arr[idx];

    if (flag == 1) {
        v = v | 0x4000;
    } else {
        v = v & ~0x4000;
    }

    ((s16*)arr)[idx] = v;
}
