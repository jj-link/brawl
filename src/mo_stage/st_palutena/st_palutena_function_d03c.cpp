#pragma force_active on
typedef unsigned char u8;

struct Vec3f { float x, y, z; };

struct GimmickSrc {
    unsigned char pad0[0x18];
    float f18;
    unsigned char pad1[0x24 - 0x1C];
    float f24;
};

struct GimmickSelf {
    unsigned char pad0[0x14c];
    GimmickSrc* src;
    u8 state;
    unsigned char pad1[3];
    float f154;
    float f158;
};

extern "C" {
extern const float lbl_67_rodata_1C8[5];
void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* pos);

void fn_67_D03C(GimmickSelf* self) {
    GimmickSrc* src = self->src;
    float one = lbl_67_rodata_1C8[0];
    if (one == src->f24) {
        self->f158 = src->f18;
        self->f154 = one;
        self->state = 2;
    } else {
        self->f158 = one;
        self->f154 = src->f24;
        self->state = 3;
    }
    setPos__9grGimmickFP5Vec3f(self, (Vec3f*)self->src);
}
}
