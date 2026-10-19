#pragma force_active on
extern "C" {

typedef struct Ctr {
    int unk0;
    int unk4;
    int count;
} Ctr;

void *fn_56_6484(Ctr *self, int idx)
{
    int n = (self->count >> 30) + idx;
    if (n >= 1) {
        n--;
    }
    return (char *)self + 0xC + n * 0x38;
}

}
