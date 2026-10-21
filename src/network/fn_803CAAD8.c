#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
extern int lbl_805A1228;
extern int lbl_805A122C;
extern int *fn_803C4450(void);
extern int fn_8020BC3C(int);
extern void fn_803C7D64(int, int);
extern void OSSleepTicks(s64);

int fn_803CAAD8(int arg0) {
    int *entry;
    int count;
    int status;
    u16 result;
    int retval;
    if (arg0 == 0)
        return -20;
    entry = fn_803C4450();
    if (entry != 0) {
        int handle = *entry;
        count = lbl_805A1228;
        status = 0;
        while (count-- > 0) {
            status = fn_8020BC3C(handle);
            switch (status) {
            case -3:
                goto sleep;
            }
            switch (status) {
            case -2:
                goto sleep;
            }
            break;
sleep:
            OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
        }
finished:
        if (status == 0) {
            result = 0;
        } else {
            fn_803C7D64(arg0, status);
            goto failure;
        }
    } else {
failure:
        result = 0xFFFF;
    }
    retval = result;
    if (retval == 0)
        retval = 0;
    return retval;
}