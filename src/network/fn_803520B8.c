#include <types.h>
#include <string.h>
#include <revolution/NHTTP/d_nhttp.h>
#pragma force_active on

extern int lbl_805A0FD8;
extern char *lbl_805A0FD4;
extern char lbl_8048D400[];
extern int lbl_80534030[];
extern void fn_80335638(int, const char *, ...);
extern int fn_8038E3F0(void *);
extern void *fn_80352BEC(size_t, int);
extern void fn_80352C04(void *);
extern u16 *fn_803FC7E4(u16 *, const u16 *, int);

int fn_803520B8(const u16 *arg0, const char *arg1, unsigned long long arg2,
                void *(*arg4)(int, int), void *arg5)
{
    const char *base = lbl_8048D400;
    int result;
    if (lbl_805A0FD8 != 0 && lbl_805A0FD8 != 0x1a) {
        fn_80335638(0x1000000, base + 0x118);
        return 0;
    }
    lbl_805A0FD4 = arg4(0, 0x5b40);
    if (lbl_805A0FD4 == 0) {
        fn_80335638(0x1000000, base + 0x130);
        return 0;
    }
    memset(lbl_805A0FD4, 0, 0x5b40);
    *(void *(**)(int, int))(lbl_805A0FD4 + 0x5b30) = arg4;
    *(void **)(lbl_805A0FD4 + 0x5b34) = arg5;
    result = fn_8038E3F0(lbl_805A0FD4 + 0x4020);
    if (result != 0) {
        fn_80335638(0x1000000, base + 0x144, result);
        return 0;
    }
    if (NHTTPStartup(fn_80352BEC, fn_80352C04, 0x11) < 0) {
        fn_80335638(0x1000000, base + 0x168);
        return 0;
    }
    fn_803FC7E4((u16 *)(lbl_805A0FD4 + 0x417e), arg0, 0x1a);
    strncpy(lbl_805A0FD4 + 0x41b2, arg1, 0xc);
    base = (const char *)1;
    *(int *)(lbl_805A0FD4 + 0x59e4) = 1;
    memset(lbl_80534030, 0, 0x1d0);
    lbl_80534030[0x1b4 / 4] = (unsigned int)arg2;
    lbl_80534030[0x1b8 / 4] = 0;
    lbl_80534030[0x1b0 / 4] = (unsigned int)(arg2 >> 32);
    if (arg2 == 0) {
        base = (const char *)1;
    } else {
        base = (const char *)0x13;
    }
    lbl_805A0FD8 = (int)base;
    return 1;
}