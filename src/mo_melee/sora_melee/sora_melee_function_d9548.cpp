#pragma force_active on
typedef struct Holder {
    int pad[2];
    int field8;
} Holder;

extern "C" {
char *fn_27_D9548(Holder *self, int idx)
{
    int i = (self->field8 >> 26) + idx;
    if (i >= 0x17) {
        i -= 0x17;
    }
    return (char *)self + i * 0x30 + 0xC;
}
}
