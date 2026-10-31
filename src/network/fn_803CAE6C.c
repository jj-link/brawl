#include <revolution/OS/OSThread.h>

#pragma force_active on

typedef long long s64;

extern int fn_803C7C64(int);
extern int *fn_803C4450(int);
extern int fn_803C7A70(int, int, int *, int, int *);
extern int fn_803C7E40(int);
extern int fn_803C75EC(int, int, int);
extern int fn_8020AC38(int, int, int);
extern int fn_803C8EF8(int, int, int, int);
extern void fn_803C7D64(int, int);
extern int lbl_805A1228;
extern int lbl_805A122C;

int fn_803CAE6C(int arg0, int arg1, int arg2, int arg3, int *arg4, int arg5) {
    int count;
    int prod;
    int step;
    int status;
    int handle;
    int limit;
    int out;
    int *entry;

    limit = fn_803C7C64(arg5);
    entry = fn_803C4450(arg5);
    out = 0;

    if (entry == 0)
        return -0x14;

    handle = *entry;

    if (fn_803C7A70(arg0, arg2, arg4, arg5, &out) == 0)
        return out;

    prod = arg0 * arg3;
    step = fn_803C75EC(arg2, arg3, fn_803C7E40(arg5));
    count = lbl_805A1228;
    status = 0;

    while (count-- > 0) {
        status = fn_8020AC38(handle, step, 0);
        if (status == -3)
            goto sleep;
        switch (status) {
        case -2:
            goto sleep;
        default:
            break;
        }
        break;
sleep:
        OSSleepTicks(lbl_805A122C *
                     (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }

    if ((u32)status == (u32)step) {
        if ((u32)(step + prod) > (u32)limit)
            return -0x16;

        status = fn_803C8EF8(handle, arg1, prod, arg5);
        if ((u32)status == (u32)prod) {
            *arg4 = arg0;
            return 0;
        }
    }

    fn_803C7D64(arg5, status);
    return status;
}
