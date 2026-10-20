#pragma force_active on
struct Owner {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int m8;
};

extern "C" bool fn_27_1A4C34(Owner* self) {
    return (self->m8 >> 19) & 1;
}
