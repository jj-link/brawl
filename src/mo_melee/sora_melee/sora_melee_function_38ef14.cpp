#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern "C" {
u32 fn_27_38EF14(u8* self, s32 unused, s32 n, s32 idx) {
    s32 off = n - *(s32*)(self + 0x14);
    u32* arr = *(u32**)(self + (off << 2) + 0x40);
    return arr[idx];
}
}
