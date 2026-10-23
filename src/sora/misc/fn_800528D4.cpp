#include <types.h>
#pragma force_active on

extern "C" u32 fn_80056780(void);

struct FlagData {
    u8 padding[0x842];
    u16 flags[1];
};

struct GameGlobal {
    u8 padding[0x24];
    FlagData* data;
};

extern GameGlobal* g_GameGlobal;

extern "C" void fn_800528D4(void* /* unused */, u32 flag) {
    s32 idx = fn_80056780();
    u16* arr = g_GameGlobal->data->flags;
    u16 v = arr[idx];

    if (flag == 1) {
        v = v | 0x2000;
    } else {
        v = v & ~0x2000;
    }

    ((s16*)arr)[idx] = v;
}
