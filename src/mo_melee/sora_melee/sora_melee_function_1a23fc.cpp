#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
int fn_27_1A23FC(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    return ((s32)((v << 8) & 0xF8000000)) >> 28;
}
}
