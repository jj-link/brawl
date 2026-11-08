#include <types.h>
#pragma force_active on

void fn_803974FC(void);
void **fn_80397570(void);
int fn_80392730(const char *str);
int fn_80392734(const char *a, const char *b);
int fn_803926B8(void *unused, const char *arg);
void fn_8039272C(void *dst, const char *src, int n);
void fn_80392738(void *dest, unsigned long count);

s32 fn_8039471C(void *arg0) {
    char *self = (char *)arg0;
    char *r30;
    char *r29;
    s32 r3;

    fn_803974FC();
    r30 = (char *)*fn_80397570();
    r30 = *(char **)(r30 + 0xc);
    r29 = *(char **)(r30 + 0x28);

    if (*(s32 *)(r30 + 0xc) != 0) {
        r29 = r30 + 0xe0;
    }

    if (fn_80392730(r29) == 0 || fn_80392734(r29, self + 4) != 0) {
        r3 = fn_803926B8(r30, r29);
        *(s32 *)(self + 0x314) = r3;
        if (r3 == 0) {
            if (*(s32 *)(r30 + 0xc) != 0) {
                *(s32 *)(self + 0x330) = 0xc;
                return 0;
            }
            *(s32 *)(self + 0x330) = 4;
            return 0;
        }
    } else {
        *(s32 *)(self + 0x314) = *(s32 *)(self + 0x318);
    }

    fn_80392738(self + 4, 0x100);
    fn_8039272C(self + 4, r29, fn_80392730(r29));
    *(s32 *)(self + 0x31c) = *(s32 *)(r30 + 0x20);
    if (*(s32 *)(r30 + 0xc) != 0) {
        *(s32 *)(self + 0x31c) = *(s32 *)(r30 + 0x1e0);
    }
    if ((u32)*(s32 *)(self + 0x314) != (u32)*(s32 *)(self + 0x318) ||
        *(s32 *)(self + 0x31c) != *(s32 *)(self + 0x320) ||
        *(s32 *)(r30 + 0x8) == 1) {
        *(s32 *)(self + 0x338) = 0;
    }
    *(s32 *)(self + 0x318) = *(s32 *)(self + 0x314);
    *(s32 *)(self + 0x320) = *(s32 *)(self + 0x31c);
    return 1;
}
