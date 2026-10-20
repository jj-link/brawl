#pragma force_active on
struct Thing {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" {
void *fn_27_1B0494(Thing *self, int idx) {
    int i = (self->unk8 >> 30) + idx;
    if (i >= 1) {
        i -= 1;
    }
    return (char *)self + 0xc + i * 0x14;
}
}
