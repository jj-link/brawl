#pragma force_active on
typedef struct Obj {
    int unk0;
    int unk4;
    int unk8;
    int arr[1];
} Obj;

extern "C" {
void* fn_27_1D524(Obj* self, int idx)
{
    int i = (self->unk8 >> 30) + idx;
    i = (i >= 1) ? i - 1 : i;
    return &self->arr[i];
}
}
