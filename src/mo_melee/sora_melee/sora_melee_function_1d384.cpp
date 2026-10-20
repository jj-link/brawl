#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1D384(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    s32 f = (s32)((v >> 13) & 0x7F);
    return (f << 25) >> 26;
}
