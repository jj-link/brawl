#include <mt/mt_prng.h>

#pragma force_active on

extern "C" const float lbl_78_rodata_0[];
extern "C" void fn_8009EF8C(void*, const void*, float, float, float, float);

struct Vec3Local {
    float x, y, z;
};

struct RectLocal {
    float a, b, c, d;
};

struct Object {
    char pad0[0x258];
    unsigned char current;
    unsigned char previous;
    unsigned char other;
    char pad1[5];
    char object[8];
    unsigned int flags;
    char pad2[0x29c - 0x26c];
    RectLocal rect;
    char pad3[0x2e4 - 0x2ac];
    unsigned char state;
};

extern "C" int fn_78_1214(Object* self, unsigned int mode) {
    const float* c = lbl_78_rodata_0;
    float random = randf();
    unsigned int previous;
    unsigned int result;
    if (mode == 1)
        previous = 0xff;
    else
        previous = self->previous;
    switch (previous) {
    case 0:
        if (random < c[13]) result = 1;
        else if (random < c[14]) result = 2;
        else result = 3;
        break;
    case 1:
        if (random < c[13]) result = 0;
        else if (random < c[14]) result = 2;
        else result = 3;
        break;
    case 2:
        if (random < c[13]) result = 0;
        else if (random < c[14]) result = 1;
        else result = 3;
        break;
    case 3:
        if (random < c[13]) result = 0;
        else if (random < c[14]) result = 1;
        else result = 2;
        break;
    default:
        if (random < c[9]) result = 0;
        else if (random < c[15]) result = 1;
        else if (random < c[16]) result = 2;
        else result = 3;
        break;
    }
    if (mode == 1) {
        if (result == self->current) return 0;
        self->other = result;
    } else {
        if (result == self->other) return 0;
        self->current = result;
        self->previous = result;
        RectLocal rect;
        Vec3Local pos;
        pos.x = c[0];
        pos.y = c[0];
        pos.z = c[0];
        rect.c = c[17];
        rect.d = c[18];
        rect.a = c[19];
        rect.b = c[20];
        self->flags &= 0x1fffffff;
        fn_8009EF8C(self->object, &pos, rect.b, rect.a, rect.d, rect.c);
        self->rect = rect;
        self->state = 0;
        self->flags &= 0xe3ffffff;
        self->state = 0;
    }
    return 1;
}
