#include <mo_fighter/ft_mario/ft_mario_initialize_types.h>
#pragma force_active on

struct PhysicsPrefix {
    unsigned char pad[8];
};

class Physics : public PhysicsPrefix {
public:
    virtual void a0() = 0;
    virtual void a1() = 0;
    virtual void a2() = 0;
    virtual void a3() = 0;
    virtual void initialize(unsigned int, int, int, int, int, int, bool, int) = 0;
    virtual void a5() = 0;
    virtual void a6() = 0;
    virtual void a7() = 0;
    virtual void a8() = 0;
    virtual void a9() = 0;
    virtual void a10() = 0;
    virtual void a11() = 0;
    virtual void a12() = 0;
    virtual void a13() = 0;
    virtual void a14() = 0;
    virtual void a15() = 0;
    virtual void a16() = 0;
    virtual void a17() = 0;
    virtual void a18() = 0;
    virtual void a19() = 0;
    virtual void a20() = 0;
    virtual void a21() = 0;
    virtual void a22() = 0;
    virtual void a23() = 0;
    virtual void a24() = 0;
    virtual void a25() = 0;
    virtual void a26() = 0;
    virtual void a27() = 0;
    virtual void a28() = 0;
    virtual void a29() = 0;
    virtual void a30() = 0;
    virtual void a31() = 0;
    virtual void a32() = 0;
    virtual void a33() = 0;
    virtual void a34() = 0;
    virtual void a35() = 0;
    virtual void a36() = 0;
    virtual void a37() = 0;
    virtual void extra() = 0;
    virtual void setMode(int) = 0;
    virtual void a39() = 0;
    virtual void a40() = 0;
    virtual void a41() = 0;
    virtual void a42() = 0;
    virtual void a43() = 0;
    virtual void a44() = 0;
    virtual void a45() = 0;
    virtual void a46() = 0;
    virtual void a47() = 0;
    virtual void a48() = 0;
    virtual void a49() = 0;
    virtual void a50() = 0;
    virtual void a51() = 0;
    virtual void setScale(float) = 0;
};

inline Physics& physics(const soModuleEnumeration* m) {
    return *static_cast<Physics*>(m->m_physicsModule);
}

inline soResourceModule& resourceModule(const soModuleEnumeration* m) {
    return *m->m_resourceModule;
}

inline soPostureModule& postureModule(const soModuleEnumeration* m) {
    return *m->m_postureModule;
}

extern "C" {
extern const float lbl_113_rodata_190;
extern int lbl_113_data_BAA8;

Vec3f* fn_113_A1D0(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const MarioMantleInitializeParam*);

void fn_113_2CF34(MarioMantleInitializeObject* object, int resource, int team,
                  int parameter, float facing, bool flag, int value) {
    Vec3f position;
    fn_113_A1D0(&position, lbl_113_rodata_190, lbl_113_rodata_190,
                lbl_113_rodata_190);

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

    object->accesser->getLinkModule().offModelConstraintFlag(2);
    object->accesser->getLinkModule().setAttribute(
        3, (soLinkConnection::Attribute)8, false);
    object->accesser->getLinkModule().setAttribute(
        3, (soLinkConnection::Attribute)8, false);

    const soModuleEnumeration* modules = object->accesser->m_enumerationStart;
    soResourceModule* res = &resourceModule(modules);
    Physics& initialPhysics = physics(modules);
    initialPhysics.initialize(res->getResourceIdAccesser()->getBinResId(), 0,
                              lbl_113_data_BAA8, lbl_113_data_BAA8, 1, 0,
                              false, -1);

    soModuleAccesser* accesser = object->accesser;
    accesser->getStatusModule().changeStatusForce(0, accesser);
    object->accesser->getWorkManageModule().setFlag(flag, 0x22000000);
    object->accesser->getWorkManageModule().setInt(value, 0x10000007);
    object->accesser->getWorkManageModule().setInt(11, 0x10000005);

    modules = object->accesser->m_enumerationStart;
    soPostureModule* posture = &postureModule(modules);
    Physics& phys = physics(modules);
    phys.setScale(posture->getScale());
    static_cast<Physics*>(object->accesser->m_enumerationStart->m_physicsModule)
        ->setMode(6);
}
}
