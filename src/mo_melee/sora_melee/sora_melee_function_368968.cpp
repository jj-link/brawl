#pragma force_active on
struct FnData {
    int unk0;
    const float* unk4;
    int unk8;
    float unkC;
    float unk10;
};

extern "C" void fn_27_368968(FnData* self, const float* src, int v)
{
    self->unk0 = v;
    self->unk4 = src;
    self->unk8 = 0;
    self->unkC = *src;
    self->unk10 = *src;
}
