#pragma force_active on
struct CrayonData {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" int fn_56_632C(const CrayonData* self) {
    return self->unk8 >> 30;
}
