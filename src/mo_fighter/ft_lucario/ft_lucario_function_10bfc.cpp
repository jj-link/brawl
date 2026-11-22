#pragma force_active on

#include <types.h>
#include <nw4r/math/math_types.h>
#include <cm/cm_camera_controller.h>

struct VT {
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(nw4r::math::VEC3*);
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual float m13(float);
    virtual void m14();
    virtual void m15();
    virtual float m16();
};

class Stage {
    char pad[0x3c];

public:
    virtual void m01();
    virtual void m02();
    virtual void m03();
    virtual void m04();
    virtual void m05();
    virtual void m06();
    virtual void m07();
    virtual void m08();
    virtual void m09();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61(nw4r::math::VEC3*, u32);
};

extern "C" void fn_118_933C(
    nw4r::math::VEC3* dst, const nw4r::math::VEC3* src);

extern Stage* lbl_27_bss_5668;
extern const float lbl_118_rodata_98[];

extern "C" void fn_118_10BFC(void* self, unsigned char* obj) {
    const float* const c = lbl_118_rodata_98;
    nw4r::math::VEC3 v20, v14, v8;

    unsigned char* mods = *(unsigned char**)(obj + 0xD8);
    VT* a = *(VT**)(mods + 0x8);
    VT* b = *(VT**)(mods + 0xC);

    lbl_27_bss_5668->m61(&v14, 0);
    fn_118_933C(&v20, &v14);

    float cam = *(float*)((unsigned char*)CameraController::getInstance() + 0x150);
    v20.y = c[1] + cam;

    float t = a->m13(cam);
    float d = a->m16();

    register f32 wOne, p0, p1, p2, p3, wS;
    wS = (float)sin(c[2] * (t / d));
    register nw4r::math::VEC3* pOut = &v8;
    wOne = c[3] - wS;
    register nw4r::math::VEC3* pA = &v20;
    register nw4r::math::VEC3* pB = &v14;
    asm {
        psq_l p0, 0(pA), 0, 0
        psq_l p1, 8(pA), 1, 0
        psq_l p2, 0(pB), 0, 0
        psq_l p3, 8(pB), 1, 0
        ps_muls0 p0, p0, wOne
        ps_muls0 p1, p1, wOne
        ps_madds0 wOne, p2, wS, p0
        ps_madds0 p0, p3, wS, p1
        psq_st wOne, 0(pOut), 0, 0
        psq_st p0, 8(pOut), 1, 0
    }

    b->m6(&v8);
}
