#include <mo_fighter/ft_mario/ft_mario_initialize_types.h>
#pragma force_active on

class ZeldaWork {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void setFlag(int, unsigned long) = 0;
};

struct PhysicsPrefix { unsigned char prefix[8]; };
class ZeldaPhysics : public PhysicsPrefix {
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
struct ObjectPrefix { unsigned char prefix[0x3c]; };
class ZeldaObject : public ObjectPrefix {
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
    virtual void finish() = 0;
    unsigned char pad[0x20];
    soModuleAccesser* accesser;
};

inline ZeldaPhysics& physics(const soModuleEnumeration* modules) {
    return *static_cast<ZeldaPhysics*>(modules->m_physicsModule);
}
inline ZeldaPhysics& physics(soModuleAccesser* accesser) {
    return physics(accesser->m_enumerationStart);
}
inline soResourceModule& resourceModule(const soModuleEnumeration* modules) {
    return *modules->m_resourceModule;
}
inline soPostureModule& postureModule(const soModuleEnumeration* modules) {
    return *modules->m_postureModule;
}

extern "C" {
extern const float lbl_104_rodata_1A8;
extern const float lbl_104_rodata_1A0;
extern int lbl_104_data_CB60;
Vec3f* fn_104_121E8(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const MarioMantleInitializeParam*);
void fn_27_1DA698(void*, int, int, int);

void fn_104_23F80(ZeldaObject* object, int resource, int team, int parameter, float facing, int activate) {
    Vec3f position;
    fn_104_121E8(&position, lbl_104_rodata_1A8, lbl_104_rodata_1A8, lbl_104_rodata_1A8);
    MarioMantleInitializeParam p;
    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;
    __memcpy(&p.position, &position, sizeof(position));
    p.facing = facing;
    p.parameter = parameter;
    p.reserved2 = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved3 = 0;
    p.motion = 0x35f;
    p.reserved4 = 0;
    p.flags.first = 1;
    p.flags.second = 0;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;
    fn_27_1D8370(object, &p);
    if (activate == 0) {
        fn_27_1DA698(object, -1, -1, -1);
        const soModuleEnumeration* initialModules = object->accesser->m_enumerationStart;
        soResourceModule* resourceModule = &::resourceModule(initialModules);
        ZeldaPhysics& phys = physics(initialModules);
        phys.initialize(resourceModule->getResourceIdAccesser()->getBinResId(), 0,
                        lbl_104_data_CB60, lbl_104_data_CB60, 1, 0, false, -1);
        const soModuleEnumeration* modules = object->accesser->m_enumerationStart;
        soPostureModule* posture = &postureModule(modules);
        physics(modules).setScale(posture->getScale());
        physics(object->accesser).setMode(6);
        object->accesser->getWorkManageModule().setInt(10, 0x10000005);
        object->accesser->getPostureModule().setOwnerScale(lbl_104_rodata_1A0);
        object->finish();
    }
    reinterpret_cast<ZeldaWork*>(&object->accesser->getWorkManageModule())->setFlag(activate, 0x12000003);
}
}
