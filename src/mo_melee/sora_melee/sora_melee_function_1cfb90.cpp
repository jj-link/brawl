#pragma force_active on
struct Fn27Entry {
    int unk0;
    int unk4;
    int flags;
};

extern "C" {
void *fn_27_1CFB90(Fn27Entry *self, int index)
{
    int n = (self->flags >> 26) + index;
    if (n >= 0x12) {
        n -= 0x12;
    }
    return (char *)self + 0xc + n * 0xc;
}
}
