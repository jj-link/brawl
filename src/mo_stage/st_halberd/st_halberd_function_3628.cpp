#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct grCollision;

struct Data {
    unsigned char pad[0x9C];
    float range;
};

struct Stage {
    unsigned char pad0[0x9C];
    Data* data;
    unsigned char padA0[0x330];
    unsigned char state;
    unsigned char pad3D1[0x17];
    float x, y, z;
};

extern "C" {
extern const float lbl_57_rodata_0[];

float randf__Fv();

int stRayCheck__FP5Vec3fP5Vec3fP5Vec3fP5Vec3fbP11grCollisionbUc(
    Vec3f*, Vec3f*, Vec3f*, Vec3f*,
    bool, grCollision*, bool, unsigned char);

void fn_57_3628(Stage* self) {
    const float* constants = lbl_57_rodata_0;
    Data* data = self->data;
    if (data) {
        switch (self->state) {
        case 12: {
            Vec3f start = {constants[0], constants[64], constants[0]};
            Vec3f end = {constants[0], constants[65], constants[0]};
            Vec3f hit;
            Vec3f normal;
            float x = -data->range
                + constants[66] * data->range * randf__Fv();

            if (stRayCheck__FP5Vec3fP5Vec3fP5Vec3fP5Vec3fbP11grCollisionbUc(
                    &start, &end, &hit, &normal, true, 0, false, 1)) {
                self->x = x;
                self->y = hit.y;
                self->z = constants[0];
                self->state = 13;
            }
            break;
        }
        }
    }
}
}
