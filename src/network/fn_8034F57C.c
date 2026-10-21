#pragma force_active on
typedef unsigned long long u64;
typedef unsigned int u32;

extern u64 OSGetTime(void);
extern u64 fn_803F1470(u64 a, u64 b);

u64 fn_8034F57C(void) {
    u64 t = OSGetTime();
    u32 d = *(u32 *)0x800000F8 >> 2;
    return fn_803F1470(t, (u64)d) + 0x386D4380ULL;
}
