#include <types.h>
#pragma force_active on

struct RO {
    float one;
    float zero;
    float small;
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

struct MatrixF {
    float m[12];
};

extern "C" void fn_10_19FF4(u8*, int, int);
extern "C" void fn_801AAF04(void*, int, MatrixF*);
extern "C" void setIdentity__6MatrixFv(MatrixF*);
extern "C" void setSRT__6MatrixFRC5Vec3fRC5Vec3fRC5Vec3f(MatrixF*, float*, float*, float*);

extern "C" void fn_10_1A924(u8* self) {
    const RO* r = &lbl_10_rodata_7D0;
    fn_10_19FF4(self, 8, 0);

    int enabled = (*(u32*)(*(u8**)(self + 0x9c) + 0x1dc) >> 31) ^ 1;
    VObj* obj = *(VObj**)(self + 0x40);
    obj->f3c(*(void**)(self + 0x44));

    if (enabled && !self[0xdc]) {
        obj = *(VObj**)(self + 0x40);
        obj->f34(*(void**)((u8*)obj + 0xe4), *(void**)(self + 0x44));
    }

    self[0xd0] = enabled;
    *(int*)(self + 0xa4) = 3;
    *(int*)(self + 0xa8) = 0;
    *(int*)(self + 0xa0) = 0;

    MatrixF mtx;
    float rot[3];
    float scale[3];

    *(float*)(self + 0xcc) = r->small;
    scale[0] = r->small;
    scale[1] = r->small;
    scale[2] = r->one;
    rot[0] = r->zero;
    rot[1] = r->zero;
    rot[2] = r->zero;

    setIdentity__6MatrixFv(&mtx);
    setSRT__6MatrixFRC5Vec3fRC5Vec3fRC5Vec3f(&mtx, scale, rot, (float*)(self + 0x90));
    fn_801AAF04(*(void**)(self + 0x44), 0, &mtx);
}
