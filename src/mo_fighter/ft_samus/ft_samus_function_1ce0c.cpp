#include <so/so_module_accesser.h>
#include <memory.h>
#include <mo_fighter/ft_mario/ft_mario_initialize_types.h>
#pragma force_active on

struct SamusValue {
    unsigned char pad[8];
    float value;
};

struct SamusInitializeObject : MarioMantleInitializeObject {
    unsigned char state[0x1d18 - sizeof(MarioMantleInitializeObject)];
    SamusValue* value;
};

struct SamusPhysicsPrefix {
    unsigned char prefix[8];
};

class SamusPhysics : public SamusPhysicsPrefix {
public:
    virtual void slot_8() = 0;
    virtual void slot_c() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void initialize(unsigned int, int, int, int, int, int, bool, int) = 0;
    virtual void slot_1c() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2c() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3c() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4c() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5c() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6c() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7c() = 0;
    virtual void slot_80() = 0;
    virtual void slot_84() = 0;
    virtual void slot_88() = 0;
    virtual void slot_8c() = 0;
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9c() = 0;
    virtual void slot_a0() = 0;
    virtual void setMode(int) = 0;
    virtual void slot_a8() = 0;
    virtual void slot_ac() = 0;
    virtual void slot_b0() = 0;
    virtual void slot_b4() = 0;
    virtual void slot_b8() = 0;
    virtual void slot_bc() = 0;
    virtual void slot_c0() = 0;
    virtual void slot_c4() = 0;
    virtual void slot_c8() = 0;
    virtual void slot_cc() = 0;
    virtual void slot_d0() = 0;
    virtual void slot_d4() = 0;
    virtual void slot_d8() = 0;
    virtual void setScale(float) = 0;
};

class SamusKinetic {
public:
    virtual void slot_8() = 0;
    virtual void slot_c() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1c() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2c() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3c() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4c() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void changeKinetic(int, soModuleAccesser*) = 0;
};

class SamusCollisionAttack {
public:
    virtual void slot_8() = 0;
    virtual void slot_c() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1c() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2c() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3c() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4c() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5c() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6c() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7c() = 0;
    virtual void slot_80() = 0;
    virtual void slot_84() = 0;
    virtual void slot_88() = 0;
    virtual void slot_8c() = 0;
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9c() = 0;
    virtual void slot_a0() = 0;
    virtual void slot_a4() = 0;
    virtual void slot_a8() = 0;
    virtual void slot_ac() = 0;
    virtual void slot_b0() = 0;
    virtual void slot_b4() = 0;
    virtual void slot_b8() = 0;
    virtual void slot_bc() = 0;
    virtual void slot_c0() = 0;
    virtual void slot_c4() = 0;
    virtual void slot_c8() = 0;
    virtual void slot_cc() = 0;
    virtual void slot_d0() = 0;
    virtual void slot_d4() = 0;
    virtual void slot_d8() = 0;
    virtual void slot_dc() = 0;
    virtual void slot_e0() = 0;
    virtual void slot_e4() = 0;
    virtual void slot_e8() = 0;
    virtual void slot_ec() = 0;
    virtual void slot_f0(int, int) = 0;
};

struct SamusScaleModules {
    soPostureModule* posture;
    SamusPhysics* physics;
};

inline SamusPhysics& samusPhysics(const soModuleEnumeration* modules) {
    return *static_cast<SamusPhysics*>(modules->m_physicsModule);
}

inline soResourceModule& samusResourceModule(
    const soModuleEnumeration* modules) {
    return *modules->m_resourceModule;
}

inline soPostureModule& samusPostureModule(
    const soModuleEnumeration* modules) {
    return *modules->m_postureModule;
}

inline void samusSetScale(SamusPhysics* physics, soPostureModule* posture) {
    physics->setScale(posture->getScale());
}

extern "C" {
extern const float lbl_94_rodata_88[];
extern int lbl_94_data_C858;
void fn_27_1D8370(void*, const MarioMantleInitializeParam*);

void fn_94_1CE0C(SamusInitializeObject* object, int resource, int team,
                 int parameter, const MarioMantleInitializeVector* position,
                 float facing, int activate, int alternate, int index) {
    const float* data = lbl_94_rodata_88;
    MarioMantleInitializeParam p;
    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;
    __memcpy(&p.position, position, sizeof(MarioMantleInitializeVector));
    p.facing = facing;
    p.parameter = parameter;
    p.reserved2 = 0;
    p.reserved3 = 0;
    p.motion = 0x35f;
    p.reserved4 = 0;
    p.flags.first = 1;
    p.flags.second = 1;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    ((unsigned char*)&p.flags)[1] =
        (((unsigned int)((unsigned char*)&p.flags)[1]) & 0xffffff3f) | 0x80;
    p.situation = 3;
    p.status = 0xff;
    fn_27_1D8370(object, &p);

    reinterpret_cast<SamusKinetic*>(
        object->accesser->m_enumerationStart->m_kineticModule)
        ->changeKinetic(2, object->accesser);
    object->accesser->getWorkManageModule().setFloat(data[2], 0x11000001);
    object->accesser->getWorkManageModule().setInt(index, 0x10000007);

    if (index != -1) {
        reinterpret_cast<SamusCollisionAttack*>(
            object->accesser->m_enumerationStart->m_collisionAttackModule)
            ->slot_f0(0, index);
    }

    if (activate) {
        const soModuleEnumeration* initialModules =
            object->accesser->m_enumerationStart;
        soResourceModule& resourceModule =
            samusResourceModule(initialModules);
        SamusPhysics& physics = samusPhysics(initialModules);
        int dataValue = lbl_94_data_C858;
        unsigned int binResId =
            resourceModule.getResourceIdAccesser()->getBinResId();
        physics.initialize(binResId, 0, dataValue, dataValue, 1, 0, false, -1);

        const soModuleEnumeration* modules =
            object->accesser->m_enumerationStart;
        soPostureModule* posture = &samusPostureModule(modules);
        SamusPhysics* scaledPhysics =
            static_cast<SamusPhysics*>(modules->m_physicsModule);
        scaledPhysics->setScale(posture->getScale());
        static_cast<SamusPhysics*>(
            object->accesser->m_enumerationStart->m_physicsModule)->setMode(6);
        object->accesser->getWorkManageModule().setFlag(false, 0x22000000);
        object->accesser->getWorkManageModule().setInt(10, 0x10000005);
        object->accesser->getWorkManageModule().setInt(2, 0x10000006);
        soModuleAccesser* accesser = object->accesser;
        accesser->getStatusModule().changeStatusForce(1, accesser);
    } else if (alternate) {
        object->accesser->getWorkManageModule().setInt(10, 0x20000000);
        object->accesser->getWorkManageModule().setFloat(data[3], 0x21000000);
        object->accesser->getWorkManageModule().setFloat(data[4], 0x21000001);
        object->accesser->getWorkManageModule().setFloat(
            object->value->value, 0x21000002);
    }

    object->accesser->getWorkManageModule().setInt(-1, 0x10000009);
}
}
