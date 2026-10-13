#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <ft/ft_manager.h>

// The concrete fighter energies are not yet declared by the shared headers.
// Keep their field views local; virtual operations use the existing base ABI.
struct CounterStopEnergy {
    soKineticEnergy base;
    Vec2f speed;
    Vec2f acceleration;
    Vec2f limit;
    Vec2f brake;
};
struct CounterGravityEnergy {
    soKineticEnergy base;
    Vec2f speed;
    float acceleration;
    float limit;
};
static_assert(sizeof(CounterStopEnergy) == 0x28, "Stop energy field layout");
static_assert(sizeof(CounterGravityEnergy) == 0x18, "Gravity energy field layout");

struct CounterProcess { void* vtable; };
struct CounterTypeInfo { const char* name; const void* bases; };
struct CounterBaseInfo { const void* type; int adjustment; const void* end; };
struct CounterRegistration { void* next; void* object; void* destructor; };
typedef void (*CounterMethod)();
struct CounterVtable {
    const CounterTypeInfo* type;
    unsigned long reserved;
    CounterMethod methods[14];
};

extern "C" {
extern const char lbl_106_data_534C[];
extern const char lbl_106_data_544C[];
extern const char lbl_106_data_EB4[];
extern const char lbl_106_data_54E0[];
extern CounterVtable lbl_106_data_5600;
extern CounterTypeInfo lbl_106_data_5670;
extern const float lbl_106_rodata_38[2];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __register_global_object(void*, void*, void*);
Vec3f* fn_106_77F4(Vec3f*, float, float, float);
void fn_27_89DAC(int, soModuleAccesser*);
void fn_106_C390(CounterStopEnergy*, const Vec2f*);
CounterProcess* fn_106_C98C(CounterProcess*);
}

static inline void enableCounterEnergy(soKineticEnergy* energy) {
    // soEnable's high bit occupies byte five in the common energy layout.
    reinterpret_cast<unsigned char*>(energy)[5] |= 0x80;
}

struct CounterSpeed { float m_x, m_y; };
// ABI view of the existing kinetic vtable. The shared owning vector/flag
// wrappers do not describe this slot's raw two-word return and mask address.
class CounterKineticModule : public soNullable {
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
    virtual CounterSpeed getSumSpeed(const unsigned short&);
};

extern "C" void fn_106_BFF0(CounterProcess*, soModuleAccesser* accesser) {
    CounterStopEnergy* stop = static_cast<CounterStopEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_106_data_534C, lbl_106_data_EB4, 1));
    CounterGravityEnergy* gravity = static_cast<CounterGravityEnergy*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_106_data_544C, lbl_106_data_EB4, 1));
    unsigned short attributes = 1;
    Vec2f speed;
    CounterSpeed sum = reinterpret_cast<CounterKineticModule*>(
        &accesser->getKineticModule())->getSumSpeed(attributes);
    __memcpy(&speed, &sum, sizeof(speed));
    float speedX = speed.m_x;

    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x115:
        if (accesser->getSituationModule().getKind() == 2) {
            speedX *= soValueAccesser::getConstantFloat(accesser, 0xfb0, 0);
            const float zero = lbl_106_rodata_38[0];
            Vec2f stopSpeed(speedX, zero);
            Vec3f stopRotation;
            stop->base.resetEnergy(6, &stopSpeed,
                fn_106_77F4(&stopRotation, zero, zero, zero), accesser);
            Vec2f brake(soValueAccesser::getConstantFloat(accesser, 0xfb1, 0), lbl_106_rodata_38[0]);
            fn_106_C390(stop, &brake);
            enableCounterEnergy(&stop->base);
            float gravityZero = lbl_106_rodata_38[0];
            Vec2f gravitySpeed(gravityZero, zero);
            Vec3f gravityRotation;
            gravity->base.resetEnergy(0, &gravitySpeed,
                fn_106_77F4(&gravityRotation, gravityZero, gravityZero, gravityZero), accesser);
            gravity->acceleration = -soValueAccesser::getConstantFloat(accesser, 0xfb2, 0);
            gravity->limit = soValueAccesser::getConstantFloat(accesser, 0xfb3, 0);
            enableCounterEnergy(&gravity->base);
            fn_27_89DAC(2, accesser);
            accesser->getWorkManageModule().setInt(2, 0x20000000);
        } else {
            accesser->getWorkManageModule().setInt(0, 0x20000000);
        }
        break;
    case 0x11d: {
        float power = accesser->getWorkManageModule().getFloat(0x21000004);
        float multiplier = soValueAccesser::getConstantFloat(accesser, 0xfb4, 0);
        float maximum = soValueAccesser::getConstantFloat(accesser, 0xfb7, 0);
        // The stored rule is a byte; the shared header's enum bitfield view
        // has different signed extraction semantics.
        if (reinterpret_cast<const unsigned char*>(g_ftManager)[0x68] == 1) {
            multiplier = soValueAccesser::getConstantFloat(accesser, 0xfb5, 0);
            maximum = soValueAccesser::getConstantFloat(accesser, 0xfb8, 0);
        }
        multiplier = power * multiplier;
        if (multiplier < soValueAccesser::getConstantFloat(accesser, 0xfb6, 0)) {
            multiplier = soValueAccesser::getConstantFloat(accesser, 0xfb6, 0);
        }
        if (multiplier > maximum) {
            multiplier = maximum;
        }
        accesser->getWorkManageModule().setFloat(multiplier, 0x21000004);
        break;
    }
    }
}

