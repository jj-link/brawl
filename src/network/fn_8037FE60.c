#include <types.h>
#pragma force_active on

extern s32 fn_8037C1C0(void *, void *, s32);
extern s32 fn_803F524C(void *, s32, s32, void *);

s32 fn_8037FE60(void *arg0, void *arg1)
{
    s16 buf[0x800];
    struct {
        s16 a;
        u8 b;
    } tmp;
    s32 n;
    s32 r;
    s32 rem;

    for (;;) {
        n = fn_803F524C(buf, 1, 0x1000, *(void **)((u8 *)arg0 + 0x8));
        if (n <= 0) {
            *(s32 *)((u8 *)arg1 + 0x120) = 1;
            *(s32 *)((u8 *)arg1 + 0x3C) = 0xE;
            return 0;
        }

        *(s32 *)((u8 *)arg0 + 0x4) = *(s32 *)((u8 *)arg0 + 0x4) + n;
        if (*(s32 *)((u8 *)arg0 + 0x4) > *(s32 *)((u8 *)arg0 + 0xC)) {
            *(s32 *)((u8 *)arg1 + 0x120) = 1;
            *(s32 *)((u8 *)arg1 + 0x3C) = 0xE;
            return 0;
        }

        r = fn_8037C1C0(arg1, buf, n);
        if (r == 0) {
            return 0;
        }

        if (*(s32 *)((u8 *)arg0 + 0x4) == *(s32 *)((u8 *)arg0 + 0xC)) {
            if (*(s32 *)(*(u8 **)((u8 *)arg1 + 0x160) + 0x14) != 0) {
                tmp.a = 0;
                tmp.b = 0;
                rem = 4 - (*(s32 *)((u8 *)arg0 + 0xC) % 4);
                if (rem != 4 && rem > 0) {
                    if (fn_8037C1C0(arg1, &tmp, rem) == 0) {
                        return 0;
                    }
                }
            }
            return 1;
        }

        if (r != 1) {
            return 2;
        }
    }
}
