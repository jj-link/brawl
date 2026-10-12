#include <so/so_module_accesser.h>

// Activation prefix consumed by the common weapon initializer. The unused
// low bits of the final byte retain their original unspecified values.
struct NessFireActivationDescriptor {
    unsigned int taskId;
    int identifier0, identifier1, identifier2;
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

    inline NessFireActivationDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};
struct NessFireInitializationOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char body[0x2348];
    const float* parameters;
};
struct NessFireNormalEnergy {
    unsigned char prefix[5];
    u8 flags;
    unsigned char padding[2];
    Vec2f speed, acceleration, brake, speedLimit, speedMax;
};
struct NessFireGravityEnergy {
    unsigned char prefix[5];
    u8 enabled : 1;
    u8 reserved : 7;
    unsigned char padding[2];
    float speed, acceleration, speedLimit;
};

extern "C" {
extern const unsigned char lbl_101_data_9840[], lbl_101_data_9310[], lbl_101_data_3890[];
extern const float lbl_101_rodata_A8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const NessFireActivationDescriptor*);
Vec2f* fn_101_FE5C(Vec2f*, const Vec2f*);
Vec3f* fn_101_1303C(Vec3f*, float, float, float);

void fn_101_15838(NessFireInitializationOwner* object, unsigned int taskId, int ownerId,
                  const Vec3f* position, const Vec2f* velocity, float facing, float angle) {
    NessFireActivationDescriptor descriptor(taskId, ownerId, *position, facing);
    fn_27_1D8370(object, &descriptor);
    const soModuleEnumeration* modules = object->accesser->m_enumerationStart;
    soPostureModule* posture = modules->m_postureModule;
    soKineticModule* kinetic = modules->m_kineticModule;
    soStatusModule* status = modules->m_statusModule;
    NessFireNormalEnergy* normal = static_cast<NessFireNormalEnergy*>(__dynamic_cast(
        kinetic->getEnergy(0), 0, lbl_101_data_9840, lbl_101_data_3890, static_cast<short>(1)));
    NessFireGravityEnergy* gravity = static_cast<NessFireGravityEnergy*>(__dynamic_cast(
        kinetic->getEnergy(2), 0, lbl_101_data_9310, lbl_101_data_3890, static_cast<short>(1)));
    fn_101_FE5C(&normal->speed, velocity);
    Vec2f zero(lbl_101_rodata_A8, lbl_101_rodata_A8);
    fn_101_FE5C(&normal->acceleration, &zero);
    fn_101_FE5C(&normal->brake, velocity);
    fn_101_FE5C(&normal->speedMax, velocity);
    normal->flags |= 0x80;
    gravity->speed = lbl_101_rodata_A8;
    gravity->acceleration = -object->parameters[3];
    gravity->speedLimit = object->parameters[4];
    gravity->enabled = false;
    Vec3f rotation;
    posture->setRot(fn_101_1303C(&rotation, angle, lbl_101_rodata_A8, lbl_101_rodata_A8), 0);
    status->changeStatusForce(0, object->accesser);
}
}
