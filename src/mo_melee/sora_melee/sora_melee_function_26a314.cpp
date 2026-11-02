#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_25F3C4(void* self, const char* name);
void fn_27_262210(void* self, void* data);
extern u8 lbl_27_data_568E8[];
extern const f32 lbl_27_rodata_4388;
extern const f32 lbl_27_rodata_438C;
}

extern "C" void* __ct__9grGimmickFPCc(void* arg0, const char* arg1) {
    char* self = (char*)arg0;
    fn_27_25F3C4(self, arg1);
    *(u32*)(self + 0x9C) = 0;
    *(void**)(self + 0x3C) = lbl_27_data_568E8;
    *(u32*)(self + 0xA0) = 0;
    *(u32*)(self + 0xA4) = 0;
    *(u32*)(self + 0xA8) = 0;
    *(u32*)(self + 0xAC) = 0;
    *(u32*)(self + 0xB0) = 0;
    *(f32*)(self + 0xB4) = lbl_27_rodata_4388;
    *(u32*)(self + 0xB8) = 0;
    *(u32*)(self + 0xCC) = 0;
    fn_27_262210(self + 0xD0, lbl_27_data_568E8);

    f32 v[3];
    v[0] = lbl_27_rodata_4388;
    v[1] = lbl_27_rodata_4388;
    v[2] = lbl_27_rodata_4388;
    *(u8*)(self + 0xE0) = 0;
    *(u8*)(self + 0xE1) = 1;
    *(u32*)(self + 0xE4) = 0x1F;
    *(u32*)(self + 0xEC) = *(u32*)&v[0];
    *(u32*)(self + 0xF0) = *(u32*)&v[1];
    *(u32*)(self + 0xF4) = *(u32*)&v[2];
    *(f32*)(self + 0xF8) = lbl_27_rodata_438C;
    *(u32*)(self + 0xBC) = 0;
    *(s32*)(self + 0xC0) = -1;
    *(s32*)(self + 0xC4) = -1;
    *(u8*)(self + 0xC8) = 0;
    *(u8*)(self + 0x6C) |= 1;
    *(u32*)(self + 0xFC) = 0;
    *(u32*)(self + 0x124) = 0;
    *(u32*)(self + 0x100) = 0;
    *(u32*)(self + 0x128) = 0;
    *(u32*)(self + 0x104) = 0;
    *(u32*)(self + 0x12C) = 0;
    *(u32*)(self + 0x108) = 0;
    *(u32*)(self + 0x130) = 0;
    *(u32*)(self + 0x10C) = 0;
    *(u32*)(self + 0x134) = 0;
    *(u32*)(self + 0x110) = 0;
    *(u32*)(self + 0x138) = 0;
    *(u32*)(self + 0x114) = 0;
    *(u32*)(self + 0x13C) = 0;
    *(u32*)(self + 0x118) = 0;
    *(u32*)(self + 0x140) = 0;
    *(u32*)(self + 0x11C) = 0;
    *(u32*)(self + 0x144) = 0;
    *(u32*)(self + 0x120) = 0;
    *(u32*)(self + 0x148) = 0;
    return self;
}
