#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_5EBC;
}

struct Object {
    unsigned char padding[8];
    float unk8;
    float unkC;
    float unk10;
};

extern "C" void fn_27_2B4B30(Object* p) {
    p->unk8 = p->unkC = p->unk10 = lbl_27_rodata_5EBC;
}
