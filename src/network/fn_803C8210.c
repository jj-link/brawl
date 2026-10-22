#pragma force_active on
typedef unsigned int u32;
typedef long long s64;
extern int lbl_805A1228;
extern int lbl_805A122C;
extern int fn_8020A870(int);
extern void OSSleepTicks(s64);

int fn_803C8210(int arg0) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020A870(arg0);
        if (status == -3) {
            goto sleep;
        }
        if (status == -2) {
            goto sleep;
        }
        return status;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}
