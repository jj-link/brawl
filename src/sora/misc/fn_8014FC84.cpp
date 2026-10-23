#pragma force_active on
extern "C" {
extern void *g_GameGlobal;

typedef unsigned long long u64;

u64 fn_8014FC84(void) {
    unsigned char *p = *(unsigned char **)((char *)g_GameGlobal + 0x34);

    return (((u64)p[0x2D] << 8) + ((u64)p[0x2C] << 16) + (u64)p[0x2E])
         + ((((u64)p[0x2B] << 24) + ((u64)p[0x2A] << 32))
         + (((u64)p[0x27] << 56) + ((u64)p[0x28] << 48) + ((u64)p[0x29] << 40)));
}
}
