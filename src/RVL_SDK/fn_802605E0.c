#include <types.h>
#include <revolution/OS/OS.h>
#pragma force_active on
#pragma use_lmw_stmw on

extern const char *lbl_8059EE50;

typedef struct {
    void *ptr;
    s32 format;
    u16 width;
    u16 height;
    u8 a;
    u8 pad;
    u16 b;
    u8 c;
    u8 pad2[3];
    s32 result;
    s32 arg;
    char reserved[0x80];
    u32 size;
} Params;

typedef struct {
    char pad[0x10];
    s32 out1;
    char rest[0x6e8];
} Work;

extern s32 fn_8026B3D8(Work *, void *, s32, Params *);
extern s32 fn_8026B544(Work *, s32, s32);

s32 TMCCJPEGEncEncode(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u32 arg7, s32 *out)
{
    Work work;
    Params p;
    s32 r;
    s32 count;

    OSRegisterVersion(lbl_8059EE50);
    *out = 0;
    p.c = 1;
    if (arg2 > 0xFFFF || arg2 <= 0 || arg3 > 0xFFFF || arg3 <= 0) {
        r = -1;
    } else if (arg7 < 0x25F) {
        r = -3;
    } else if (arg4 != 4 && arg4 != 6) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return r;
    }
    p.width = arg2;
    p.height = arg3;
    p.a = 2;
    p.c = 1;
    p.result = arg5;
    p.b = 0;
    p.format = arg4;
    p.ptr = arg0;
    p.size = arg7;
    count = fn_8026B3D8(&work, (void *)arg6, arg1, &p);
    if (count < 0) {
        return count;
    }
    for (;;) {
        r = fn_8026B544(&work, count, arg1);
        if (r < 0) {
            *out = work.out1;
            return r;
        }
        if (r <= 0) {
            break;
        }
    }
    *out = work.out1;
    return 0;
}
