#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" void* fn_27_1AFA44(void* self, s32 idx) {
    s32 v = *(s32*)((u8*)self + 8);
    s32 n = (v >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (u8*)self + (n << 2) + 0xc;
}
