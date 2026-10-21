#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
u32 fn_80294380(u8 *arg0) {
    u32 base = ((u32)arg0 + 0x37) & ~0xF;
    return base + ((u32)*(u16 *)(arg0 + 6) << 5);
}
}
