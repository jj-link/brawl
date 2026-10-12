#include <wn/weapon.h>

// Prefix consumed by the shared weapon initializer. The reserved trailing
// bits retain their unspecified values, as in the other Ness descriptors.
struct NessYoyoActivationDescriptor {
    unsigned int taskId;
    unsigned int identifier0, identifier1, identifier2;
    int ownerId, teamId;
    int field18, field1C;
    Vec3f position;
    float facing;
    int parameter, field34, situation, status, field40, motion, field48;
    u8 active : 1;
    u8 field4C1 : 3;
    u8 field4C4 : 1;
    u8 field4C5 : 3;
    u8 field4D0 : 2;
    u8 reserved : 6;

    inline NessYoyoActivationDescriptor(unsigned int task, unsigned int resource,
                                      int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(resource), identifier1(resource), identifier2(resource),
          ownerId(-1), teamId(-1), field18(1), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};

extern "C" {
extern const float lbl_101_rodata_168[];
void fn_27_1D8370(void*, const NessYoyoActivationDescriptor*);

void fn_101_2368C(Weapon* object, unsigned int taskId, unsigned int resourceId,
                  int parameter, float facing, const Vec3f* position, bool normalDirection) {
    NessYoyoActivationDescriptor descriptor(taskId, resourceId, parameter, *position, facing);
    fn_27_1D8370(object, &descriptor);
    object->m_moduleAccesser->getCollisionAttackModule().setPowerMul(lbl_101_rodata_168[0]);
    object->m_moduleAccesser->getWorkManageModule().setFlag(normalDirection, 0x22000000);
    object->m_moduleAccesser->getWorkManageModule().onFlag(0x12000000);
    object->m_moduleAccesser->getKineticModule().changeKinetic(2, object->m_moduleAccesser);
    object->updateNodeSRT();
}
}
