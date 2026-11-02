#include <so/so_module_accesser.h>
#pragma force_active on

struct LucasActivationDescriptor {
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

    inline LucasActivationDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};
struct LucasInitializationOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char body[0xDD6C];
    const float* parameters;
};
struct LucasNormalEnergy {
    unsigned char prefix[5];
    u8 flags;
    unsigned char padding[2];
    Vec2f speed, acceleration, brake, speedLimit, speedMax;
};

extern "C" {
extern const unsigned char lbl_114_data_9140[], lbl_114_data_31DC[];
extern const float lbl_114_rodata_100, lbl_114_rodata_F8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const LucasActivationDescriptor*);
Vec2f* fn_114_F6BC(Vec2f*, const Vec2f*);
Vec2f* fn_114_18C84(Vec2f*, float, float);

void fn_114_18A44(LucasInitializationOwner* object, unsigned int taskId, int ownerId,
                  const Vec3f* position, float facing) {
    LucasActivationDescriptor descriptor(taskId, ownerId, *position, facing);
    fn_27_1D8370(object, &descriptor);
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
    object->accesser->getLinkModule().setAttribute(3, static_cast<soLinkConnection::Attribute>(4), true);
    object->accesser->getWorkManageModule().setFloat(lbl_114_rodata_100 * object->parameters[2], 0x21000000);
    LucasNormalEnergy* energy = static_cast<LucasNormalEnergy*>(__dynamic_cast(
        object->accesser->getKineticModule().getEnergy(0), 0, lbl_114_data_9140, lbl_114_data_31DC, static_cast<short>(1)));
    Vec2f speed(lbl_114_rodata_F8, object->parameters[1]);
    fn_114_F6BC(&energy->speed, &speed);
    Vec2f acceleration(lbl_114_rodata_F8, lbl_114_rodata_F8);
    fn_114_F6BC(&energy->acceleration, &acceleration);
    Vec2f limit(lbl_114_rodata_F8, lbl_114_rodata_F8);
    fn_114_F6BC(&energy->speedLimit, &limit);
    Vec2f maximum;
    fn_114_18C84(&maximum, object->parameters[1], object->parameters[1]);
    fn_114_F6BC(&energy->speedMax, &maximum);
    Vec2f brake;
    fn_114_18C84(&brake, object->parameters[1], object->parameters[1]);
    fn_114_F6BC(&energy->brake, &brake);
    energy->flags |= 0x80;
}
}
