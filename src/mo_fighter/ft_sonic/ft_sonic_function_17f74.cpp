#pragma always_inline on
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#pragma force_active on
#pragma scheduling off
#pragma opt_common_subs off
#pragma optimize_for_size on
#pragma inline all

struct GroundView : soNull, soNullable {
    virtual void m02(); virtual void m03(); virtual void m04(); virtual void m05();
    virtual void m06(); virtual void m07(); virtual void m08(); virtual void m09();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
    virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17();
    virtual void m20(int, unsigned long);
};
struct EnergyView {
    virtual void slot1();
    virtual void updateEnergy(soModuleAccesser*);
    virtual unsigned long long getSpeed();
};

extern "C" {
extern const float lbl_123_rodata_98;
extern const float lbl_123_rodata_9C;
int fn_123_183C4(float);
int fn_123_183EC(float);
float fn_123_18410(float* v);
void fn_123_9574(Vec2f&, const Vec2f&);
}

extern "C" void fn_123_17F74(soKineticEnergy* energy, soModuleAccesser* accesser) {
    float stickX = accesser->getControllerModule().getStickX();
    float stickY = accesser->getControllerModule().getStickY();
    float absX, absY;
    float f27 = lbl_123_rodata_9C;
    Vec2f v60, v58, v50, v48;

    unsigned long long raw40 = reinterpret_cast<EnergyView*>(energy)->getSpeed();
        Vec2f& v40 = *reinterpret_cast<Vec2f*>(&raw40);
    int r = fn_123_183C4(v40.m_x);
    if (r != 0) {
        r = fn_123_183C4(v40.m_y);
    }
    bool cond = (r == 1);
    if (cond) {
        unsigned long long raw38 = reinterpret_cast<EnergyView*>(energy)->getSpeed();
        Vec2f& v38 = *reinterpret_cast<Vec2f*>(&raw38);
        int r29 = 0;
        if (fn_123_183EC(v38.m_x) != 0 && fn_123_183EC(v38.m_y) != 0) {
            r29 = 1;
        }
        cond = (r29 == 0);
    }
    if (cond) {
        unsigned long long raw30 = reinterpret_cast<EnergyView*>(energy)->getSpeed();
        Vec2f& v30 = *reinterpret_cast<Vec2f*>(&raw30);
        float f31 = soValueAccesser::getConstantFloat(accesser, 0xFA5, 0);
        float magnitude = fn_123_18410(&v30.m_x);
        f27 = magnitude * f31;
    }

    v60.m_x = lbl_123_rodata_9C;
    v60.m_y = lbl_123_rodata_9C;
    v58.m_x = lbl_123_rodata_98;
    v58.m_y = lbl_123_rodata_98;
    v50.m_x = lbl_123_rodata_9C;
    v50.m_y = lbl_123_rodata_9C;

    unsigned long long raw48 = reinterpret_cast<EnergyView*>(energy)->getSpeed();
    __memcpy(&v48, &raw48, sizeof(v48));
    unsigned long long raw20 = reinterpret_cast<EnergyView*>(energy)->getSpeed();
        Vec2f& v20 = *reinterpret_cast<Vec2f*>(&raw20);
    float lenV20 = fn_123_18410(&v20.m_x);
    absX = (float)(double)nw4r::math::FAbs(stickX);
    if (absX < soValueAccesser::getConstantFloat(accesser, 0xFA4, 0)) {
        v60.m_x = f27;
        v58.m_x = lbl_123_rodata_9C;
    } else {
        v50.m_x = stickX * soValueAccesser::getConstantFloat(accesser, 0xFA0, 0);
    }

    if (accesser->getKineticModule().getKineticType() == 0x20 &&
        stickY < soValueAccesser::getConstantFloat(accesser, 0xFA4, 0)) {
        v48.m_y = lbl_123_rodata_9C;
    } else {
        absY = (float)(double)nw4r::math::FAbs(stickY);
        if (absY < soValueAccesser::getConstantFloat(accesser, 0xFA4, 0)) {
            v60.m_y = f27;
            v58.m_y = lbl_123_rodata_9C;
        } else {
            v50.m_y = stickY * soValueAccesser::getConstantFloat(accesser, 0xFA2, 0);
            if (accesser->getKineticModule().getKineticType() == 0x20) {
                accesser->getSituationModule().setKind(static_cast<SituationKind>(2), false);
                reinterpret_cast<GroundView*>(&accesser->getGroundModule())->m20(5, 0);
            }
        }
    }

    fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x10), v50);
    fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x20), v60);
    fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x18), v58);
    fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x8), v48);

    if (energy->isEnable() == true &&
        *(reinterpret_cast<unsigned char*>(energy) + 6) == 0) {
        energy->updateEnergy(accesser);
    }

    int r28 = 0;
    unsigned long long raw18 = reinterpret_cast<EnergyView*>(energy)->getSpeed();
        Vec2f& v18 = *reinterpret_cast<Vec2f*>(&raw18);
    if (fn_123_18410(&v18.m_x) < lenV20) {
        unsigned long long raw10 = reinterpret_cast<EnergyView*>(energy)->getSpeed();
        Vec2f& v10 = *reinterpret_cast<Vec2f*>(&raw10);
        float thr = soValueAccesser::getConstantFloat(accesser, 0xFA6, 0);
        if (fn_123_18410(&v10.m_x) < thr) {
            r28 = 1;
        }
    }
    if (r28 != 0) {
        Vec2f v8;
        v8.m_x = lbl_123_rodata_9C;
        v8.m_y = lbl_123_rodata_9C;
        fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x8), v8);
    }
}
