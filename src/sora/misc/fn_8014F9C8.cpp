#pragma force_active on
extern void *g_GameGlobal;

typedef unsigned char u8;
typedef unsigned long long u64;
typedef long long s64;

extern "C" u64 fn_8014F9C8(void) {
    u8 *p = *(u8 **)((u8 *)g_GameGlobal + 0x34);

    return (u64)(((s64)p[0x7D] << 8) +
                 (((s64)p[0x7C] << 16) + ((s64)p[0x7B] << 24))) +
           (u64)p[0x7E] +
           ((((u64)p[0x7A] << 32) + ((u64)p[0x79] << 40)) +
            (((u64)p[0x77] << 56) + ((u64)p[0x78] << 48)));
}
