#include <types.h>
#include <gf/gf_model.h>

#pragma force_active on

extern "C" {
void update__9grGimmickFf(void* self, float deltaFrame);
void updateCallback__9grGimmickFUl(void* self, unsigned long arg);
extern const float lbl_27_rodata_4410;
}

struct GimAnimIface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(float);
};

struct GimPad {
    char pad[0x3c];
};

struct GimVt : GimPad {
    virtual void f2(); virtual void f3(); virtual void f4();
    virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
    virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29();
    virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34();
    virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
    virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44();
    virtual void f45(); virtual void f46(); virtual void f47(); virtual void f48(); virtual void f49();
    virtual void f50(); virtual void f51(); virtual void f52(); virtual void f53(); virtual void f54();
    virtual void f55(); virtual void f56(); virtual void f57(); virtual void f58(); virtual void f59();
    virtual void f60(); virtual void f61(); virtual void f62(); virtual void f63();
    virtual void f64(void*, s32);
    virtual void f65(); virtual void f66(); virtual void f67(); virtual void f68(); virtual void f69();
    virtual void f70(); virtual void f71(); virtual void f72(); virtual void f73(); virtual void f74();
    virtual void f75(); virtual void f76(); virtual void f77(); virtual void f78(); virtual void f79();
    virtual void f80(); virtual void f81(); virtual void f82(); virtual void f83(); virtual void f84();
    virtual void f85(); virtual void f86(); virtual void f87(); virtual void f88(); virtual void f89();
    virtual void f90(); virtual void f91(); virtual void f92(); virtual void f93(); virtual void f94();
    virtual void f95(); virtual void f96(); virtual void f97(); virtual void f98(); virtual void f99();
    virtual void f100(); virtual void f101(); virtual void f102(); virtual void f103(); virtual void f104();
    virtual void f105(); virtual void f106(); virtual void f107(); virtual void f108(); virtual void f109();
    virtual void f110(); virtual void f111(); virtual void f112(); virtual void f113();
    virtual void f114();
    virtual void f115(void*);
};

struct SpringVec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct BlkA {
    s32 a;
    s32 b;
    SpringVec3 v;
    f32 d;
    f32 e;
};

struct BlkB {
    s32 a;
    s32 b;
    SpringVec3 v;
    f32 p;
    f32 q;
};

class grGimmickSpring {
public:
    void update(float deltaFrame);
};

void grGimmickSpring::update(float deltaFrame) {
    char* self = (char*)this;
    BlkA sp24;
    BlkB sp8;
    void* obj;
    void* o;

    update__9grGimmickFf(self, deltaFrame);
    switch (*(u8*)(self + 0x158)) {
    case 1:
        obj = *(void**)(*(char**)(*(char**)(self + 0x48)) + 0x1c);
        ((GimAnimIface*)obj)->f5(*(float*)(self + 0x15c));
        if (*(float*)(self + 0x15c) > (f32)*(s32*)(self + 0x160)) {
            sp24.a = 0x18;
            sp24.b = 0;
            ((GimVt*)self)->f115(&sp24.v);
            sp24.d = *(f32*)(*(char**)(self + 0x150) + 0x3c);
            sp24.e = *(f32*)(*(char**)(self + 0x150) + 0x38);
            o = *(void**)(self + 0x14c);
            ((GimVt*)o)->f64(&sp24, -1);
            ((GimVt*)self)->f114();
        } else {
            sp8.a = 0x19;
            sp8.b = 0;
            ((GimVt*)self)->f115(&sp8.v);
            o = *(void**)(self + 0x14c);
            ((GimVt*)o)->f64(&sp8, -1);
        }
        break;
    case 2:
        obj = *(void**)(*(char**)(*(char**)(self + 0x48)) + 0x1c);
        ((GimAnimIface*)obj)->f5(*(float*)(self + 0x15c));
        if (*(float*)(self + 0x15c) > (f32)*(s32*)(self + 0x164)) {
            (*(gfModelAnimation***)(self + 0x48))[0]->unbindShapeAnim(
                (*(nw4r::g3d::ScnMdl***)(self + 0x44))[0]);
            *(u8*)(self + 0x158) = 0;
            *(f32*)(self + 0x15c) = lbl_27_rodata_4410;
        }
        break;
    }
    *(f32*)(self + 0x15c) += deltaFrame;
    updateCallback__9grGimmickFUl(self, 0);
}
