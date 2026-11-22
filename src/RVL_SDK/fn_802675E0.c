#include <types.h>
#pragma force_active on

void fn_802675E0(void *arg0, s32 arg1, s32 arg2)
{
    s32 tb;
    u8 *obj;
    s32 skip;
    u16 *row;
    s32 col;
    u8 *dst;
    u8 *src;
    s32 x;
    s32 x_end;
    s32 y_end;
    u32 pitch;
    s32 x_count;
    s32 pos;
    s32 c;
    s32 idx;
    s32 b;
    s32 a;

    obj = *(u8 **)((u8 *)arg0 + 0x19D0);
    dst = *(u8 **)(obj + 0x64);
    pitch = (*(u32 *)(obj + 0x48) >> 1) & 0x7FFFFFFE;
    src = (u8 *)arg0 + 0x1848;
    x_count = 8 / *(u8 *)(obj + 0x2C);
    x_end = arg1 + x_count;
    y_end = arg2 + x_count;
    skip = 8 - x_count;

    for (; arg2 < y_end; arg2++) {
        row = (u16 *)(dst + ((arg2 & 3) << 3));
        col = (arg2 >> 2) * pitch;

        for (x = arg1; x < x_end; x++) {
            c = *src++;

            if (c >> 8) {
                a = c > 255 ? 255 : (c < 0 ? 0 : c);
                b = c > 255 ? 255 : (c < 0 ? 0 : c);
                c = c > 255 ? 255 : (c < 0 ? 0 : c);
            } else {
                a = c;
                b = c;
            }

            pos = x & 3;
            tb = (x >> 2) * 2;
            idx = tb + col;
            row[pos + idx * 16] = (u8)c + 0xFF00;
            row[pos + (idx + 1) * 16] =
                ((u8)b << 8) + (u8)a;
        }

        src += skip;
    }
}
