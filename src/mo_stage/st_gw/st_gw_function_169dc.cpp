#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Object {
    unsigned char pad0[0x1A4];
    unsigned char* state;
    unsigned char pad1[4];
    Vec3* position;
    unsigned char pad2[8];
    float factor;
};

extern "C" const float lbl_63_rodata_220[];

extern "C" void fn_63_169DC(Object* self, Vec3* out)
{
    const float* constants = lbl_63_rodata_220;

    switch (*self->state) {
    case 1:
        out->x = constants[0];
        out->y = constants[0];
        out->z = constants[0];
        break;

    case 0: {
        Vec3* pos = self->position;
        out->x = pos->x;
        out->y = pos->y;
        out->z = pos->z;
        out->y += constants[3] * (constants[2] * self->factor);
        break;
    }
    }
}
