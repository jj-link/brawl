#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_CF9BC(void* p) {
    u32 x = *(u32*)((char*)p + 8);
    u32 y = ((x << 3) | (x >> 29)) & 0xF0000000;
    return (s32)y >> 29;
}
}
