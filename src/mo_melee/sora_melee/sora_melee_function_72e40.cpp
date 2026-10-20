#pragma force_active on
struct Fn27Entry {
    int unk0;
    int unk4;
    int unk8;
    void* arr[20];
};

extern "C" void* fn_27_72E40(Fn27Entry* self, int idx)
{
    int off = self->unk8 >> 26;
    int i = off + idx;
    if (i >= 20) {
        i -= 20;
    }
    return &self->arr[i];
}
