#pragma force_active on
struct fn_8004ADD0_data {
    unsigned char pad[0x18];
    int* unk18;
    int unk1C;
};

extern "C" int fn_8004ADD0(const fn_8004ADD0_data* self) {
    int r0 = 0;
    if (self->unk18 != 0) {
        r0 = (*self->unk18 - 1) == 0;
    }
    int r4 = 0;
    if (r0 != 0 && self->unk1C <= 1) {
        r4 = 1;
    }
    return r4;
}
