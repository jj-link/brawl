#pragma force_active on
#include <types.h>

extern int lbl_805A1228;
extern int lbl_805A122C;
extern int fn_8020AB58(void *, void *, s32);
extern void fn_803A9644(void *, void *, s32);
extern void fn_803C73F8(u32, s32, s32 *, s32 *, s32 *, s32 *, s32 *);
extern int fn_803C7DE4(int);
extern void *fn_803C42AC(int);
extern void OSSleepTicks(s64);

static inline int nw_read(void *handle, void *buf, s32 len) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020AB58(handle, buf, len);
        switch (status) { case -3: goto sleep; }
        switch (status) { case -2: goto sleep; }
        break;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

int fn_803C8EF8(void *a, u32 b, s32 n, s32 d) {
    s32 sp50, sp4c, sp48, sp44, sp40;
    u8 buf[0x20] __attribute__((aligned(64)));
    int status;
    fn_803C42AC(fn_803C7DE4(d));
    if (n & 31) return 0;
    fn_803C73F8(b, n, &sp48, &sp50, &sp44, &sp4c, &sp40);
    if (sp48 == 0) {
        status = nw_read(a, (void *)b, n);
        if (status < 0) return status;
    } else {
        fn_803A9644(buf, (void *)b, sp48);
        status = nw_read(a, buf, sp48);
        if (status < 0) return status;
        status = nw_read(a, (void *)sp50, sp44 + sp40);
        if (status < 0) return status;
    }
    return n;
}