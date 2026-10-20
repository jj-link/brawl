#pragma force_active on
extern const float lbl_27_rodata_E28;

struct SoraSrc {
    char pad[0x24];
    float unk24;
};

struct SoraDst {
    float unk0;
    float unk4;
    float unk8;
};

extern "C" {
void fn_27_B75C8(SoraDst* dst, SoraSrc* src) {
    float v = lbl_27_rodata_E28;
    float a = src->unk24;
    dst->unk0 = a;
    dst->unk4 = v;
    dst->unk8 = v;
}
}
