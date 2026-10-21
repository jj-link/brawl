#pragma force_active on
extern "C" {
extern float lbl_805A33B8;
extern float lbl_805A33BC;
}

struct Fn9400Obj {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
};

struct Fn9400Src {
    float unk0;
    float unk4;
};

extern "C" void fn_801A9400(Fn9400Obj* obj, const Fn9400Src* src) {
    float v = src->unk4;
    float r = lbl_805A33BC - v;
    float z = lbl_805A33B8;
    float x = src->unk0;
    obj->unk4 = z;
    obj->unk0 = x;
    obj->unk8 = z;
    obj->unkC = z;
    obj->unk10 = z;
    obj->unk14 = v;
    obj->unk18 = z;
    obj->unk1C = r;
}
