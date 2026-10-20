#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_27_1CFA74(void *p);
}

extern "C" int fn_27_1CFA74(void *p) {
    u32 x = *(u32 *)((char *)p + 8);
    u32 r = ((x << 6) | (x >> 26)) & 0xFE000000;
    return (int)r >> 26;
}
