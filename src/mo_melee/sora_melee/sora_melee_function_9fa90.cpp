#pragma force_active on
typedef unsigned char u8;

extern const float lbl_27_rodata_CA8;

struct FnObj {
    int unk0;
    int unk4;
    float unk8;
    float unkC;
    u8 pad10[0x28 - 0x10];
    u8 unk28;
    u8 unk29;
    u8 unk2A;
};

extern "C" {
void fn_27_9FA90(FnObj* p, int a, int b, float c, u8 d)
{
    p->unk0 = a;
    p->unk4 = b;
    p->unk8 = c;
    p->unkC = lbl_27_rodata_CA8;
    p->unk2A = d;
    p->unk28 = 1;
    p->unk29 = 1;
}
}
