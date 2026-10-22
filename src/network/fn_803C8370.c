#pragma force_active on
typedef unsigned int u32;
typedef long long s64;
extern int lbl_805A1228;
extern int lbl_805A122C;
extern int fn_8020BC3C(int);
extern void OSSleepTicks(s64);

int fn_803C8370(int arg0) {
    int count;
    int status;
    count = lbl_805A1228;
    status = 0;
    while (count-- > 0) {
        status = fn_8020BC3C(arg0);
        if (status != -3 && status != -2) {
            return status;
        }
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}
