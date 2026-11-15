#pragma force_active on
#include <types.h>

extern int lbl_805A1228;
extern int lbl_805A122C;
extern void OSSleepTicks(s64);
extern void fn_803C73F8(s32, s32, s32 *, s32 *, s32 *, s32 *, s32 *);
extern int fn_8020AA78(void *, void *, u32);
extern int fn_8020AC38(void *, int, int);
extern void fn_803A9644(void *, void *, int);

static inline int nw_read(void *handle, void *buf, u32 len) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020AA78(handle, buf, len);
        switch (status) { case -3: goto sleep; }
        switch (status) { case -2: goto sleep; }
        break;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

static inline int nw_seek(void *handle, s32 off, int flag) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020AC38(handle, off, flag);
        switch (status) { case -3: goto sleep; }
        switch (status) { case -2: goto sleep; }
        break;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

int fn_803C8B48(void *handle, u32 addr, s32 len) {
    s32 sp50, sp4c, sp48, sp44, sp40;
    u8 buf[0x20] __attribute__((aligned(64)));
    int status;

    if (len & 0x1F) {
        return 0;
    }
    fn_803C73F8(addr, len, &sp48, &sp50, &sp44, &sp4c, &sp40);
    if (sp48 == 0) {
        status = nw_read(handle, (void *)addr, len);
        if (status < 0) {
            return status;
        }
    } else {
        status = nw_read(handle, buf, 0x20);
        if (status < 0) {
            return status;
        }
        fn_803A9644((void *)addr, buf, sp48);
        status = nw_seek(handle, -sp40, 1);
        if (status < 0) {
            return status;
        }
        if (sp44 != 0) {
            status = nw_read(handle, (void *)sp50, sp44);
            if (status < 0) {
                return status;
            }
        }
        if (sp40 != 0) {
            status = nw_read(handle, buf, 0x20);
            if (status < 0) {
                return status;
            }
            fn_803A9644((void *)sp4c, buf, sp40);
        }
    }
    return len;
}
