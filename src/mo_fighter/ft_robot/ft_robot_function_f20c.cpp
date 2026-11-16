#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <so/effect/so_effect_module_impl.h>
#pragma force_active on

struct EnableBit {
    u8 on : 1;
    u8 rest : 7;
};

template <class T>
inline T* ptrAt(void* base, int off) {
    return *reinterpret_cast<T**>(static_cast<char*>(base) + off);
}

template <class T>
inline T& fieldAt(void* base, int off) {
    return *reinterpret_cast<T*>(static_cast<char*>(base) + off);
}

class Kinetic {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void* getEnergy(int);
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual Vec2f getSumSpeed(const s16*);
};

class Energy {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void resetEnergy(int, Vec2f*, Vec3f*, soModuleAccesser*);
};

class Obj14 {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
};

class Obj8 {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42(int);
};

class Obj64 {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual float s14(int);
    virtual void s15(float, int);
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20(int);
    virtual void s21(int);
};

class Obj88 {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13(int, int, Vec3f*, Vec3f*, int, int, int, float, int);
};

static inline Kinetic* kineticOf(soModuleAccesser* a) {
    return ptrAt<Kinetic>(ptrAt<void>(a, 0xD8), 0x7C);
}
static inline Obj14* obj14Of(soModuleAccesser* a) {
    return ptrAt<Obj14>(ptrAt<void>(a, 0xD8), 0x14);
}
static inline Obj64* obj64Of(soModuleAccesser* a) {
    return ptrAt<Obj64>(ptrAt<void>(a, 0xD8), 0x64);
}
static inline Obj8* obj8Of(soModuleAccesser* a) {
    return ptrAt<Obj8>(ptrAt<void>(a, 0xD8), 0x8);
}
static inline Obj88* obj88Of(soModuleAccesser* a) {
    return ptrAt<Obj88>(ptrAt<void>(a, 0xD8), 0x88);
}

static inline EnableBit& enableOf(void* p) {
    return *reinterpret_cast<EnableBit*>(static_cast<char*>(p) + 5);
}

static inline Vec2f* temp(const Vec2f& v) {
    return const_cast<Vec2f*>(&v);
}

extern "C" {
extern const float lbl_120_rodata_50[];
extern const char lbl_120_data_7028[];
extern const char lbl_120_data_6FE4[];
extern const char lbl_120_data_2208[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_120_DE7C(float);
Vec3f* fn_120_8718(Vec3f*, float, float, float);
void fn_120_BDBC(void*, Vec2f*);
}

extern "C" void fn_120_F20C(void* self, soModuleAccesser* accesser) {
    s16 one = 1;
    Energy* gravity = static_cast<Energy*>(__dynamic_cast(
        kineticOf(accesser)->getEnergy(1), 0, lbl_120_data_7028, lbl_120_data_2208, one));
    Energy* motion = static_cast<Energy*>(__dynamic_cast(
        kineticOf(accesser)->getEnergy(2), 0, lbl_120_data_6FE4, lbl_120_data_2208, one));
    obj64Of(accesser)->s20(0x22000012);
    s16 flag = one;
    Vec2f speed;
    Vec2f::copy(speed, kineticOf(accesser)->getSumSpeed(&flag));

    if (obj64Of(accesser)->s14(0x11000015) > 0.0f) {
        float limit = soValueAccesser::getConstantFloat(accesser, 0xFC3, 0);
        if (fn_120_DE7C(speed.m_y) > limit) {
            float sgnf = (float)((speed.m_y < 0.0f) ? -1 : 1);
            float c = soValueAccesser::getConstantFloat(accesser, 0xFC3, 0);
            speed.m_y = c * sgnf;
        }
        if (obj14Of(accesser)->s5() == 0) {
            speed.m_y += soValueAccesser::getConstantFloat(accesser, 0xFC0, 0);
        } else if (speed.m_y < 0.0f) {
            speed.m_y += soValueAccesser::getConstantFloat(accesser, 0xFC1, 0);
        }
        Vec3f z1;
        gravity->resetEnergy(0, temp(Vec2f(0.0f, speed.m_y)), fn_120_8718(&z1, 0.0f, 0.0f, 0.0f), accesser);
        enableOf(gravity).on = 1;

        enum K { MotionKind = 11 };
        K kind = MotionKind;
        float limitX = soValueAccesser::getConstantFloat(accesser, 0xFC2, 0);
        if (fn_120_DE7C(speed.m_x) > limitX) {
            float sgnx = (float)((speed.m_x < 0.0f) ? -1 : 1);
            float c = soValueAccesser::getConstantFloat(accesser, 0xFC2, 0);
            speed.m_x = c * sgnx;
        }
        Vec3f z2;
        motion->resetEnergy(kind, temp(Vec2f(speed.m_x, 0.0f)), fn_120_8718(&z2, 0.0f, 0.0f, 0.0f), accesser);

        fn_120_BDBC(reinterpret_cast<char*>(motion) + 8, temp(Vec2f(speed.m_x, 0.0f)));
        fieldAt<float>(motion, 0x40) = soValueAccesser::getConstantFloat(accesser, 0xFC7, 0);
        fn_120_BDBC(reinterpret_cast<char*>(motion) + 0x18,
                    temp(Vec2f(soValueAccesser::getConstantFloat(accesser, 0xFC8, 0), 0.0f)));
        enableOf(motion).on = 1;

        enableOf(kineticOf(accesser)->getEnergy(3)).on = 0;
        enableOf(kineticOf(accesser)->getEnergy(0)).on = 0;

        obj64Of(accesser)->s15(0.0f, 0x21000004);

        Vec3f a2;
        Vec3f a1;
        accesser->getEffectModule().reqFollow((EfID)0x24000A, 0x60,
            fn_120_8718(&a2, 0.0f, 0.0f, 0.0f),
            fn_120_8718(&a1, 0.0f, 0.0f, -90.0f),
            1.0f, false, 1, 0, -1);

        Vec3f a4;
        Vec3f a3;
        accesser->getEffectModule().reqFollow((EfID)0x240002, 0x60,
            fn_120_8718(&a4, 0.0f, 0.0f, 0.0f),
            fn_120_8718(&a3, 0.0f, 0.0f, -90.0f),
            1.0f, false, 1, 0, -1);
    } else {
        enum K { MotionKind = 11 };
        K kind = MotionKind;
        Vec3f z5;
        motion->resetEnergy(kind, temp(Vec2f(speed.m_x, 0.0f)), fn_120_8718(&z5, 0.0f, 0.0f, 0.0f), accesser);
        fn_120_BDBC(reinterpret_cast<char*>(motion) + 8, temp(Vec2f(speed.m_x, 0.0f)));
        Vec3f z7;
        gravity->resetEnergy(0, temp(Vec2f(0.0f, speed.m_y)), fn_120_8718(&z7, 0.0f, 0.0f, 0.0f), accesser);
        enableOf(gravity).on = 1;
    }

    obj8Of(accesser)->s42(2);
    obj64Of(accesser)->s21(0x12000040);
    obj64Of(accesser)->s21(0x12000041);
}
