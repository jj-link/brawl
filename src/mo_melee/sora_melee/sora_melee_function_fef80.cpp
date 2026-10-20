#pragma force_active on
struct S {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" int fn_27_FEF80(const S* self) {
    return (self->unk8 >> 25) & 1;
}