#include <types.h>
#pragma force_active on

typedef struct {
    s32 field0, field4;
    u32 field8;
    s32 fieldC, field10;
} TableEntry;
extern TableEntry lbl_804169B0[];

extern s32 fn_803B5650(void *, s32 *, u32);
extern s32 fn_803B5CEC(void *, s32, u32, s32 *, u32 *, s32 *);

s32 fn_803B8160(u8 *arg0, u32 arg1, u32 arg2, u32 *arg3, u32 *arg4)
{
    s32 sp10;
    u32 spC;
    s32 sp8;
    u8 *cache;
    u8 *inner;
    u32 first;
    u32 previous;
    u32 index;
    u32 count;
    u32 i;
    u32 size;
    s32 result;

    *arg3 = 0;
    *arg4 = 0;
    previous = arg1;
    if (arg0 == 0) {
        return 0xA;
    }
    cache = *(u8 **)(arg0 + 0x30);
    if (cache == 0) {
        return 0xA;
    }
    first = *(u32 *)arg0;
    if (first == 0) {
        return 0xA;
    }
    if (*(u32 *)(cache + 8) > first) {
        return 0xA;
    }
    inner = *(u8 **)(arg0 + 0x34);
    if ((s8)inner[0x187A] < 0x41 || (s8)inner[0x187A] > 0x5A) {
        return 0x23;
    }
    if (inner == 0) {
        return 0xA;
    }
    first = **(u32 **)(arg0 + 8);
    if (first < 2) {
        return 0;
    }
    if (arg1 < 2) {
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    if ((u32)(arg2 + 0x10000) == 0xFFFF) {
        if (*(u32 *)(arg0 + 0xC) != 0) {
            *arg3 = *(u32 *)(arg0 + 0xC);
            *arg4 = lbl_804169B0[*(s32 *)(inner + 0x1C)].field8;
            return 0;
        }
    }
    size = *(u16 *)inner << inner[0x21];
    count = arg2 / size;
    if (arg2 % size != 0) {
        count++;
    }
    if (first == arg1) {
        index = 1;
    } else {
        index = *(u32 *)cache + 1;
    }
    sp10 = -1;
    spC = 1;
    result = fn_803B5650(inner, &sp8, arg1);
    if (result != 0) {
        return result;
    }
    for (i = 0; i < count; i++) {
        result = fn_803B5CEC(arg0, arg1, index, &sp10, &spC, &sp8);
        if (result != 0) {
            return result;
        }
        previous = arg1;
        if ((u32)sp10 == lbl_804169B0[*(s32 *)(inner + 0x1C)].field8) {
            *(u32 *)(arg0 + 0xC) = arg1;
            *(u32 *)(arg0 + 0x10) = index - 1;
            break;
        }
        arg1 = sp10;
        index++;
    }
    **(u32 **)(arg0 + 0x30) = index - 1;
    *arg3 = previous;
    *arg4 = sp10;
    return 0;
}
