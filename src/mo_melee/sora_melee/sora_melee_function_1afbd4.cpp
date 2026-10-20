#pragma force_active on
struct fn27Obj {
    int unk0;
    int unk4;
    int unk8;
    int arr[5];
};

extern "C" int* fn_27_1AFBD4(fn27Obj* self, int idx)
{
    int i = (self->unk8 >> 28) + idx;
    if (i >= 5) {
        i -= 5;
    }
    return &self->arr[i];
}
