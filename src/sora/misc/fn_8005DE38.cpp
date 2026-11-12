#include <types.h>
#pragma force_active on
inline void shift(s32 i, u8* base) {
    for (; i < 15; ++i) base[i + 1] = base[i + 2];
}
inline void remove(u8* base, s32 value) {
    s32 i = 0;
    u32 count = *base;
    for (; i < count; ++i) {
        if ((s8)base[i + 1] == value) {
            shift(i, base);
            ((s8*)base)[16] = -1;
            --base[0];
            return;
        }
    }
}
extern "C" void fn_8005DE38(u8* base, s32 index, s32 value) {
    base += index * 17;
    remove(base, value);
}