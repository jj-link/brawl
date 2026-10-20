#pragma force_active on
extern const float lbl_27_rodata_5EBC;

struct SoraMeleeVec2f {
    int unk0;
    int unk4;
    float unk8;
};

extern "C" {
void fn_27_2B4BB8(SoraMeleeVec2f* p) {
    p->unk8 = lbl_27_rodata_5EBC;
}
}
