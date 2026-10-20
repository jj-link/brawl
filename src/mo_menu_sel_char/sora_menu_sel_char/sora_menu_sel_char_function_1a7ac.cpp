#include <types.h>
#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Matrix {
    float m[12];
    void setIdentity();
    void setSRT(const Vec3f&, const Vec3f&, const Vec3f&);
};

struct RO {
    float one, zero, small;
};

extern "C" const RO lbl_10_rodata_7D0;

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void f34(void*, void*);
    virtual void v12();
    virtual void f3c(void*);
};

extern "C" void fn_10_19FF4(u8*, int, int);
extern "C" void fn_801AAF04(void*, int, Matrix*);

extern "C" void fn_10_1A7AC(u8* self, int arg) {
    const RO* r = &lbl_10_rodata_7D0;
    fn_10_19FF4(self, 2, 0);

    int enabled = (*(u32*)(*(u8**)(self + 0x9c) + 0x1dc) >> 31) ^ 1;
    VObj* obj = *(VObj**)(self + 0x40);
    obj->f3c(*(void**)(self + 0x44));

    if (enabled && !self[0xdc]) {
        obj = *(VObj**)(self + 0x40);
        obj->f34(*(void**)((u8*)obj + 0xe4), *(void**)(self + 0x44));
    }

    self[0xd0] = enabled;
    *(int*)(self + 0xa4) = 2;
    *(int*)(self + 0xa8) = 0;
    *(int*)(self + 0xa0) = arg;

    Matrix mtxOther;
    Vec3f rotOther, scaleOther;
    Matrix mtx;
    Vec3f rot, scale;

    if (arg == 0) {
        *(float*)(self + 0xcc) = r->small;
        scale.x = r->small;
        scale.y = r->small;
        scale.z = r->one;
        rot.x = r->zero;
        rot.y = r->zero;
        rot.z = r->zero;

        mtx.setIdentity();
        mtx.setSRT(scale, rot, *(Vec3f*)(self + 0x90));
        fn_801AAF04(*(void**)(self + 0x44), 0, &mtx);
    } else {
        *(float*)(self + 0xcc) = r->one;
        scaleOther.x = r->one;
        scaleOther.y = r->one;
        scaleOther.z = r->one;
        rotOther.x = r->zero;
        rotOther.y = r->zero;
        rotOther.z = r->zero;

        mtxOther.setIdentity();
        mtxOther.setSRT(scaleOther, rotOther, *(Vec3f*)(self + 0x90));
        fn_801AAF04(*(void**)(self + 0x44), 0, &mtxOther);
    }
}
