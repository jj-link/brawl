#pragma force_active on
extern "C" {
extern const float lbl_805A34E8;
extern const float lbl_805A34EC;

struct fn_801BF190_data {
    int unk0;
    float unk4;
    unsigned char pad8[8];
    float unk10;
};

float fn_801BF190(const fn_801BF190_data* self) {
    if (self->unk0 != 0 || lbl_805A34EC != self->unk10) {
        return self->unk4 / lbl_805A34E8;
    }
    return lbl_805A34EC;
}
}
