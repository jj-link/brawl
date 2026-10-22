#pragma force_active on
typedef unsigned int u32;
typedef long long s64;
extern int fn_8020BC3C(void*);
extern void OSSleepTicks(s64);

int fn_80398768(char* self) {
    int ret = 0;
    int s;
    u32 i = 0;
    do {
        s = fn_8020BC3C(self + 0xC);
        if ((u32)(s + 3) > 1) break;
        OSSleepTicks(1000 * (s64)((*(u32*)0x800000F8 / 4) / 1000));
        i++;
    } while (i < 3);
    if (s == -4) ret = -0x26;
    else if (s != 0) ret = -0x11;
    return ret;
}
