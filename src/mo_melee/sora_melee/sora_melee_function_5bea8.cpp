#pragma force_active on
struct Data {
    unsigned char pad[0x40];
    int state;
    unsigned char pad44[4];
    bool active;
};

extern "C" bool fn_27_5BEA8(const Data* self) {
    return !self->active || self->state == 2;
}
