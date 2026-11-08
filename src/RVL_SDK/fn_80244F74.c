#include <types.h>
#pragma force_active on
extern void *fn_8022EFF8(s32);
extern void fn_80242908(void *);
s32 fn_80244F74(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *src;
    u8 *ptr;
    u8 *dest;
    s32 count;
    src = arg2;
    ptr = (u8 *)fn_8022EFF8(2);
    if (ptr == NULL) return 0;
    *(s16 *)(ptr + 2) = 0x1A;
    *(s16 *)(ptr + 4) = 0;
    ptr[8] = 0xD;
    ptr[9] = 4;
    ptr[0xA] = 0x17;
    ptr[0xB] = arg0[5];
    ptr[0xC] = arg0[4];
    ptr[0xD] = arg0[3];
    ptr[0xE] = arg0[2];
    ptr[0xF] = arg0[1];
    ptr[0x10] = arg0[0];
    ptr[0x11] = (u8)arg1;
    dest = ptr + 0x12;
    count = 0;
    while (count < arg1) {
        *dest = *src;
        count++;
        src++;
        dest++;
    }
    while (count < 16) {
        *dest++ = 0;
        count++;
    }
    fn_80242908(ptr);
    return 1;
}