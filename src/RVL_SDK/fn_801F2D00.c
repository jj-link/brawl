#pragma force_active on
typedef unsigned int u32;

u32 fn_801F2D00(void *arg0) {
    u32 x = *(u32 *)((char *)arg0 + 0xC);
    return (x << 5) & 0x1FFFFFE0;
}
