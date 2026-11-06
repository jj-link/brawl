#pragma opt_propagation off
#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

struct YoshiActivationDescriptor {
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

    YoshiActivationDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};

struct YoshiObject : StageObject {
    unsigned char body[0x1e94];
    const float* parameters;
};

struct YoshiEnergy {
    unsigned char prefix[5];
    u8 flags;
    unsigned char padding[2];
    Vec2f speed, acceleration, brake, speedLimit, speedMax;
};

extern "C" {
extern const unsigned char lbl_95_data_8EA8[], lbl_95_data_2C38[];
extern const float lbl_95_rodata_150[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const YoshiActivationDescriptor*);
void fn_8003DC64(Vec2f*, float, Vec2f*);
Vec2f fn_95_1B7C0(float, const Vec2f*);
void fn_95_DF08(Vec2f*, const Vec2f*);
float fn_95_A8B4(float);
Vec2f* fn_95_1473C(Vec2f*, float, float);

inline void setYoshiLimit(YoshiEnergy* energy, float x, float y) {
    Vec2f limit;
    fn_95_1473C(&limit, x, y);
    fn_95_DF08(&energy->speedLimit, &limit);
}

void fn_95_1B534(YoshiObject* object, unsigned int task, int value,
                 const Vec3f* position, float facing, float angle) {
    const float* constants = lbl_95_rodata_150;
    YoshiActivationDescriptor descriptor(task, value, *position, facing);
    fn_27_1D8370(object, &descriptor);

    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);
    soKineticModule& kinetic = object->m_moduleAccesser->getKineticModule();
    kinetic.changeKinetic(2, object->m_moduleAccesser);

    YoshiEnergy* energy = static_cast<YoshiEnergy*>(__dynamic_cast(
        kinetic.getEnergy(0), 0, lbl_95_data_8EA8, lbl_95_data_2C38,
        static_cast<short>(1)));

    Vec2f direction;
    direction.m_x = constants[0];
    direction.m_y = constants[2];
    fn_8003DC64(&direction, constants[4] * angle, &direction);

    Vec2f speed;
    Vec2f::copy(speed, fn_95_1B7C0(object->parameters[0], &direction));
    speed.m_x *= facing;

    Vec2f acceleration;
    Vec2f::copy(acceleration, fn_95_1B7C0(object->parameters[1], &direction));
    acceleration.m_x *= -facing;
    acceleration.m_y *= constants[1];

    fn_95_DF08(&energy->speed, &speed);
    fn_95_DF08(&energy->acceleration, &acceleration);

    float y = fn_95_A8B4(acceleration.m_y);
    float x = fn_95_A8B4(acceleration.m_x);
    setYoshiLimit(energy, x, y);
    fn_95_DF08(&energy->brake, &speed);
    fn_95_DF08(&energy->speedMax, &speed);

    energy->flags |= 0x80;
    object->updateNodeSRT();
}
}
