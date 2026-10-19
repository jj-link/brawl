#pragma force_active on
typedef struct Obj
{
    int unk0;
    int unk4;
    int unk8;
} Obj;

extern "C" void *fn_56_65B4(Obj *self, int n)
{
    int s = self->unk8 >> 30;
    int i = s + n;
    if (i >= 1) {
        i = i - 1;
    }
    return (char *)self + i * 0x90 + 0xc;
}
