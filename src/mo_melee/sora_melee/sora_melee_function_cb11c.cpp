#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

extern "C" s32 fn_27_CB11C(const void* ptr) {
    s32 val = *(const s32*)((const u8*)ptr + 8);
    return (val >> 16) & 1;
}
