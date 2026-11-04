#include <ft/ft_common_data_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Accesser;
#define SLOT(n) virtual void unused##n();
struct WorkView {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20) SLOT(24)
    virtual void setInt(int, unsigned int);
    SLOT(32) SLOT(36) SLOT(40) SLOT(44) SLOT(48)
    SLOT(52) SLOT(56) SLOT(60) SLOT(64) SLOT(68) SLOT(72)
    virtual bool isFlag(unsigned int);
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};
struct MotionData {
    unsigned int value;
    float first, second;
    unsigned char byte0, byte1, byte2, byte3;
};
struct MotionView {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20) SLOT(24) SLOT(28)
    SLOT(32) SLOT(36) SLOT(40) SLOT(44) SLOT(48)
    virtual void setFrame(float);
    virtual float getFrame();
    SLOT(60) SLOT(64) SLOT(68) SLOT(72) SLOT(76)
    SLOT(80) SLOT(84) SLOT(88) SLOT(92) SLOT(96)
    SLOT(100) SLOT(104) SLOT(108) SLOT(112) SLOT(116) SLOT(120) SLOT(124)
    virtual void change(MotionData*);
};
struct EnergyView {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20) SLOT(24)
    virtual void reset(int, Vec2f*, Vec3f*, Accesser*);
};
struct KineticView {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20) SLOT(24) SLOT(28)
    virtual EnergyView* getEnergy(int);
    SLOT(36) SLOT(40) SLOT(44) SLOT(48) SLOT(52) SLOT(56)
    virtual Vec2f getSumSpeed(const unsigned short&);
};
struct VisibilityView {
    SLOT(8) SLOT(12)
    virtual void set(unsigned int, int);
};
struct EffectView {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20) SLOT(24) SLOT(28)
    SLOT(32) SLOT(36) SLOT(40) SLOT(44) SLOT(48) SLOT(52) SLOT(56) SLOT(60)
    SLOT(64) SLOT(68) SLOT(72) SLOT(76) SLOT(80) SLOT(84) SLOT(88) SLOT(92)
    SLOT(96) SLOT(100) SLOT(104) SLOT(108) SLOT(112) SLOT(116) SLOT(120)
    SLOT(124) SLOT(128) SLOT(132) SLOT(136) SLOT(140) SLOT(144) SLOT(148)
    SLOT(152) SLOT(156) SLOT(160) SLOT(164) SLOT(168)
    virtual void setA(bool, int);
    SLOT(176) SLOT(180) SLOT(184) SLOT(188) SLOT(192) SLOT(196) SLOT(200)
    virtual void setB(bool, int);
};
#undef SLOT
struct Modules {
    char pad0[8];
    MotionView* motion;
    char pad1[0x4c];
    VisibilityView* visibility;
    char pad2[8];
    WorkView* work;
    char pad3[0x14];
    KineticView* kinetic;
    char pad4[0x28];
    EffectView* effect;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
inline Vec2f* temporaryVector(const Vec2f& v) {
    return const_cast<Vec2f*>(&v);
}
extern "C" {
extern const char lbl_102_data_5EBC[];
extern const char lbl_102_data_5D8C[];
extern const char lbl_102_data_14F4[];
extern const float lbl_102_rodata_58;
extern const float lbl_102_rodata_5C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_15788(Accesser*);
void fn_102_156C0(Accesser*);
Vec3f* fn_102_C5B8(Vec3f*, float, float, float);
Vec2f* fn_102_C5AC(Vec2f*, float, float);
void fn_102_B024(void*, const Vec2f*);
void fn_102_CB90(MotionData*, unsigned int, float, float,
                  unsigned char, unsigned char, unsigned char, unsigned char);
}
static inline void apply(void* dst, const float* x, const float* y, const Vec2f& temporary) {
    fn_102_C5AC(const_cast<Vec2f*>(&temporary), *x, *y);
    fn_102_B024(dst, &temporary);
}
static inline float adjustedFrame(float offset, MotionView* motion) {
    return motion->getFrame() - offset;
}
extern "C" void fn_102_15A90(void*, Accesser* accesser) {
    WorkView* work = accesser->modules->work;
    if (work->isFlag(0x1200003D)) {
        fn_102_15788(accesser);
        work->offFlag(0x1200003D);
    }
    EffectView* effect = accesser->modules->effect;
    bool enabled = !work->isFlag(0x22000013);
    effect->setA(enabled, 0);
    effect->setB(enabled, 0xff);
    unsigned short flag = 1;
    Vec2f speed;
    __memcpy(&speed, &accesser->modules->kinetic->getSumSpeed(flag), sizeof(Vec2f));
    float* data = *reinterpret_cast<float**>(
        reinterpret_cast<char*>(g_ftCommonDataAccesser.getData(static_cast<ftKind>(0x30))) + 0x84);
    work->setInt(0, 0x20000000);
    fn_102_156C0(accesser);
    if (!work->isFlag(0x22000010)) {
        EnergyView* control = static_cast<EnergyView*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(2), 0,
            lbl_102_data_5EBC, lbl_102_data_14F4, 1));
        Vec3f rotation;
        control->reset(0, temporaryVector(Vec2f(speed.m_x, lbl_102_rodata_58)),
            fn_102_C5B8(&rotation, lbl_102_rodata_58,
                lbl_102_rodata_58, lbl_102_rodata_58), accesser);
        reinterpret_cast<float*>(control)[15] = data[6];
        apply(reinterpret_cast<char*>(control) + 0x18,
              &data[4], &reinterpret_cast<float*>(control)[7], Vec2f());
        apply(reinterpret_cast<char*>(control) + 0x28,
              &data[4], &reinterpret_cast<float*>(control)[11], Vec2f());
        reinterpret_cast<unsigned char*>(control)[5] |= 0x80;
    } else {
        EnergyView* motion = static_cast<EnergyView*>(__dynamic_cast(
            accesser->modules->kinetic->getEnergy(3), 0,
            lbl_102_data_5D8C, lbl_102_data_14F4, 1));
        Vec3f rotation;
        motion->reset(0, temporaryVector(Vec2f(speed.m_x, lbl_102_rodata_58)),
            fn_102_C5B8(&rotation, lbl_102_rodata_58,
                lbl_102_rodata_58, lbl_102_rodata_58), accesser);
        reinterpret_cast<unsigned char*>(motion)[5] |= 0x80;
    }
    if (work->isFlag(0x22000015)) {
        MotionData change;
        fn_102_CB90(&change, 0x1D4, lbl_102_rodata_58, lbl_102_rodata_5C, 0, 0, 0, 0);
        accesser->modules->motion->change(&change);
        work->offFlag(0x22000015);
    } else if (work->isFlag(0x22000016)) {
        float frame;
        if (!work->isFlag(0x1200003F)) {
            work->onFlag(0x1200003F);
            frame = adjustedFrame(static_cast<float>(soValueAccesser::getConstantInt(
                reinterpret_cast<soModuleAccesser*>(accesser), 0x5DC8, 0)),
                accesser->modules->motion);
        } else {
            frame = accesser->modules->motion->getFrame();
        }
        MotionData change;
        fn_102_CB90(&change, 0x1D4, lbl_102_rodata_5C, lbl_102_rodata_5C, 0, 0, 0, 0);
        accesser->modules->motion->change(&change);
        accesser->modules->motion->setFrame(frame);
        work->offFlag(0x22000016);
    } else {
        MotionData change;
        fn_102_CB90(&change, 0x1D4, lbl_102_rodata_58, lbl_102_rodata_5C, 0, 0, 0, 0);
        accesser->modules->motion->change(&change);
    }
    if (work->isFlag(0x22000013)) {
        accesser->modules->visibility->set(1, 1);
        return;
    }
    accesser->modules->visibility->set(1, 0);
}
