#include <so/so_module_accesser.h>

struct PikachuQuickAttackParameters {
    char reserved[0x48];
    float speedMultiplier;
};
struct PikachuQuickAttackParameterAccess {
    char reserved[8];
    PikachuQuickAttackParameters* parameters;
};

extern "C" {
extern const char lbl_98_data_600[], lbl_98_data_2F88[];
extern const char lbl_98_data_71F8[], lbl_98_data_769C[], lbl_98_data_7408[], lbl_98_data_24B0[];
extern const float lbl_98_rodata_20;
void* __dynamic_cast(void*, long, const void*, const void*, short);
PikachuQuickAttackParameterAccess* fn_98_9530(void*);
void fn_98_F0D8(Vec2f*, float);
Vec3f* fn_98_F5B0(Vec3f*, float, float, float);
}

// The shared kinetic declaration uses Vec2f, whose copy constructor changes
// MWCC's return handling. The original entry returns a POD pair in r3/r4.
struct QuickAttackSpeed { float m_x; float m_y; };
class QuickAttackKineticModuleView : public soNullable {
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
    virtual QuickAttackSpeed getSumSpeed(const unsigned short&);
};

#pragma always_inline on
#pragma inline_depth(8)
struct QuickAttackEnableFlag {
    unsigned char enabled : 1;
};


static inline void enableQuickAttackEnergy(soKineticEnergy* energy) {
    reinterpret_cast<QuickAttackEnableFlag*>(reinterpret_cast<unsigned char*>(energy) + 5)->enabled = 1;
}


extern "C" void fn_98_F5D0(void*, soModuleAccesser* accesser) {
    const int situation = accesser->getSituationModule().getKind();
    PikachuQuickAttackParameters* parameters = fn_98_9530(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_600, lbl_98_data_2F88, 1))->parameters;
    Vec2f appliedSpeed;
    Vec2f airborneSpeed;
    if (situation == 0) {
        unsigned short attributes = 1;
        QuickAttackSpeed speed = reinterpret_cast<QuickAttackKineticModuleView*>(
            &accesser->getKineticModule())->getSumSpeed(attributes);
        __memcpy(&appliedSpeed, &speed, sizeof(appliedSpeed));
        soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(3), 0, lbl_98_data_71F8, lbl_98_data_24B0, 1));
        fn_98_F0D8(&appliedSpeed, parameters->speedMultiplier);
        Vec2f horizontal(appliedSpeed.m_x, lbl_98_rodata_20);
        Vec3f stopRotation;
        stop->resetEnergy(7, &horizontal, fn_98_F5B0(&stopRotation,
            lbl_98_rodata_20, lbl_98_rodata_20, lbl_98_rodata_20), accesser);
        enableQuickAttackEnergy(stop);
        soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0, lbl_98_data_769C, lbl_98_data_24B0, 1));
        Vec2f vertical(lbl_98_rodata_20, appliedSpeed.m_y);
        Vec3f gravityRotation;
        gravity->resetEnergy(0, &vertical, fn_98_F5B0(&gravityRotation,
            lbl_98_rodata_20, lbl_98_rodata_20, lbl_98_rodata_20), accesser);
        enableQuickAttackEnergy(gravity);
        static_cast<soKineticEnergy*>(__dynamic_cast(accesser->getKineticModule().getEnergy(2),
            0, lbl_98_data_7408, lbl_98_data_24B0, 1))->clearSpeed();
        reinterpret_cast<signed char*>(accesser->getKineticModule().getEnergy(2))[5] &= ~0x80;
    } else {
        airborneSpeed.m_x = lbl_98_rodata_20;
        airborneSpeed.m_y = lbl_98_rodata_20;
        soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(3), 0, lbl_98_data_71F8, lbl_98_data_24B0, 1));
        fn_98_F0D8(&airborneSpeed, parameters->speedMultiplier);
        Vec2f horizontal(airborneSpeed.m_x, lbl_98_rodata_20);
        Vec3f stopRotation;
        stop->resetEnergy(7, &horizontal, fn_98_F5B0(&stopRotation,
            lbl_98_rodata_20, lbl_98_rodata_20, lbl_98_rodata_20), accesser);
        enableQuickAttackEnergy(stop);
        soKineticEnergy* gravity = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0, lbl_98_data_769C, lbl_98_data_24B0, 1));
        Vec2f vertical(lbl_98_rodata_20, airborneSpeed.m_y);
        Vec3f gravityRotation;
        gravity->resetEnergy(0, &vertical, fn_98_F5B0(&gravityRotation,
            lbl_98_rodata_20, lbl_98_rodata_20, lbl_98_rodata_20), accesser);
        enableQuickAttackEnergy(gravity);
        static_cast<soKineticEnergy*>(__dynamic_cast(accesser->getKineticModule().getEnergy(2),
            0, lbl_98_data_7408, lbl_98_data_24B0, 1))->clearSpeed();
        reinterpret_cast<signed char*>(accesser->getKineticModule().getEnergy(2))[5] &= ~0x80;
    }
    int count = accesser->getWorkManageModule().getInt(0x20000000);
    accesser->getWorkManageModule().setInt(count + 1, 0x20000000);
    accesser->getWorkManageModule().setInt(0, 0x20000004);
}
