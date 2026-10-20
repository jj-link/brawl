#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_CB0CC(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    u32 t = (v >> 21) & 0x3F;
    return (s32)(t << 26) >> 27;
}
