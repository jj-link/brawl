#include <types.h>
#pragma force_active on
extern s32 fn_803AA540(void *);
extern s32 fn_803AA858(void *, s32);
extern void fn_803B032C(void *);
extern s32 fn_803B3678(void *);
extern s32 fn_803B7540(void *, void *);
extern s32 fn_803B7C98(void *);
extern s32 fn_803B80F0(void *);
extern s32 fn_803C06B8(void *);
extern s32 fn_803C0838(void *, s32);
extern char lbl_8053B248[];

static inline int mount(char *self) {
    if (!(*(u16 *)(self + 0x1878) & 2)) {
        int status = fn_803C06B8(self);
        if (status != 0) return status;
        *(u16 *)(self + 0x187c) &= 0xfff8;
        ++*(int *)(lbl_8053B248 + 0x10);
    }
    return 0;
}
s32 fn_803C093C(void *arg0, s32 arg1) {
    char *self = (char *)arg0;
    u32 restore = 0;
    s32 saved15e8 = 0;
    u16 saved187c = 0;
    s32 r = 0;
    u32 x;
    s32 sp8;

    if (self == 0) return 10;
    if (fn_803AA540(self) != 0) return 11;
    r = fn_803AA858(self, arg1);
    if (r != 0) return r;
    if (*(u16 *)(self + 0x1878) & 2) {
        saved15e8 = *(s32 *)(self + 0x15e8);
        saved187c = *(u16 *)(self + 0x187c);
        restore = 1;
        fn_803B032C(self);
        r = fn_803C0838(self, 0);
        if (r != 0) return r;
    }
    r = mount(self);
    if (r != 0) return r;
    if (restore == 1) {
        *(s32 *)(self + 0x15e8) = saved15e8;
        *(u16 *)(self + 0x187c) = saved187c;
    }
    if (*(u16 *)(self + 0x1878) & 0x20) {
        if (*(s32 *)(self + 0x1c) == 2) {
            x = *(u16 *)(self + 0x187c);
            if (x & 2) {
                *(u16 *)(self + 0x187c) = (u16)(x | 4);
                fn_803B80F0(self);
                goto done;
            }
        }
        x = *(u16 *)(self + 0x187c);
        x = x & 0xFFFFFFFBU;
        *(u16 *)(self + 0x187c) = (u16)x;
        if (*(s32 *)(self + 0x1c) != 2) {
            *(u16 *)(self + 0x187c) = (u16)(x & 0xFFFC);
        }
        r = fn_803B7540(self, &sp8);
        if (r != 0) return r;
done:
        return 0;
    }
    r = fn_803B7C98(self);
    if (r != 0) return r;
    r = fn_803B3678(self);
    if (r != 0) return r;
    if (*(s32 *)(self + 0x1c) != 2)
        *(u16 *)(self + 0x187c) = (u16)(*(u16 *)(self + 0x187c) & 0xFFFC);
    if (*(s32 *)(self + 0x1c) == 2 && (*(u16 *)(self + 0x187c) & 2)) {
        r = fn_803B80F0(self);
        if (r != 0) return r;
    }
    return 0;
}