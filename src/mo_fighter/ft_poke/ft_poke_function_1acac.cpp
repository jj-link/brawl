#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
extern "C" {
extern const float lbl_116_rodata_60[];
Vec2f* fn_116_CB3C(Vec2f*, const Vec2f*);
float fn_8003DDD0(const Vec2f*, const Vec2f*);
}
#pragma scheduling off
#pragma optimize_for_size on
#pragma always_inline on
#pragma pool_data on
#pragma pool_fp_consts on
inline Vec2f* makeUp(Vec2f* result) {
    result->m_x = 0.0f;
    result->m_y = 1.0f;
    return result;
}
extern "C" void fn_116_1ACAC(soKineticEnergy* energy, soModuleAccesser* accesser) {
    float pool; double bias;
    pool = 0.0f; pool = 1.0f; pool = 57.295780181884766f; pool = -1.0f;
    bias = 4503601774854144.0;
    if (energy->isEnable()) {
        int type = accesser->getKineticModule().getKineticType();
        switch (type) {
        case 0x66:
        case 0x67: {
            Vec2f speed;
            Vec2f::copy(speed, energy->getSpeed());
            if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(6), 0) == 1) {
                speed.m_x *= -soValueAccesser::getConstantFloat(accesser, 0xfb6, 0);
                fn_116_CB3C(reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 8), &speed);
            }
            Vec2f limit(0.0f, 0.0f);
            Vec2f accel(0.0f, 0.0f);
            if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(8), 0) == 1) {
                Vec2f normal;
                Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0));
                int angle = static_cast<int>(57.295780181884766f * fn_8003DDD0(makeUp(&Vec2f()), &normal));
                if (angle == 0) {
                    float value = soValueAccesser::getConstantFloat(accesser, 0xfae, 0);
                    if (static_cast<float>(static_cast<double>(nw4r::math::FAbs(speed.m_x))) < value) {
                        accel.m_x = soValueAccesser::getConstantFloat(accesser, 0xfb0, 0);
                        if (speed.m_x < 0.0f) accel.m_x = -accel.m_x;
                    }
                    limit.m_x = value;
                } else {
                    float sign = normal.m_x < 0.0f ? -1.0f : 1.0f;
                    float value;
                    if (normal.m_x * speed.m_x < 0.0f) {
                        value = soValueAccesser::getConstantFloat(accesser, 0xfb7, 0);
                    } else {
                        value = soValueAccesser::getConstantFloat(accesser, 0xfb8, 0);
                    }
                    accel.m_x = static_cast<float>(angle) * (sign * value);
                    limit.m_x = soValueAccesser::getConstantFloat(accesser, 0xfac, 0);
                }
            } else {
                float value = soValueAccesser::getConstantFloat(accesser, 0xfaf, 0);
                if (static_cast<float>(static_cast<double>(nw4r::math::FAbs(speed.m_x))) < value) {
                    accel.m_x = soValueAccesser::getConstantFloat(accesser, 0xfb1, 0);
                    if (speed.m_x < 0.0f) accel.m_x = -accel.m_x;
                }
                limit.m_x = value;
            }
            fn_116_CB3C(reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x10), &accel);
            fn_116_CB3C(reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 0x18), &limit);
            break;
        }
        }
    }
    energy->updateEnergy(accesser);
}