#include <types.h>
#pragma force_active on

typedef struct hkMath {
    f32 unk0;
} hkMath;

typedef struct Block {
    f32 v[48];
} __attribute__((aligned(16))) Block;

extern f32 lbl_805A3E04;

extern void fn_80291DE8(void *dst, const void *src);
extern void fn_8029211C(void *a, void *b, void *c, void *d);
extern void fn_802921B0(void *a, const void *b);
extern void fn_80284614(void *dst, const void *src);
extern void fn_80290AC0(void *p);
extern void fn_80284240(void *out, const void *a, const void *b);
extern void fn_8029193C(void *dst, const void *src);
extern void fn_80283EB4(void *dst, const void *src);
extern void fn_80284670(void *dst, const void *src);
extern hkMath *fn_80291270(void *base, s32 i, s32 j);
extern f32 max2f__6hkMathFff(f32 a, f32 b);

void fn_80291C70(u8 *arg0, u8 *base, void *arg2, void *arg3, void **arg4)
{
    Block t260, t1A0, tE0, t20;
    s32 i;
    hkMath *a, *b;
    u8 flag;

    fn_80291DE8(&t260, base + 0x240);
    fn_80291DE8(&t1A0, base + 0x300);
    flag = *arg0;
    fn_8029211C(arg2, &flag, &t260, &t1A0);
    fn_802921B0(arg2, arg3);
    fn_80284614(base, arg3);
    fn_80290AC0(&tE0);
    fn_80284240(&tE0, base, *arg4);
    fn_8029193C(base + 0xC0, &t260);
    fn_80283EB4(base + 0xC0, &tE0);

    i = 0;
    do {
        a = fn_80291270(base + 0xC0, i, i);
        b = fn_80291270(base + 0x150, i, i);
        a->unk0 = max2f__6hkMathFff(a->unk0, lbl_805A3E04);
        {
            f32 threshold = lbl_805A3E04;
            b->unk0 = max2f__6hkMathFff(b->unk0, threshold);
        }
        i++;
    } while (i < 3);

    fn_80290AC0(&t20);
    fn_8029193C(&t20, base + 0xC0);
    fn_80284670(base + 0xC0, &t20);
    fn_80284240(base + 0x180, base + 0xC0, &t1A0);
    fn_8029193C(arg3, base + 0x300);
    *arg4 = base + 0x180;
}
