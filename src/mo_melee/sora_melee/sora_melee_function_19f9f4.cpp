#pragma force_active on
extern "C" {
typedef unsigned char u8;
typedef int s32;

s32 fn_27_19F9F4(void* self) {
    s32 val = *(s32*)((u8*)self + 8);
    return val >> 27;
}
}
