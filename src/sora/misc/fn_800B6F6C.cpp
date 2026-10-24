#include <types.h>
#pragma force_active on

class fnVirtBase {
public:
    virtual void vf0(s32, s32);
    virtual void vf1(s32, s32);
    virtual void vf2(s32, s32);
    virtual void vf3(s32, s32);
    virtual void vf4(s32, s32);
    virtual void vf5(s32, s32);
    virtual void vf6(s32, s32);
};

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" {
void setIdentity__6MatrixFv(void*);
void setSRT__6MatrixFRC5Vec3fRC5Vec3fRC5Vec3f(void*, void*, void*, void*);
void fn_801AAF04(void*, int, void*);
}

extern const f32 lbl_805A2204;

struct Object {
    u8 padding[0x3C];
    Vec3 a;
    Vec3 b;
};

extern "C" void fn_800B6F6C(Object* arg0, const Vec3* arg1) {
    u8* self = (u8*)arg0;
    const Vec3* src = arg1;
    Vec3 v;
    f32 mtx[12];

    arg0->b = *src;

    v.x = lbl_805A2204;
    v.y = lbl_805A2204;
    v.z = lbl_805A2204;

    setIdentity__6MatrixFv(mtx);
    setSRT__6MatrixFRC5Vec3fRC5Vec3fRC5Vec3f(mtx, &v, self + 0x48, self + 0x3C);
    fn_801AAF04(*(void**)(self + 0xC), 0, mtx);

    fnVirtBase* obj = *(fnVirtBase**)(self + 0x10);
    obj->vf6(2, 0);
    obj->vf6(5, 0);
}
