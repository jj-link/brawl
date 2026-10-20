#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct State {
    unsigned char pad0[0xC];
    unsigned char mode;
    unsigned char padD[2];
    unsigned char status;
    unsigned char pad10;
    unsigned char flags;
    unsigned char pad12[2];
    unsigned int value;
    unsigned char pad18[0x60];
    Vec3 position;
    float amount;
};

extern "C" void fn_27_115DF0(State* self, const Vec3* position,
                            unsigned int value, float amount) {
    self->position = *position;
    self->amount = amount;
    self->mode = 7;
    self->value = value;
    self->flags |= 0x20;
    if (self->status != 3)
        self->status = 5;
}
