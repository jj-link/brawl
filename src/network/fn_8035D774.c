#pragma force_active on
typedef unsigned int u32;
typedef long long s64;

extern void OSSleepTicks(s64 ticks);

void fn_8035D774(u32 ms) {
    u32 k = (*(u32 *)0x800000F8 / 4) / 1000;
    s64 t = (s64)ms * (s64)k;
    OSSleepTicks(t);
}
