#pragma force_active on
typedef unsigned int u32;

extern unsigned char lbl_27_data_3B1A0[];

struct SoWorkData {
    unsigned char* unk0;
    unsigned char* unk4;
    u32 unk8;
};

extern "C" {
void fn_27_1A7348(SoWorkData* p) {
    p->unk0 = lbl_27_data_3B1A0;
    p->unk4 = lbl_27_data_3B1A0 + 0x48;
    p->unk8 = p->unk8 & 0x7FFFF;
}
}
