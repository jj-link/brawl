#pragma always_inline on
#include <types.h>
#include <math.h>
#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on
#pragma scheduling off
#pragma optimize_for_size on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_122_12CC4(Vec2f* dst, const Vec2f& src);
void fn_122_27980(void* object, const Vec3f* value);
void fn_122_2799C(void* a0, float value, void* self);
extern const unsigned char lbl_122_data_10750[], lbl_122_data_81AC[], lbl_122_data_E1EC[];
extern const float lbl_122_rodata_180[];
}

class EnergyUniq {
public:
    virtual void v1();
    virtual void v2();
    virtual Vec2f getVec2();
    char pad[0xC];
    Vec2f m10;
    Vec2f m18;
    char pad2[0x34 - 0x20];
    float m34;
};

class Class_E104 {
public:
    virtual void fn_122_ABB4();
    virtual void fn_122_176B0();
    virtual void fn_122_18F4C();
    virtual void fn_122_18F44();
    virtual Vec3f fn_122_18F3C();
    virtual void fn_122_18F34();
    virtual void fn_122_18F2C();
    virtual void fn_122_18F24();
    virtual void fn_122_18F1C();
    virtual void fn_122_18F14();
    virtual void fn_122_18F0C();
    virtual void fn_122_18F04();
    virtual void fn_122_18EFC();
    virtual void fn_122_18EF4();
    virtual void fn_122_18EA4();
    virtual void fn_122_18EEC();
    virtual void fn_122_18EDC();
    virtual void fn_122_18ECC();
    virtual void fn_122_18EBC();
    virtual void fn_122_18EAC();
    virtual void fn_122_18E94();
};

class Speed : public Vec2f {
public:
    Speed(float x, const float& y) {
        m_x = x;
        m_y = y;
    }
};

extern "C" void fn_122_272F0(void* arg0, soModuleAccesser* accesser) {
    const float* rod = lbl_122_rodata_180;
    int zero = 0;

    EnergyUniq* energy = static_cast<EnergyUniq*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(2), zero,
        lbl_122_data_10750, lbl_122_data_81AC, static_cast<short>(zero)));
    Class_E104* gravity = static_cast<Class_E104*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), zero,
        lbl_122_data_E1EC, lbl_122_data_81AC, static_cast<short>(zero)));

    if (energy != 0 && gravity != 0) {
        float previousAngle = energy->m34;

        if (accesser->getWorkManageModule().getInt(0x10000006) >= 0) {
            accesser->getWorkManageModule().decInt(0x10000006);
            float f29 = energy->m34;
            f29 += accesser->getWorkManageModule().getFloat(0x11000001);
            float old = energy->m34;
            accesser->getWorkManageModule().setFloat(old, 0x21000002);
            energy->m34 = f29;
            Vec3f rot;
            rot.m_x = -f29;
            rot.m_y = rod[2];
            rot.m_z = rod[3];
            accesser->getPostureModule().setRot(&rot, 1);
        } else if (accesser->getControllerModule().getStickX() != rod[3] ||
                   accesser->getControllerModule().getStickY() != rod[3]) {
            float f30 = rod[4] * accesser->getControllerModule().getStickAngle() - energy->m34;
            if (rod[3] != f30) {
                if (f30 < rod[5]) {
                    f30 += rod[6];
                } else if (f30 > rod[7]) {
                    f30 -= rod[6];
                }
                float f29 = accesser->getWorkManageModule().getFloat(0x21000000);
                float f1 = accesser->getWorkManageModule().getFloat(0x21000001);
                float f28 = rod[3];
                if (static_cast<float>(static_cast<double>(nw4r::ut::Abs(f30))) > f29) {
                    float f0;
                    if (f30 < f28) {
                        f0 = rod[8];
                    } else {
                        f0 = rod[9];
                    }
                    f28 = f29 * f0;
                }
                if (static_cast<float>(static_cast<double>(nw4r::ut::Abs(f30))) < f1) {
                    f28 *= rod[10];
                }
                float old = energy->m34;
                accesser->getWorkManageModule().setFloat(old, 0x21000002);
                float f2 = f28 + energy->m34;
                if (static_cast<float>(static_cast<double>(nw4r::ut::Abs(f2))) >= rod[6]) {
                    float f0;
                    if (f2 >= rod[3]) {
                        f0 = rod[8];
                    } else {
                        f0 = rod[9];
                    }
                    f2 += rod[6] * f0;
                }
                energy->m34 = f2;
                Vec3f rot;
                rot.m_x = -(f28 + static_cast<float>(static_cast<double>(f2)));
                rot.m_y = rod[2];
                rot.m_z = rod[3];
                accesser->getPostureModule().setRot(&rot, 1);
            }
            fn_122_2799C(arg0, f30, accesser);
        }

        float f29b = accesser->getWorkManageModule().getFloat(0x21000004);
        float f30b = accesser->getWorkManageModule().getFloat(0x21000003);

        if (previousAngle != energy->m34) {
            Vec2f v;
            v.m_x = f29b;
            v.m_y = rod[3];
            fn_122_12CC4(&energy->m18, v);
            if (!accesser->getWorkManageModule().isFlag(0x22000000)) {
                float f28b = accesser->getWorkManageModule().getFloat(0x11000002);
                float f31 = accesser->getWorkManageModule().getFloat(0x11000003);
                float magnitude;
                if (energy->getVec2().m_x <= f29b) {
                    magnitude = f31;
                } else {
                    if (energy->getVec2().m_x >= f30b) {
                        magnitude = f28b;
                    } else {
                        Vec3f pos = gravity->fn_122_18F3C();
                        float f2 = (pos.m_z - f29b) / (f30b - f29b);
                        magnitude = f28b * f2 + f31 * (rod[9] - f2);
                    }
                }
                f31 = magnitude;
                Vec3f v2;
                v2.m_x = rod[3];
                v2.m_y = rod[3];
                v2.m_z = f31;
                fn_122_27980(gravity, &v2);
            }
        } else {
            fn_122_12CC4(&energy->m18, Speed(f30b, rod[3]));
            if (!accesser->getWorkManageModule().isFlag(0x22000000)) {
                float z4 = accesser->getWorkManageModule().getFloat(0x11000002);
                Vec3f v4;
                v4.m_x = rod[3];
                v4.m_y = rod[3];
                v4.m_z = z4;
                fn_122_27980(gravity, &v4);
            }
        }

        if (accesser->getWorkManageModule().getInt(0x20000000) == 0) {
            fn_122_12CC4(&energy->m10, Vec2f(rod[3], rod[3]));
            fn_122_12CC4(&energy->m18, Vec2f(rod[3], rod[3]));
            accesser->getWorkManageModule().decInt(0x20000000);
            float z7 = accesser->getWorkManageModule().getFloat(0x11000002);
            Vec3f v7;
            v7.m_x = rod[3];
            v7.m_y = rod[3];
            v7.m_z = z7;
            fn_122_27980(gravity, &v7);
            accesser->getWorkManageModule().onFlag(0x22000000);
        }
    }
}
