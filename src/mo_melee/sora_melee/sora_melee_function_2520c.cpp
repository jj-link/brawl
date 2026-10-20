#pragma force_active on
#include <types.h>

extern "C" {
extern const float lbl_27_rodata_3B0;
extern const float lbl_27_rodata_3B4;
extern u8 lbl_27_data_2708[];

struct fn27_struct {
    u8* unk0;
    u8 unk4;
    u8 pad5[3];
    void* unk8;
    float unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
};

void fn_27_2520C(fn27_struct* obj, void* param) {
    float arr[6];
    obj->unk0 = lbl_27_data_2708;
    obj->unk4 = 0;
    obj->unk8 = param;
    obj->unk3C = lbl_27_rodata_3B0;
    obj->unk40 = lbl_27_rodata_3B4;
    arr[3] = lbl_27_rodata_3B4;
    arr[4] = lbl_27_rodata_3B4;
    arr[5] = lbl_27_rodata_3B4;
    obj->unkC = arr[3];
    obj->unk10 = arr[4];
    obj->unk14 = arr[5];
    obj->unk18 = arr[3];
    obj->unk1C = arr[4];
    obj->unk20 = arr[5];
    obj->unk24 = arr[3];
    obj->unk28 = arr[4];
    obj->unk2C = arr[5];
    arr[0] = lbl_27_rodata_3B4;
    arr[1] = lbl_27_rodata_3B4;
    arr[2] = lbl_27_rodata_3B4;
    obj->unk30 = arr[0];
    obj->unk34 = arr[1];
    obj->unk38 = arr[2];
}
}
