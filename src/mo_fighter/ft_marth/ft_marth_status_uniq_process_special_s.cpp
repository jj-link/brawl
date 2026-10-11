#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

// Concrete fighter-energy layouts are not exposed by the shared headers.
struct SideProcess { void* vtable; };
struct SideTypeInfo { const char* name; const void* bases; };
struct SideBaseInfo { const void* type; int adjustment; const void* end; };
struct SideRegistration { void* next; void* object; void* destructor; };
struct SideRttiBase { const void* type; int adjustment; };
struct SideGravityBases { SideRttiBase bases[4]; const void* end; };
struct SideMotionBases { SideRttiBase bases[5]; const void* end; };
struct SideEnableByte { unsigned char enabled : 1; };
// The original sum-speed entry returns a POD vector in r3/r4 and takes a
// reference to its attribute mask. Keep this view local until the common
// kinetic interface reflects that ABI; all preceding virtual slots retain
// their existing declarations and order.
struct SideSpeed { float m_x; float m_y; };
class SideKineticModuleView : public soNullable {
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
    virtual SideSpeed getSumSpeed(const unsigned short&);
};
typedef void (*SideMethod)();
struct SideVtable { const SideTypeInfo* type; unsigned long reserved; SideMethod methods[14]; };
extern "C" {
extern const char lbl_106_data_534C[], lbl_106_data_5390[], lbl_106_data_EB4[];
extern const char lbl_106_data_ECC[], lbl_106_data_1128[], lbl_106_data_18C4[];
extern SideTypeInfo lbl_106_data_544C;
extern SideVtable lbl_106_data_5454;
extern SideTypeInfo lbl_106_data_54C4, lbl_106_data_54E0;
extern const float lbl_106_rodata_20[2];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __register_global_object(void*, void*, void*);
Vec3f* fn_106_77F4(Vec3f*, float, float, float);
void fn_27_89DAC(int, soModuleAccesser*);
SideProcess* fn_106_B5C8(SideProcess*);
}
static inline void enableSideEnergy(soKineticEnergy* energy) {
    reinterpret_cast<SideEnableByte*>(reinterpret_cast<unsigned char*>(energy) + 5)->enabled = 1;
}
static inline void disableSideEnergy(soKineticEnergy* energy) {
    reinterpret_cast<SideEnableByte*>(reinterpret_cast<unsigned char*>(energy) + 5)->enabled = 0;
}
extern "C" void fn_106_A714(SideProcess*, soModuleAccesser* accesser) {
    soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0, lbl_106_data_534C, lbl_106_data_EB4, 1));
    soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0, &lbl_106_data_544C, lbl_106_data_EB4, 1));
    soKineticEnergy* motion = static_cast<soKineticEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(0), 0, lbl_106_data_5390, lbl_106_data_EB4, 1));
    disableSideEnergy(accesser->getKineticModule().getEnergy(0));
    unsigned short attributes = 1;
    Vec2f speed;
    SideSpeed sumSpeed = reinterpret_cast<SideKineticModuleView*>(&accesser->getKineticModule())->getSumSpeed(attributes);
    __memcpy(&speed, &sumSpeed, sizeof(speed));
    float speedX = speed.m_x;
    float speedY = speed.m_y;
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x113:
        if (accesser->getSituationModule().getKind() == 2) {
            speedX *= soValueAccesser::getConstantFloat(accesser, 0xfa2, 0);
            float gravitySpeed = speedY < lbl_106_rodata_20[0] ? lbl_106_rodata_20[0] :
                soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
            {
                Vec2f resetSpeed(speedX, lbl_106_rodata_20[0]);
                Vec3f resetRotation;
                stop->resetEnergy(6, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(stop);
            }
            {
                Vec2f resetSpeed(lbl_106_rodata_20[0], gravitySpeed);
                Vec3f resetRotation;
                gravity->resetEnergy(0, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(gravity);
            }
            fn_27_89DAC(2, accesser);
        } else {
            {
                Vec2f resetSpeed(lbl_106_rodata_20[0], lbl_106_rodata_20[0]);
                Vec3f resetRotation;
                motion->resetEnergy(3, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(motion);
            }
            fn_27_89DAC(3, accesser);
            fn_27_89DAC(1, accesser);
            fn_27_89DAC(2, accesser);
        }
        accesser->getWorkManageModule().setInt(accesser->getSituationModule().getKind(), 0x20000003);
        break;
    case 0x11a:
        if (accesser->getSituationModule().getKind() == 2) {
            {
                Vec2f resetSpeed(speedX, lbl_106_rodata_20[0]);
                Vec3f resetRotation;
                stop->resetEnergy(6, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(stop);
            }
            {
                Vec2f resetSpeed(lbl_106_rodata_20[0], speedY);
                Vec3f resetRotation;
                gravity->resetEnergy(0, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(gravity);
            }
            fn_27_89DAC(2, accesser);
        } else {
            fn_27_89DAC(3, accesser);
            fn_27_89DAC(1, accesser);
            fn_27_89DAC(2, accesser);
        }
        accesser->getWorkManageModule().setInt(accesser->getSituationModule().getKind(), 0x20000003);
        break;
    case 0x11b:
        if (accesser->getSituationModule().getKind() == 2) {
            {
                Vec2f resetSpeed(speedX, lbl_106_rodata_20[0]);
                Vec3f resetRotation;
                stop->resetEnergy(6, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(stop);
            }
            {
                Vec2f resetSpeed(lbl_106_rodata_20[0], speedY);
                Vec3f resetRotation;
                gravity->resetEnergy(0, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(gravity);
            }
        } else {
            {
                Vec2f resetSpeed(lbl_106_rodata_20[0], lbl_106_rodata_20[0]);
                Vec3f resetRotation;
                motion->resetEnergy(3, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(motion);
            }
            fn_27_89DAC(3, accesser);
            fn_27_89DAC(1, accesser);
        }
        accesser->getWorkManageModule().setInt(accesser->getSituationModule().getKind(), 0x20000003);
        break;
    case 0x11c:
        if (accesser->getSituationModule().getKind() == 2) {
            {
                Vec2f resetSpeed(speedX, lbl_106_rodata_20[0]);
                Vec3f resetRotation;
                stop->resetEnergy(6, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(stop);
            }
            {
                Vec2f resetSpeed(lbl_106_rodata_20[0], speedY);
                Vec3f resetRotation;
                gravity->resetEnergy(0, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(gravity);
            }
        } else {
            {
                Vec2f resetSpeed(lbl_106_rodata_20[0], lbl_106_rodata_20[0]);
                Vec3f resetRotation;
                motion->resetEnergy(3, &resetSpeed, fn_106_77F4(&resetRotation,
                    lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                enableSideEnergy(motion);
            }
            fn_27_89DAC(3, accesser);
            fn_27_89DAC(1, accesser);
        }
        accesser->getWorkManageModule().setInt(accesser->getSituationModule().getKind(), 0x20000003);
        break;
    }
    disableSideEnergy(accesser->getKineticModule().getEnergy(2));
}
extern "C" void fn_106_AEA4(SideProcess*, soModuleAccesser* accesser) {
    int situation = accesser->getSituationModule().getKind();
    int previousSituation = accesser->getWorkManageModule().getInt(0x20000003);
    unsigned short attributes = 1;
    Vec2f speed;
    SideSpeed sumSpeed = reinterpret_cast<SideKineticModuleView*>(&accesser->getKineticModule())->getSumSpeed(attributes);
    __memcpy(&speed, &sumSpeed, sizeof(speed));
    if (situation != previousSituation) {
        soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(3), 0, lbl_106_data_534C, lbl_106_data_EB4, 1));
        soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0, &lbl_106_data_544C, lbl_106_data_EB4, 1));
        soKineticEnergy* motion = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(0), 0, lbl_106_data_5390, lbl_106_data_EB4, 1));
        accesser->getWorkManageModule().setInt(accesser->getSituationModule().getKind(), 0x20000003);
        switch (accesser->getStatusModule().getStatusKind()) {
        case 0x113:
            if (accesser->getSituationModule().getKind() == 2) {
                {
                    Vec2f resetSpeed(speed.m_x, lbl_106_rodata_20[0]);
                    Vec3f resetRotation;
                    stop->resetEnergy(6, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(stop);
                }
                {
                    Vec2f resetSpeed(lbl_106_rodata_20[0], speed.m_y);
                    Vec3f resetRotation;
                    gravity->resetEnergy(0, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(gravity);
                }
            } else {
                {
                    Vec2f resetSpeed(lbl_106_rodata_20[0], lbl_106_rodata_20[0]);
                    Vec3f resetRotation;
                    motion->resetEnergy(3, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(motion);
                }
                fn_27_89DAC(3, accesser);
                fn_27_89DAC(1, accesser);
            }
            break;
        case 0x11a:
            if (accesser->getSituationModule().getKind() == 2) {
                {
                    Vec2f resetSpeed(speed.m_x, lbl_106_rodata_20[0]);
                    Vec3f resetRotation;
                    stop->resetEnergy(6, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(stop);
                }
                {
                    Vec2f resetSpeed(lbl_106_rodata_20[0], speed.m_y);
                    Vec3f resetRotation;
                    gravity->resetEnergy(0, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(gravity);
                }
                fn_27_89DAC(2, accesser);
            } else {
                fn_27_89DAC(3, accesser);
                fn_27_89DAC(1, accesser);
                fn_27_89DAC(2, accesser);
            }
            break;
        case 0x11b:
            if (accesser->getSituationModule().getKind() == 2) {
                {
                    Vec2f resetSpeed(speed.m_x, lbl_106_rodata_20[0]);
                    Vec3f resetRotation;
                    stop->resetEnergy(6, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(stop);
                }
                {
                    Vec2f resetSpeed(lbl_106_rodata_20[0], speed.m_y);
                    Vec3f resetRotation;
                    gravity->resetEnergy(0, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(gravity);
                }
            } else {
                {
                    Vec2f resetSpeed(lbl_106_rodata_20[0], lbl_106_rodata_20[0]);
                    Vec3f resetRotation;
                    motion->resetEnergy(3, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(motion);
                }
                fn_27_89DAC(3, accesser);
                fn_27_89DAC(1, accesser);
            }
            break;
        case 0x11c:
            if (accesser->getSituationModule().getKind() == 2) {
                {
                    Vec2f resetSpeed(speed.m_x, lbl_106_rodata_20[0]);
                    Vec3f resetRotation;
                    stop->resetEnergy(6, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(stop);
                }
                {
                    Vec2f resetSpeed(lbl_106_rodata_20[0], speed.m_y);
                    Vec3f resetRotation;
                    gravity->resetEnergy(0, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(gravity);
                }
            } else {
                {
                    Vec2f resetSpeed(lbl_106_rodata_20[0], lbl_106_rodata_20[0]);
                    Vec3f resetRotation;
                    motion->resetEnergy(3, &resetSpeed, fn_106_77F4(&resetRotation,
                        lbl_106_rodata_20[0], lbl_106_rodata_20[0], lbl_106_rodata_20[0]), accesser);
                    enableSideEnergy(motion);
                }
                fn_27_89DAC(3, accesser);
                fn_27_89DAC(1, accesser);
            }
            break;
        }
    }
}
// These inherited virtual callbacks intentionally perform no work, or return
// their original fixed capability values.
extern "C" void fn_106_B508() {}
extern "C" void fn_106_B50C() {}
extern "C" void fn_106_B510() {}
extern "C" bool fn_106_B514() { return true; }
extern "C" void fn_106_B51C() {}
extern "C" bool fn_106_B520() { return false; }
extern "C" void fn_106_B528() {}
extern "C" bool fn_106_B52C() { return false; }
extern "C" void fn_106_B534() {}
extern "C" void fn_106_B538() {}
extern "C" void fn_106_B53C() {}
extern "C" SideProcess* fn_106_B540(SideProcess* process, short deleting) {
    if (process != 0 && deleting > 0) operator delete(process);
    return process;
}
extern "C" {
SideRegistration lbl_106_bss_198;
SideProcess lbl_106_bss_1A4;
}
extern "C" void fn_106_B580() {
    fn_106_B5C8(&lbl_106_bss_1A4);
    __register_global_object(&lbl_106_bss_1A4,
        reinterpret_cast<void*>(fn_106_B540), &lbl_106_bss_198);
}
#pragma dont_inline on
extern "C" SideProcess* fn_106_B5C8(SideProcess* process) {
    process->vtable = &lbl_106_data_5454;
    return process;
}
#pragma dont_inline reset
extern "C" {
__declspec(align(4)) char lbl_106_data_5410[] = "ftKineticEnergyGravity";
SideGravityBases lbl_106_data_5428 = { {
    { lbl_106_data_ECC, 6 }, { lbl_106_data_1128, 5 },
    { lbl_106_data_18C4, 0 }, { lbl_106_data_EB4, 0 }
}, 0 };
SideTypeInfo lbl_106_data_544C = { lbl_106_data_5410, &lbl_106_data_5428 };
SideVtable lbl_106_data_5454 = { &lbl_106_data_54C4, 0,
    { reinterpret_cast<SideMethod>(fn_106_B540), reinterpret_cast<SideMethod>(fn_106_A714),
      fn_106_B510, reinterpret_cast<SideMethod>(fn_106_AEA4), fn_106_B508,
      fn_106_B53C, fn_106_B538, fn_106_B50C, fn_106_B534,
      reinterpret_cast<SideMethod>(fn_106_B52C), fn_106_B528,
      reinterpret_cast<SideMethod>(fn_106_B520), fn_106_B51C,
      reinterpret_cast<SideMethod>(fn_106_B514) } };
__declspec(align(4)) char lbl_106_data_5494[] = "ftMarthStatusUniqProcessSpecialS";
SideBaseInfo lbl_106_data_54B8 = { &lbl_106_data_54E0, 0, 0 };
SideTypeInfo lbl_106_data_54C4 = { lbl_106_data_5494, &lbl_106_data_54B8 };
__declspec(align(4)) char lbl_106_data_54CC[] = "soStatusUniqProcess";
SideTypeInfo lbl_106_data_54E0 = { lbl_106_data_54CC, 0 };
__declspec(align(4)) char lbl_106_data_54E8[] = "ftKineticEnergyController";
SideMotionBases lbl_106_data_5504 = { {
    { lbl_106_data_ECC, 6 }, { lbl_106_data_1128, 5 },
    { lbl_106_data_18C4, 0 }, { lbl_106_data_EB4, 0 }, { lbl_106_data_5390, 0 }
}, 0 };
SideTypeInfo lbl_106_data_5530 = { lbl_106_data_54E8, &lbl_106_data_5504 };
__declspec(align(4)) char lbl_106_data_5538[] = "ftKineticEnergyMotion";
SideMotionBases lbl_106_data_5550 = { {
    { lbl_106_data_ECC, 6 }, { lbl_106_data_1128, 5 },
    { lbl_106_data_18C4, 0 }, { lbl_106_data_EB4, 0 }, { lbl_106_data_5390, 0 }
}, 0 };
SideTypeInfo lbl_106_data_557C = { lbl_106_data_5538, &lbl_106_data_5550 };
extern const float lbl_106_rodata_20[2] = {0.0f, 0.0f};
}
// The module's constructor list must retain this externally invoked callback.
__declspec(section ".ctors") extern void (*const sideInitializer)() = fn_106_B580;
