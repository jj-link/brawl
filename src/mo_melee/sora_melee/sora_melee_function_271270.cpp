#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

struct Obj {
    u32 unk0;
    u32 unk4;
    u8 pad8[0x20];
    float unk28;
    u8 unk2c;
    u8 pad2d[0xb];
    s32 unk38;
};

extern "C" u32 lbl_27_data_57DB0;
extern "C" const float lbl_27_rodata_4460;

extern "C" void fn_27_271270(Obj* p)
{
    p->unk28 = lbl_27_rodata_4460;
    p->unk2c = 0;
    p->unk38 = -1;
    p->unk4 = lbl_27_data_57DB0;
}
