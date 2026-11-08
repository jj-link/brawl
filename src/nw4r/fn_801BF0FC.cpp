#pragma force_active on

extern "C" {
extern float lbl_805A34E0;
extern const float lbl_805A34E4;
extern float lbl_805A34E8;
extern const float lbl_8040AD30[];

struct Obj {
    int unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    unsigned char unk14;
};

void fn_801BF0FC(Obj* arg0) {
    float value;
    float scale = lbl_805A34E0;
    float limit;
    float tableValue;

    value = lbl_805A34E8 * scale;
    limit = lbl_805A34E4;

    arg0->unk8 = limit;
    tableValue = lbl_8040AD30[127];
    arg0->unk10 = tableValue;
    arg0->unk14 = 127;
    arg0->unkC = limit;
    arg0->unk4 = value;
    arg0->unk0 = 0;
}
}
