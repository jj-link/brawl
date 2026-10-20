#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" u32 fn_27_2AF224(void* p) {
    s32 v = *(s32*)((u8*)p + 4);
    return (u32)(v >> 23) >> 31;
}
