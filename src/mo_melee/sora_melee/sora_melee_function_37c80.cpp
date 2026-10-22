#include <types.h>
#pragma force_active on

extern "C" void fn_8015BF9C(void*, int);
extern "C" s32 lbl_27_bss_B0;
extern "C" const float lbl_27_rodata_488;

extern "C" void* __ct__16soCollisionGroupFv(void* self) {
    char* p = (char*)self;
    char* p0C = p + 0x0C;
    float val = lbl_27_rodata_488;
    *(void**)(p + 0x34) = p + 0x28;
    *(void**)(p + 0x38) = p;
    *(void**)(p + 0x3C) = p0C;
    *(float*)(p + 0x4C) = val;
    *(float*)(p + 0x50) = val;
    *(float*)(p + 0x54) = val;
    *(s16*)(p + 0x70) = -1;
    *(u8*)(p + 0x72) = 0;
    *(u8*)(p + 0x73) = 0;
    *(u8*)(p + 0x74) = 0;
    fn_8015BF9C(p + 0x1C, 0x28);
    fn_8015BF9C(*(void**)(p + 0x34), 0);
    fn_8015BF9C(*(void**)(p + 0x38), 0);
    fn_8015BF9C(*(void**)(p + 0x3C), 0);
    fn_8015BF9C(p + 0x40, 0x10);
    *(s32*)(p + 0x18) = lbl_27_bss_B0++;
    return p;
}
