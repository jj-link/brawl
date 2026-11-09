#pragma scheduling off
#include <so/so_module_accesser.h>
#pragma force_active on

struct Descriptor {
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
    Descriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};
struct Object {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char body[0x1f38];
    const float* parameters;
};
struct Energy {
    unsigned char prefix[8];
    Vec2f speed, acceleration, brake, speedLimit, speedMax;
};
extern "C" {
extern const unsigned char lbl_95_data_8EA8[], lbl_95_data_2C38[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const Descriptor*);
void fn_95_DF08(Vec2f*, const Vec2f*);
void fn_95_16E70(Object* object, unsigned int task, int value, const Vec3f* position, float facing) {
    Descriptor descriptor(task, value, *position, facing);
    fn_27_1D8370(object, &descriptor);
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
    Energy* energy = static_cast<Energy*>(__dynamic_cast(
        object->accesser->getKineticModule().getEnergy(0), 0, lbl_95_data_8EA8,
        lbl_95_data_2C38, static_cast<short>(1)));
    Vec2f speed;
    Vec2f acceleration;
    Vec2f brake;
    Vec2f::copy(brake, energy->speedMax);
    speed.m_x = object->parameters[0] * facing;
    speed.m_y = object->parameters[2];
    acceleration.m_x = object->parameters[1] * facing;
    acceleration.m_y = -object->parameters[4];
    brake.m_y = object->parameters[3];
    fn_95_DF08(&energy->speed, &speed);
    fn_95_DF08(&energy->acceleration, &acceleration);
    fn_95_DF08(&energy->brake, &brake);
    fn_95_DF08(&energy->speedMax, &brake);
}
}