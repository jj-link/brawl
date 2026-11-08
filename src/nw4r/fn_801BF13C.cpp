#pragma force_active on
extern "C" {
extern const float lbl_805A34E8;
extern const float lbl_805A34E4;
extern const float lbl_8040AD30[];
}
struct S { int unk0; float unk4, unk8, unkC, unk10; unsigned char unk14;
 void init(float value) { unk8 = lbl_805A34E4; unk10 = lbl_8040AD30[127]; unk14 = 127; unkC = lbl_805A34E4; unk4 = value; unk0 = 0; }
};
extern "C" void fn_801BF13C(S* p, float scale) {
 p->init(lbl_805A34E8 * scale);
}
