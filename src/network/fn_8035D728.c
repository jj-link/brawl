#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

extern u64 OSGetTime(void);
extern u64 fn_803F1470(u64 a, u64 b);

u32 fn_8035D728(void) {
    u64 t = OSGetTime();
    u32 d = (*(u32 *)0x800000F8 >> 2) / 1000;
    return (u32)fn_803F1470(t, (u64)d);
}
