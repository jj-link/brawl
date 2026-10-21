#include <types.h>
#pragma force_active on

extern "C" {
struct GameGlobal;
struct Entry {
    s16 id;
};
struct Record {
    char pad[0xF0];
    s32 value;
};

extern GameGlobal* g_GameGlobal;
Record* fn_8004D138(GameGlobal*, s32);

s32 fn_10_1CCE8(const void* a, const void* b) {
    s32 x = ((const Entry*)a)->id;
    s32 y = ((const Entry*)b)->id;
    GameGlobal* gg = g_GameGlobal;
    Record* pa = fn_8004D138(gg, x);
    Record* pb = fn_8004D138(gg, y);
    s32 result = x - y;
    s32 difference = pb->value - pa->value;
    if (difference != 0) {
        result = difference;
    }
    return result;
}
}
