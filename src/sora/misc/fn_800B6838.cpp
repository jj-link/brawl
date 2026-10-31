#include <types.h>
#include <mt/mt_matrix.h>
#pragma force_active on

class Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(s32, s32);
};

struct Target {
    u8 padding[0x3C];
    Vec3f rotation;
    Vec3f scale;
};

extern const f32 lbl_805A2204;

extern "C" void fn_801AAF04(void*, int, Matrix*);

extern "C" void fn_800B6838(Target* self, const Vec3f* arg1) {
    Matrix matrix(true);
    Vec3f zero;

    self->rotation = *arg1;

    zero.m_x = lbl_805A2204;
    zero.m_y = lbl_805A2204;
    zero.m_z = lbl_805A2204;

    matrix.setIdentity();
    matrix.setSRT(zero, self->scale, self->rotation);
    fn_801AAF04(*(void**)((u8*)self + 0xC), 0, &matrix);

    Object* object = *(Object**)((u8*)self + 0x10);
    object->vf6(2, 0);
    object->vf6(5, 0);
}
