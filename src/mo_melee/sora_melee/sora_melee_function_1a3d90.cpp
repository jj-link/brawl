#pragma force_active on
struct UnknownStruct {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" int fn_27_1A3D90(const UnknownStruct *p) {
    return p->unk8 >> 22;
}
