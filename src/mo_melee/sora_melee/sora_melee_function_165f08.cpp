#include <so/so_module_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#include <types.h>

#pragma force_active on

#define DUM(n) virtual void d##n();

class Work {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5)
    DUM(6) DUM(7) DUM(8) DUM(9) DUM(10) DUM(11)
    virtual float getFloat(u32);      // 0x38
    virtual void setFloat(float, u32); // 0x3c
    DUM(14) DUM(15) DUM(16)
    virtual u32 isFlag(u32);          // 0x4c
};

class Kinetic {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5) DUM(6) DUM(7)
    DUM(8) DUM(9) DUM(10) DUM(11) DUM(12) DUM(13) DUM(14) DUM(15)
    DUM(16) DUM(17) DUM(18) DUM(19) DUM(20)
    virtual void f21(u32, soModuleAccesser*); // 0x5c
};

class Posture {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5) DUM(6) DUM(7)
    DUM(8)
    virtual float getLr();           // 0x2c
};

class Motion {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5) DUM(6)
    virtual void setRot(float);      // 0x24
};

class Camera {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5) DUM(6) DUM(7)
    DUM(8) DUM(9) DUM(10) DUM(11) DUM(12) DUM(13) DUM(14) DUM(15)
    DUM(16) DUM(17) DUM(18) DUM(19) DUM(20) DUM(21) DUM(22) DUM(23)
    DUM(24) DUM(25) DUM(26) DUM(27) DUM(28) DUM(29) DUM(30) DUM(31)
    DUM(32) DUM(33) DUM(34) DUM(35) DUM(36) DUM(37) DUM(38) DUM(39)
    virtual void f40(u32);           // 0xa8
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern "C" float fn_27_194A74(void*);
extern "C" void fn_27_1652A8(void*, u32, u32, u32, u32, float, float);
extern "C" const float lbl_27_rodata_2048;

extern "C" void fn_27_165F08(void* owner, soModuleAccesser* self) {
    float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xBC0, 0);

    if (reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->isFlag(0x1200000A) == 1) {
        reinterpret_cast<Kinetic*>(self->m_enumerationStart->m_kineticModule)->f21(0x45, self);
    } else {
        reinterpret_cast<Kinetic*>(self->m_enumerationStart->m_kineticModule)->f21(0xE, self);
    }

    fn_27_1652A8(self, 0xF, 0x21000005, 0x21000007, 0, scale, fn_27_194A74(self));

    if (reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->isFlag(0x1200000A) == 1) {
        float v5 = reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->getFloat(0x21000005);
        float absV = (float)(double)nw4r::math::FAbs(v5);
        if (absV < lbl_27_rodata_2048) {
            float k = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xD8A, 0);
            Posture* p = reinterpret_cast<Posture*>(self->m_enumerationStart->m_postureModule);
            Work* w = reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule);
            float lr = p->getLr();
            w->setFloat(k * lr, 0x21000005);
        }
    }

    float a = reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->getFloat(0x21000005);
    float b = reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->getFloat(0x21000007);
    float r;
    if (reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->isFlag(0x1200000A) == 1) {
        float k = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xD8A, 0);
        r = b * k;
        if (r < k) r = k;
    } else {
        float absv5 = (float)(double)nw4r::math::FAbs(a);
        r = b * absv5;
    }
    float limit = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC3C, 0);
    if (r > limit) r = limit;

    reinterpret_cast<Motion*>(self->m_enumerationStart->m_motionModule)->setRot(r);
    reinterpret_cast<Camera*>(self->m_enumerationStart->m_cameraModule)->f40(0);
}