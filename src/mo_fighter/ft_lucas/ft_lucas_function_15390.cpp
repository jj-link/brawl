#include <so/so_module_accesser.h>
#pragma force_active on

struct LucasFireDescriptor {
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

    inline LucasFireDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};

struct LucasFireObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char body[0x2348];
    const float* parameters;
};

struct LucasNormalEnergy {
    unsigned char prefix[5];
    u8 flags;
    unsigned char padding[2];
    Vec2f speed, acceleration, brake, speedLimit, speedMax;
};

struct LucasGravityEnergy {
    unsigned char prefix[5];
    u8 enabled : 1;
    u8 reserved : 7;
    unsigned char padding[2];
    float speed, acceleration, speedLimit;
};

extern "C" {
extern const unsigned char lbl_114_data_9140[], lbl_114_data_8C10[], lbl_114_data_31DC[];
extern const float lbl_114_rodata_C8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const LucasFireDescriptor*);
Vec2f* fn_114_F6BC(Vec2f*, const Vec2f*);
Vec3f* fn_114_12B94(Vec3f*, float, float, float);

void fn_114_15390(LucasFireObject* object, unsigned int taskId, int ownerId,
                  const Vec3f* position, const Vec2f* velocity, float facing, float angle) {
    LucasFireDescriptor descriptor(taskId, ownerId, *position, facing);
    fn_27_1D8370(object, &descriptor);
    soModuleAccesser* accesser = object->accesser;
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soPostureModule* posture = modules->m_postureModule;
    soKineticModule* kinetic = modules->m_kineticModule;
    soStatusModule* status = modules->m_statusModule;
    LucasNormalEnergy* normal = static_cast<LucasNormalEnergy*>(__dynamic_cast(
        kinetic->getEnergy(0), 0, lbl_114_data_9140, lbl_114_data_31DC, static_cast<short>(1)));
    LucasGravityEnergy* gravity = static_cast<LucasGravityEnergy*>(__dynamic_cast(
        kinetic->getEnergy(2), 0, lbl_114_data_8C10, lbl_114_data_31DC, static_cast<short>(1)));
    fn_114_F6BC(&normal->speed, velocity);
    Vec2f zero(lbl_114_rodata_C8, lbl_114_rodata_C8);
    fn_114_F6BC(&normal->acceleration, &zero);
    fn_114_F6BC(&normal->brake, velocity);
    fn_114_F6BC(&normal->speedMax, velocity);
    normal->flags |= 0x80;
    gravity->speed = lbl_114_rodata_C8;
    gravity->acceleration = -object->parameters[3];
    gravity->speedLimit = object->parameters[4];
    gravity->enabled = false;
    Vec3f rotation;
    posture->setRot(fn_114_12B94(&rotation, angle, lbl_114_rodata_C8, lbl_114_rodata_C8), 0);
    status->changeStatusForce(0, object->accesser);
}
}