extern "C" void fn_106_C390(CounterStopEnergy* energy, const Vec2f* brake) {
    energy->brake.m_x = brake->m_x;
    energy->brake.m_y = brake->m_y;
}

extern "C" void fn_106_C3A4(CounterProcess*, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x115: {
        bool changed;
        {
            soWorkManageModule* work = &accesser->getWorkManageModule();
            soSituationModule* situation = &accesser->getSituationModule();
            int previous = work->getInt(0x20000000);
            int current = situation->getKind();
            changed = current != previous;
        }
        if (changed) {
            CounterStopEnergy& stop = *static_cast<CounterStopEnergy*>(__dynamic_cast(
                accesser->getKineticModule().getEnergy(3), 0,
                lbl_106_data_534C, lbl_106_data_EB4, 1));
            CounterGravityEnergy& gravity = *static_cast<CounterGravityEnergy*>(__dynamic_cast(
                accesser->getKineticModule().getEnergy(1), 0,
                lbl_106_data_544C, lbl_106_data_EB4, 1));
            unsigned short attributes = 1;
            Vec2f speed;
            CounterSpeed sum = reinterpret_cast<CounterKineticModule*>(
                &accesser->getKineticModule())->getSumSpeed(attributes);
            __memcpy(&speed, &sum, sizeof(speed));
            float speedX = speed.m_x;
            float speedY = speed.m_y;
            if (accesser->getSituationModule().getKind() == 2) {
                Vec2f stopSpeed(speedX, lbl_106_rodata_38[0]);
                Vec3f stopRotation;
                stop.base.resetEnergy(6, &stopSpeed,
                    fn_106_77F4(&stopRotation, lbl_106_rodata_38[0], lbl_106_rodata_38[0], lbl_106_rodata_38[0]), accesser);
                Vec2f brake(soValueAccesser::getConstantFloat(accesser, 0xfb1, 0), lbl_106_rodata_38[0]);
                fn_106_C390(&stop, &brake);
                enableCounterEnergy(&stop.base);
                Vec2f gravitySpeed(lbl_106_rodata_38[0], speedY);
                Vec3f gravityRotation;
                gravity.base.resetEnergy(0, &gravitySpeed,
                    fn_106_77F4(&gravityRotation, lbl_106_rodata_38[0], lbl_106_rodata_38[0], lbl_106_rodata_38[0]), accesser);
                gravity.acceleration = -soValueAccesser::getConstantFloat(accesser, 0xfb2, 0);
                gravity.limit = soValueAccesser::getConstantFloat(accesser, 0xfb3, 0);
                enableCounterEnergy(&gravity.base);
                fn_27_89DAC(2, accesser);
                accesser->getWorkManageModule().setInt(2, 0x20000000);
            } else {
                accesser->getWorkManageModule().setInt(0, 0x20000000);
            }
        }
        break;
    }
    case 0x11d:
        break;
    }
}

