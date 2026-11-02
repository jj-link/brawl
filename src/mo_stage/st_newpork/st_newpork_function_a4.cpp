#pragma force_active on
#include <types.h>

extern "C" {
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void fn_8009ED40(void*, int, int);
void fn_8009F1FC(void*);
void setIdentity__6MatrixFv(void*);
extern const char lbl_69_data_50[];
extern const char lbl_69_data_328[];
extern s32 lbl_69_data_0;
extern const float lbl_69_rodata_0;
}

extern "C" void* fn_69_A4(void* arg0) {
    char* self = (char*)arg0;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_69_data_50, 0x20);
    *(const char**)(self + 0x3C) = lbl_69_data_328;
    *(s32*)(self + 0x224) = lbl_69_data_0;
    *(s32*)(self + 0x228) = 0;
    *(s32*)(self + 0x23C) = lbl_69_data_0;
    *(s32*)(self + 0x240) = 0;
    *(s32*)(self + 0x250) = lbl_69_data_0;
    *(s32*)(self + 0x254) = 0;
    fn_8009ED40(self + 0x2BC, 0, 1);
    *(s8*)(self + 0x348) = -1;
    *(s32*)(self + 0x1D8) = 0;
    *(s32*)(self + 0x1DC) = 0;
    *(s32*)(self + 0x1E0) = 0;
    *(s32*)(self + 0x1E4) = 0;
    *(s32*)(self + 0x1E8) = 0;
    *(s32*)(self + 0x1EC) = 0;
    *(s32*)(self + 0x1F0) = 0;
    *(s32*)(self + 0x1F4) = 0;
    *(s32*)(self + 0x1F8) = 0;
    *(s32*)(self + 0x1FC) = 0;
    *(s32*)(self + 0x200) = 0;
    *(s32*)(self + 0x204) = 0;
    *(s32*)(self + 0x208) = 0;
    *(s32*)(self + 0x20C) = 0;
    *(s32*)(self + 0x210) = 0;
    *(s32*)(self + 0x214) = 0;
    *(s32*)(self + 0x218) = 0;
    *(s32*)(self + 0x21C) = 0;
    *(s32*)(self + 0x220) = 0;
    *(f32*)(self + 0x22C) = lbl_69_rodata_0;
    *(f32*)(self + 0x230) = lbl_69_rodata_0;
    *(f32*)(self + 0x234) = lbl_69_rodata_0;
    *(s8*)(self + 0x238) = 0;
    *(f32*)(self + 0x244) = lbl_69_rodata_0;
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x24C) = 0;
    *(s8*)(self + 0x258) = 0;
    *(s32*)(self + 0x25C) = 0;
    *(f32*)(self + 0x260) = lbl_69_rodata_0;
    *(f32*)(self + 0x264) = lbl_69_rodata_0;
    *(f32*)(self + 0x268) = lbl_69_rodata_0;
    setIdentity__6MatrixFv(self + 0x26C);
    *(s8*)(self + 0x2A8) = 0;
    *(f32*)(self + 0x29C) = lbl_69_rodata_0;
    *(f32*)(self + 0x2A0) = lbl_69_rodata_0;
    *(f32*)(self + 0x2A4) = lbl_69_rodata_0;
    *(f32*)(self + 0x2AC) = lbl_69_rodata_0;
    *(f32*)(self + 0x2B0) = lbl_69_rodata_0;
    *(f32*)(self + 0x2B4) = lbl_69_rodata_0;
    *(f32*)(self + 0x2B8) = lbl_69_rodata_0;
    *(f32*)(self + 0x340) = lbl_69_rodata_0;
    *(f32*)(self + 0x344) = lbl_69_rodata_0;
    *(s32*)(self + 0x34C) = 0;
    fn_8009F1FC(self + 0x2BC);
    return arg0;
}
