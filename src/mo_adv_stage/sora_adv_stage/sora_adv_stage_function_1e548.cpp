#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_40_1E548(void* p) {
    u32 x = *(u32*)((char*)p + 8);
    return (int)((x << 12) & 0xFE000000u) >> 26;
}
}
