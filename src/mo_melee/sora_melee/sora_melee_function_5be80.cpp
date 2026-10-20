#pragma force_active on
struct fn_27_5BE80_data {
    unsigned char pad0[0x40];
    unsigned int value40;
    unsigned char pad44[4];
    unsigned char flag48;
};

extern "C" bool fn_27_5BE80(const fn_27_5BE80_data* self) {
    return self->flag48 == 0 || self->value40 == 0;
}
