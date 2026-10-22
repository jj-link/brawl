#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_100_rodata_30[];
Vec3f* fn_100_CC84(Vec3f*, float, float, float);
void fn_100_FE98(void*, int);
}

struct HitInfo { int a; char b; int c; float d, e, f, g, h; char i; };
struct HitBase { int x; int y; };
extern HitBase* lbl_100_bss_268;

class CaptainStage {
    unsigned char padding[0x3C];
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void update();
};

class HitModule {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void set(int, HitInfo*);
};

extern "C" void fn_100_E744(void*, soModuleAccesser* accesser) {
    const float* c = (const float*)lbl_100_rodata_30;
    const soModuleEnumeration* m = accesser->m_enumerationStart;
    soPostureModule* posture = m->m_postureModule;
    m->m_workManageModule->offFlag(0x12000019);

    Vec3f position;
    posture->setPos(fn_100_CC84(&position, c[0], c[1], c[0]));
    posture->setLr(c[0]);

    Vec3f rotation;
    posture->setRot(fn_100_CC84(&rotation, c[0], c[0], c[0]), 0);

    CaptainStage* stage =
        reinterpret_cast<CaptainStage*>(&accesser->getStageObject());
    stage->update();

    fn_100_FE98(accesser, 0x14);

    HitInfo info;
    info.a = 0x44F;
    info.b = 0;
    info.c = 6;
    info.d = c[0];
    info.e = c[1];
    info.f = c[4];
    info.g = c[2];
    info.h = c[0];
    info.i = 0;
    HitModule* hm = *(HitModule* const*)(
        (const char*)(accesser->m_enumerationStart) + 0x54);
    hm->set(lbl_100_bss_268->y, &info);
}
