#pragma force_active on
typedef struct Blob {
    int unk0;
    int unk4;
    int unk8;
} Blob;

extern "C" {
Blob* fn_27_1CFF28(Blob* self, int idx)
{
    int i = (self->unk8 >> 28) + idx;
    if (i >= 6) {
        i -= 6;
    }
    return (Blob*)((char*)self + i * 12 + 12);
}
}
