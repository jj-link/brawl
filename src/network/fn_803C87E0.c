#pragma force_active on
typedef long long s64;
typedef unsigned int u32;
extern int lbl_805A1228;
extern int lbl_805A122C;
extern int fn_8020B0E4(int, int);
extern void OSSleepTicks(s64);

int fn_803C87E0(int arg0, int arg1) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020B0E4(arg0, arg1);
        if (status != -3 && status != -2) {
            return status;
        }
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}
