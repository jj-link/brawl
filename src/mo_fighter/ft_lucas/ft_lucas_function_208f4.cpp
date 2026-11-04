#include <mo_fighter/ft_mario/ft_mario_initialize_types.h>
#pragma force_active on

struct LucasPhysicsPrefix { unsigned char prefix[8]; };
class LucasPhysics : public LucasPhysicsPrefix {
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
struct LucasInitializeObject : MarioMantleInitializeObject {
    unsigned char state[0x20cc - sizeof(MarioMantleInitializeObject)];
    const float* parameters;
};
inline LucasPhysics& physics(soModuleAccesser* a) {
    return *static_cast<LucasPhysics*>(a->m_enumerationStart->m_physicsModule);
}
inline LucasPhysics& physics(const soModuleEnumeration* modules) {
    return *static_cast<LucasPhysics*>(modules->m_physicsModule);
}
inline soResourceModule& resourceModule(const soModuleEnumeration* modules) {
    return *modules->m_resourceModule;
}
inline soPostureModule& postureModule(const soModuleEnumeration* modules) {
    return *modules->m_postureModule;
}
extern "C" {
extern const float lbl_114_rodata_168[6];
extern int lbl_114_data_AED8;
Vec3f* fn_114_12B94(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const MarioMantleInitializeParam*);

void fn_114_208F4(LucasInitializeObject* object, int resource, int team, int parameter, float facing, int activate, int alternate) {
    const float* data = lbl_114_rodata_168;
    Vec3f position;
    fn_114_12B94(&position, data[2], data[2], data[2]);
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
    p.flags.second = 1;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;
    fn_27_1D8370(object, &p);
    if (activate) {
        const soModuleEnumeration* initialModules = object->accesser->m_enumerationStart;
        soResourceModule* resourceModule = &::resourceModule(initialModules);
        LucasPhysics& phys = physics(initialModules);
        phys.initialize(resourceModule->getResourceIdAccesser()->getBinResId(), 0,
                        lbl_114_data_AED8, lbl_114_data_AED8, 1, 0, false, -1);
        const soModuleEnumeration* modules = object->accesser->m_enumerationStart;
        soPostureModule* posture = &postureModule(modules);
        LucasPhysics* scaledPhysics = static_cast<LucasPhysics*>(modules->m_physicsModule);
        scaledPhysics->setScale(posture->getScale());
        physics(object->accesser).setMode(6);
        object->accesser->getWorkManageModule().setFlag(false, 0x22000000);
        object->accesser->getWorkManageModule().setInt(11, 0x10000005);
        object->accesser->getWorkManageModule().setInt(3, 0x10000006);
        soModuleAccesser* a = object->accesser;
        a->getStatusModule().changeStatusForce(1, a);
    } else if (alternate) {
        object->accesser->getWorkManageModule().setInt(3, 0x20000000);
        object->accesser->getWorkManageModule().setFloat(data[4], 0x21000000);
        object->accesser->getWorkManageModule().setFloat(data[5], 0x21000001);
        object->accesser->getWorkManageModule().setFloat(object->parameters[2], 0x21000002);
    }
}
}