// The original stop callback intentionally performs no work.
extern "C" void fn_106_C674(CounterProcess*, soModuleAccesser*) { }

extern "C" void fn_106_C678(CounterProcess*, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x115:
        if (!accesser->getWorkManageModule().isFlag(0x22000012)) {
            if (accesser->getWorkManageModule().isFlag(0x22000011)) {
                accesser->getCollisionShieldModule().setStatus(0, 1, 1);
                accesser->getWorkManageModule().onFlag(0x22000012);
            }
        } else if (!accesser->getWorkManageModule().isFlag(0x22000011)) {
            accesser->getCollisionShieldModule().setStatus(0, 0, 1);
            accesser->getWorkManageModule().offFlag(0x22000012);
        }
        break;
    case 0x11d: {
        soCollisionAttackModule* attack = &accesser->getCollisionAttackModule();
        float power = accesser->getWorkManageModule().getFloat(0x21000004);
        if (!(power <= lbl_106_rodata_38[0])) {
            for (int index = 0; index < static_cast<int>(attack->getPartSize()); ++index) {
                if (attack->isAttack(index, false)) {
                    attack->setPower(index, static_cast<int>(power), false);
                }
            }
        }
        break;
    }
    }
}

extern "C" void fn_106_C890(CounterProcess*, soModuleAccesser* accesser, int) {
    if (accesser->getWorkManageModule().isFlag(0x22000012)) {
        accesser->getCollisionShieldModule().setStatus(0, 0, 1);
    }
}

extern "C" CounterProcess* fn_106_C904(CounterProcess* process, short deleting) {
    if (process != 0 && deleting > 0) {
        operator delete(process);
    }
    return process;
}

extern "C" {
CounterRegistration lbl_106_bss_1B8;
CounterProcess lbl_106_bss_1C4;
}

extern "C" void fn_106_C944() {
    fn_106_C98C(&lbl_106_bss_1C4);
    __register_global_object(&lbl_106_bss_1C4,
        reinterpret_cast<void*>(fn_106_C904), &lbl_106_bss_1B8);
}

#pragma dont_inline on
extern "C" CounterProcess* fn_106_C98C(CounterProcess* process) {
    process->vtable = &lbl_106_data_5600;
    return process;
}
#pragma dont_inline reset

// Preserve the module's existing callback and RTTI ABI, including inherited
// callbacks whose implementations belong to the preceding status-process unit.
extern "C" {
void fn_106_B53C();
void fn_106_B538();
void fn_106_B534();
void fn_106_B52C();
void fn_106_B528();
void fn_106_B520();
void fn_106_B51C();
void fn_106_B514();
CounterVtable lbl_106_data_5600 = {
    &lbl_106_data_5670, 0,
    { reinterpret_cast<CounterMethod>(fn_106_C904),
      reinterpret_cast<CounterMethod>(fn_106_BFF0),
      reinterpret_cast<CounterMethod>(fn_106_C890),
      reinterpret_cast<CounterMethod>(fn_106_C3A4),
      reinterpret_cast<CounterMethod>(fn_106_C674),
      fn_106_B53C, fn_106_B538,
      reinterpret_cast<CounterMethod>(fn_106_C678),
      fn_106_B534, fn_106_B52C, fn_106_B528, fn_106_B520,
      fn_106_B51C, fn_106_B514 }
};
char lbl_106_data_5640[] = "ftMarthStatusUniqProcessSpecialLw";
CounterBaseInfo lbl_106_data_5664 = { lbl_106_data_54E0, 0, 0 };
CounterTypeInfo lbl_106_data_5670 = { lbl_106_data_5640, &lbl_106_data_5664 };
const float lbl_106_rodata_38[2] = { 0.0f, 0.0f };
}

__declspec(section ".ctors") extern void (*const counterInitializer)() = fn_106_C944;

