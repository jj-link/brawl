#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct MarioSideProcess { void* vtable; };
struct MarioSideTypeInfo { const char* name; const void* bases; };
struct MarioSideTerminatedTypeInfo { const char* name; const void* bases; const void* end; };
struct MarioSideBaseInfo { const void* type; int adjustment; const void* end; };
struct MarioSideRegistration { void* next; void* object; void* destructor; };
struct MarioSideRttiBase { const void* type; int adjustment; };
struct MarioSideGravityBases { MarioSideRttiBase bases[4]; const void* end; };
struct MarioSideEnableByte { unsigned char enabled : 1; };
struct MarioSideSpeed { float m_x; float m_y; };
// The shared kinetic interface does not yet express the original POD return
// and attribute-reference ABI. This source-local view preserves every slot.
class MarioSideKineticModuleView : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy*, int, soKineticEnergy::AttributeFlag, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(soModuleAccesser*, soKineticEnergy::AttributeFlag);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual MarioSideSpeed getSumSpeed(const unsigned short&);
};
// Individual energy speeds likewise use the original two-register POD ABI.
class MarioSideEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual MarioSideSpeed getSpeed();
};
// Only removal is used here; the common module enumeration keeps the
// generate-article manager opaque. Unused entries retain their ABI slots.
class MarioSideArticleManager {
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
public:
    virtual void remove(int, int) = 0;
};
// Concrete fighter energy fields are absent from the common headers.
// These accessors expose only the scalar members touched by this process.
static inline float& gravitySpeedY(soKineticEnergy* energy) {
    return *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x0c);
}
static inline float& gravityAccelY(soKineticEnergy* energy) {
    return *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x10);
}
static inline float& gravityTerminalY(soKineticEnergy* energy) {
    return *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x1c);
}
static inline void enableMarioSideEnergy(soKineticEnergy* energy) {
    reinterpret_cast<MarioSideEnableByte*>(reinterpret_cast<unsigned char*>(energy) + 5)->enabled = 1;
}
typedef void (*MarioSideMethod)();
struct MarioSideVtable { const MarioSideTerminatedTypeInfo* type; unsigned long reserved; MarioSideMethod methods[14]; };
extern "C" {
extern const char lbl_91_data_765C[], lbl_91_data_28FC[], lbl_91_data_2914[];
extern const char lbl_91_data_2B8C[], lbl_91_data_34A8[], lbl_91_data_779C[];
extern MarioSideTypeInfo lbl_91_data_7864;
extern MarioSideVtable lbl_91_data_786C;
extern const float lbl_91_rodata_28[2] = { 0.0f, 0.0f };
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_89DAC(int, soModuleAccesser*);
Vec2f* fn_91_CC54(Vec2f*, const Vec2f*);
Vec3f* fn_91_E60C(Vec3f*, float, float, float);
void fn_91_E108(); void fn_91_E104(); void fn_91_E100();
void fn_91_E0FC(); void fn_91_E0F8(); void fn_91_E0F0();
void fn_91_E0EC(); void fn_91_E0E4(); void fn_91_E0E0(); void fn_91_E0D8();
MarioSideProcess* fn_91_E8A4(MarioSideProcess*);
}
extern "C" void fn_91_E3C4(MarioSideProcess*, soModuleAccesser* accesser) {
    int situation = accesser->getSituationModule().getKind();
    if (accesser->getMotionModule().getKind() != 0x1d0)
        accesser->getWorkManageModule().offFlag(0x22000012);
    else
        accesser->getWorkManageModule().onFlag(0x22000012);
    if (situation == 2) {
        unsigned short attributes = 1;
        Vec2f speed;
        MarioSideSpeed sumSpeed = reinterpret_cast<MarioSideKineticModuleView*>(&accesser->getKineticModule())->getSumSpeed(attributes);
        __memcpy(&speed, &sumSpeed, sizeof(speed));
        soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(3), 0, lbl_91_data_765C, lbl_91_data_28FC, 1));
        speed.m_x /= soValueAccesser::getConstantFloat(accesser, 0xfa8, 0);
        {
            Vec2f resetSpeed(speed.m_x, lbl_91_rodata_28[0]);
            Vec3f resetRotation;
            stop->resetEnergy(6, &resetSpeed, fn_91_E60C(&resetRotation,
                lbl_91_rodata_28[0], lbl_91_rodata_28[0], lbl_91_rodata_28[0]), accesser);
        }
        Vec2f limit(soValueAccesser::getConstantFloat(accesser, 0xfa9, 0), lbl_91_rodata_28[0]);
        fn_91_CC54(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(stop) + 0x20), &limit);
        enableMarioSideEnergy(stop);
        soKineticEnergy* gravity = accesser->getKineticModule().getEnergy(1);
        {
            Vec2f resetSpeed(lbl_91_rodata_28[0], speed.m_y);
            Vec3f resetRotation;
            gravity->resetEnergy(0, &resetSpeed, fn_91_E60C(&resetRotation,
                lbl_91_rodata_28[0], lbl_91_rodata_28[0], lbl_91_rodata_28[0]), accesser);
        }
        enableMarioSideEnergy(gravity);
        fn_27_89DAC(2, accesser);
        fn_27_89DAC(0, accesser);
    }
}
#pragma dont_inline on
extern "C" Vec3f* fn_91_E60C(Vec3f* vector, float x, float y, float z) {
    vector->m_x = x;
    vector->m_y = y;
    vector->m_z = z;
    return vector;
}
#pragma dont_inline reset
extern "C" void fn_91_E61C(MarioSideProcess*, soModuleAccesser* accesser) {
    if (accesser->getSituationModule().getKind() == 2) {
        soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0, &lbl_91_data_7864, lbl_91_data_28FC, 1));
        enableMarioSideEnergy(gravity);
        if (accesser->getWorkManageModule().isFlag(0x22000011) == true) {
            if (!accesser->getWorkManageModule().isFlag(0x22000012)) {
                accesser->getWorkManageModule().onFlag(0x22000012);
                MarioSideSpeed speed = reinterpret_cast<MarioSideEnergyView*>(gravity)->getSpeed();
                float speedY;
                if (!accesser->getWorkManageModule().isFlag(0x1200003d)) {
                    accesser->getWorkManageModule().onFlag(0x1200003d);
                    speedY = soValueAccesser::getConstantFloat(accesser, 0xfaa, 0);
                } else {
                    speedY = lbl_91_rodata_28[0];
                }
                gravitySpeedY(gravity) = speedY;
            }
            gravityAccelY(gravity) = -soValueAccesser::getConstantFloat(accesser, 0xfab, 0);
            gravityTerminalY(gravity) = soValueAccesser::getConstantFloat(accesser, 0xfac, 0);
        } else {
            gravityAccelY(gravity) = -soValueAccesser::getConstantFloat(accesser, 0xbcf, 0);
            gravityTerminalY(gravity) = soValueAccesser::getConstantFloat(accesser, 0xbd0, 0);
        }
    }
}
extern "C" void fn_91_E7FC(MarioSideProcess*, soModuleAccesser* accesser) {
    static_cast<MarioSideArticleManager*>(accesser->m_enumerationStart->m_generateArticleManageModule)->remove(0, 0);
}
extern "C" MarioSideProcess* fn_91_E81C(MarioSideProcess* process, short deleting) {
    if (process != 0 && deleting > 0) operator delete(process);
    return process;
}
extern "C" {
MarioSideRegistration lbl_91_bss_1F8;
MarioSideProcess lbl_91_bss_204;
}
extern "C" void fn_91_E85C() {
    fn_91_E8A4(&lbl_91_bss_204);
    __register_global_object(&lbl_91_bss_204, reinterpret_cast<void*>(fn_91_E81C), &lbl_91_bss_1F8);
}
#pragma dont_inline on
extern "C" MarioSideProcess* fn_91_E8A4(MarioSideProcess* process) {
    process->vtable = &lbl_91_data_786C;
    return process;
}
#pragma dont_inline reset
extern "C" {
__declspec(align(4)) char lbl_91_data_7828[] = "ftKineticEnergyGravity";
MarioSideGravityBases lbl_91_data_7840 = { {
    { lbl_91_data_2914, 6 }, { lbl_91_data_2B8C, 5 },
    { lbl_91_data_34A8, 0 }, { lbl_91_data_28FC, 0 }
}, 0 };
MarioSideTypeInfo lbl_91_data_7864 = { lbl_91_data_7828, &lbl_91_data_7840 };
extern MarioSideTerminatedTypeInfo lbl_91_data_78DC;
MarioSideVtable lbl_91_data_786C = { &lbl_91_data_78DC, 0, {
    reinterpret_cast<MarioSideMethod>(fn_91_E81C), reinterpret_cast<MarioSideMethod>(fn_91_E3C4),
    reinterpret_cast<MarioSideMethod>(fn_91_E7FC), reinterpret_cast<MarioSideMethod>(fn_91_E61C),
    fn_91_E108, fn_91_E104, fn_91_E100, fn_91_E0FC, fn_91_E0F8,
    fn_91_E0F0, fn_91_E0EC, fn_91_E0E4, fn_91_E0E0, fn_91_E0D8 } };
__declspec(align(4)) char lbl_91_data_78AC[] = "ftMarioStatusUniqProcessSpecialS";
MarioSideBaseInfo lbl_91_data_78D0 = { lbl_91_data_779C, 0, 0 };
MarioSideTerminatedTypeInfo lbl_91_data_78DC = { lbl_91_data_78AC, &lbl_91_data_78D0, 0 };
}
__declspec(section ".ctors") extern void (*const marioSideInitializer)() = fn_91_E85C;
