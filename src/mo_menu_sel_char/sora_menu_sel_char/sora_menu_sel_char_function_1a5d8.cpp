#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>

#pragma force_active on

struct Pair { u32 x, y; Pair() {} };

struct RO {
    float one;
    float zero;
    float small;
};

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
    virtual void v14();
    virtual void f3c(void*);
};

extern "C" {
extern const RO lbl_10_rodata_7D0;
Pair fn_10_1BC38(int);
void fn_10_19FF4(u8*, int, int);
void fn_801AAF04(void*, int, Matrix*);
}

static inline Pair getSelfPos(u8* self) {
    Pair v;
    *(float*)&v.x = *(float*)(self + 0x90);
    *(float*)&v.y = *(float*)(self + 0x94);
    return v;
}

extern "C" void fn_10_1A5D8(u8* self, int arg) {
    const RO* r = &lbl_10_rodata_7D0;
    Matrix mtx2(true), mtx1(true);
    Vec3f rot2, scale2, rot1, scale1;
    Pair pos = fn_10_1BC38(arg);
    Pair cur = getSelfPos(self);
    int idx;
    if (*(float*)&pos.x > *(float*)&cur.x) {
        idx = 9;
    } else {
        idx = 10;
    }
    fn_10_19FF4(self, idx, 0);
    VObj* obj = *(VObj**)(self + 0x40);
    int enabled = (*(u32*)(*(u8**)(self + 0x9c) + 0x1dc) >> 31) ^ 1;
    obj->f3c(*(void**)(self + 0x44));
    if (enabled && !self[0xdc]) {
        obj = *(VObj**)(self + 0x40);
        obj->f34(*(void**)((u8*)obj + 0xe4), *(void**)(self + 0x44));
    }
    self[0xd0] = enabled;
    *(int*)(self + 0xa4) = 1;
    *(int*)(self + 0xa8) = 0;
    *(int*)(self + 0xa0) = arg;

    if (arg == 0) {
        *(float*)(self + 0xcc) = r->small;
        scale1.m_x = r->small;
        scale1.m_y = r->small;
        scale1.m_z = r->one;
        rot1.m_x = r->zero;
        rot1.m_y = r->zero;
        rot1.m_z = r->zero;
        mtx1.setIdentity();
        mtx1.setSRT(scale1, rot1, *(Vec3f*)(self + 0x90));
        fn_801AAF04(*(void**)(self + 0x44), 0, &mtx1);
    } else {
        *(float*)(self + 0xcc) = r->one;
        scale2.m_x = r->one;
        scale2.m_y = r->one;
        scale2.m_z = r->one;
        rot2.m_x = r->zero;
        rot2.m_y = r->zero;
        rot2.m_z = r->zero;
        mtx2.setIdentity();
        mtx2.setSRT(scale2, rot2, *(Vec3f*)(self + 0x90));
        fn_801AAF04(*(void**)(self + 0x44), 0, &mtx2);
    }
}
