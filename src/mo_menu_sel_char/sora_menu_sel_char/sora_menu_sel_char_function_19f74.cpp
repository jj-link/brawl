#include <types.h>
#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Matrix {
    float m[12];
    void setIdentity();
    void setSRT(const Vec3f& s, const Vec3f& r, const Vec3f& t);
};

extern "C" void fn_801AAF04(void* obj, int idx, Matrix* mtx);
extern "C" const float lbl_10_rodata_7D0;
extern "C" const float lbl_10_rodata_7D4;

extern "C" {
void fn_10_19F74(void* self) {
    u8* p = reinterpret_cast<u8*>(self);
    Matrix mtx;
    Vec3f scale;
    Vec3f rot;
    float f = *reinterpret_cast<float*>(p + 0xcc);

    scale.x = f;
    scale.y = f;
    scale.z = lbl_10_rodata_7D0;
    rot.x = lbl_10_rodata_7D4;
    rot.y = lbl_10_rodata_7D4;
    rot.z = lbl_10_rodata_7D4;

    mtx.setIdentity();
    mtx.setSRT(scale, rot, *reinterpret_cast<Vec3f*>(p + 0x90));
    fn_801AAF04(*reinterpret_cast<void**>(p + 0x44), 0, &mtx);
}
}
