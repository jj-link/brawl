#include <types.h>
#include <revolution/SO/SOBasic.h>
#pragma force_active on

extern void fn_80335638(s32 level, const char *fmt, ...);
extern void fn_8037A3A4(s32 a, u8 *b, s32 c, void *d);
extern void fn_80387450(u8 *a, s32 b, void *c);
extern s32 fn_803F6150(const void *a, const void *b, unsigned long c);
extern void *memset(void *p, s32 c, unsigned long n);
extern char lbl_8048AA60[];
extern u8 lbl_8059FB68[];
extern int lbl_805A0FA8;

typedef struct SockOut {
    u8 pad0;
    u8 family;
    s16 port;
    u32 addr;
} SockOut;

s32 fn_8033FC9C(s32 arg1, u32 arg2, u32 arg3, u8 *arg4, s32 arg5) {
    char *base = lbl_8048AA60;
    SockOut sp8;
    u8 temp_r30;
    s32 tmp;

    if (arg5 == 0 || arg4 == NULL) {
        return 0;
    }
    memset(&sp8, 0, 8);
    sp8.addr = arg2;
    sp8.family = 2;
    sp8.port = SOHtoNs(arg3);
    temp_r30 = arg4[0];
    if ((temp_r30 == 0xFE && arg4[1] == 0xFD) || temp_r30 == 0x5C) {
        fn_80335638(0x40, base + 0x520);
        tmp = *(int *)(lbl_805A0FA8 + 0x10);
        if (tmp != 0) {
            fn_8037A3A4(tmp, arg4, arg5, &sp8);
        } else {
            fn_80335638(0x40, base + 0x548);
        }
        goto success;
    }
    if (fn_803F6150(arg4, lbl_8059FB68, 6) == 0) {
        fn_80335638(0x40, base + 0x560);
        fn_80387450(arg4, arg5, &sp8);
        goto success;
    }
    if (temp_r30 == 0xFE && arg4[1] == 0xFE) {
        fn_80335638(0x80, base + 0x588);
        return 0;
    }
    fn_80335638(8, base + 0x5B8);
    return 0;
success:
    return 1;
}
