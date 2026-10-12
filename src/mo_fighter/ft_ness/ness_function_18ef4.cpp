#include <so/so_module_accesser.h>

// Prefix passed to the shared weapon activation routine. Reserved bits are
// deliberately left unspecified, as in the other Ness activation descriptors.
struct NessThunderActivationDescriptor {
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

    inline NessThunderActivationDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};
struct NessThunderInitializationOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char body[0xDD6C];
    const float* parameters;
};
struct NessThunderNormalEnergy {
    unsigned char prefix[5];
    u8 flags;
    unsigned char padding[2];
    Vec2f speed, acceleration, brake, speedLimit, speedMax;
};
extern "C" {
extern const unsigned char lbl_101_data_9840[], lbl_101_data_3890[];
extern const float lbl_101_rodata_D8[2], lbl_101_rodata_E0[4];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const NessThunderActivationDescriptor*);
Vec2f* fn_101_FE5C(Vec2f*, const Vec2f*);
Vec2f* fn_101_19134(Vec2f*, float, float);

void fn_101_18EF4(NessThunderInitializationOwner* object, unsigned int taskId, int ownerId,
                   const Vec3f* position, float facing) {
    NessThunderActivationDescriptor descriptor(taskId, ownerId, *position, facing);
    fn_27_1D8370(object, &descriptor);
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
    object->accesser->getLinkModule().setAttribute(3, static_cast<soLinkConnection::Attribute>(4), true);
    object->accesser->getWorkManageModule().setFloat(lbl_101_rodata_E0[0] * object->parameters[2], 0x21000000);
    NessThunderNormalEnergy* energy = static_cast<NessThunderNormalEnergy*>(__dynamic_cast(
        object->accesser->getKineticModule().getEnergy(0), 0, lbl_101_data_9840, lbl_101_data_3890, static_cast<short>(1)));
    Vec2f speed(lbl_101_rodata_D8[0], object->parameters[1]);
    fn_101_FE5C(&energy->speed, &speed);
    Vec2f acceleration(lbl_101_rodata_D8[0], lbl_101_rodata_D8[0]);
    fn_101_FE5C(&energy->acceleration, &acceleration);
    Vec2f limit(lbl_101_rodata_D8[0], lbl_101_rodata_D8[0]);
    fn_101_FE5C(&energy->speedLimit, &limit);
    Vec2f maximum;
    fn_101_19134(&maximum, object->parameters[1], object->parameters[1]);
    fn_101_FE5C(&energy->speedMax, &maximum);
    Vec2f brake;
    fn_101_19134(&brake, object->parameters[1], object->parameters[1]);
    fn_101_FE5C(&energy->brake, &brake);
    energy->flags |= 0x80;
}

// This unit's original constant pools include the unused companion entries.
extern const float lbl_101_rodata_D8[2] = { 0.0f, 20.0f };
extern const float lbl_101_rodata_E0[4] = { 0.017453292f, 3.1415927f, 6.2831855f, 0.0f };
}
