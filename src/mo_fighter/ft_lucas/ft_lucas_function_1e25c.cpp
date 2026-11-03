#include <so/so_module_accesser.h>
#pragma force_active on

struct LucasHeadActivationDescriptor {
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
    inline LucasHeadActivationDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) { field4C4 = 0; }
};
struct LucasHeadInitializationOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char body[0x1B74];
    const float* parameters;
};
struct LucasHeadNormalEnergy {
    unsigned char prefix[5];
    u8 flags;
    unsigned char padding[2];
    Vec2f speed, acceleration, brake, speedLimit, speedMax;
};
struct LucasHeadVector : Vec2f {
    LucasHeadVector() {}
    LucasHeadVector(const LucasHeadVector& other) { __memcpy(this, &other, sizeof(*this)); }
    LucasHeadVector& operator=(const LucasHeadVector& other) {
        __memcpy(this, &other, sizeof(*this));
        return *this;
    }
};
extern "C" {
extern const unsigned char lbl_114_data_9140[], lbl_114_data_31DC[];
extern const float lbl_114_rodata_150[6];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const LucasHeadActivationDescriptor*);
Vec2f* fn_114_F6BC(Vec2f*, const Vec2f*);
void fn_114_1E530(const Vec2f*, float, Vec2f*);
void fn_8003DC64(Vec2f*, float, Vec2f*);

inline LucasHeadVector scaleHeadVector(const Vec2f& input, const float& factor) {
    LucasHeadVector result;
    fn_114_1E530(&input, factor, &result);
    return result;
}
void fn_114_1E25C(LucasHeadInitializationOwner* object, unsigned int taskId, int ownerId,
                   const Vec3f* position, float angle) {
    const float* constants = lbl_114_rodata_150;
    float facing = angle > constants[2] ? constants[0] : constants[1];
    LucasHeadActivationDescriptor descriptor(taskId, ownerId, *position, facing);
    fn_27_1D8370(object, &descriptor);
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
    Vec2f direction;
    direction.m_x = constants[2];
    direction.m_y = constants[1];
    fn_8003DC64(&direction, angle, &direction);
    LucasHeadVector speed;
    LucasHeadVector acceleration;
    LucasHeadVector initialSpeed;
    float speedFactor = object->parameters[0];
    initialSpeed = scaleHeadVector(direction, speedFactor);
    speed = initialSpeed;
    LucasHeadVector initialAcceleration;
    float accelerationFactor = object->parameters[1];
    initialAcceleration = scaleHeadVector(direction, accelerationFactor);
    acceleration = initialAcceleration;
    soKineticModule* kinetic = &object->accesser->getKineticModule();
    LucasHeadNormalEnergy* energy = static_cast<LucasHeadNormalEnergy*>(__dynamic_cast(
        kinetic->getEnergy(0), 0, lbl_114_data_9140, lbl_114_data_31DC, static_cast<short>(1)));
    kinetic->changeKinetic(2, object->accesser);
    fn_114_F6BC(&energy->speed, &speed);
    fn_114_F6BC(&energy->acceleration, &acceleration);
    LucasHeadVector brake;
    brake = scaleHeadVector(speed, constants[4]);
    fn_114_F6BC(&energy->brake, &brake);
    LucasHeadVector maximum;
    maximum = scaleHeadVector(speed, constants[4]);
    fn_114_F6BC(&energy->speedMax, &maximum);
    energy->flags |= 0x80;
    soPostureModule* posture = &object->accesser->getPostureModule();
    Vec3f rotation;
    rotation.m_x = constants[5] * (angle * -facing);
    rotation.m_y = constants[2];
    rotation.m_z = constants[2];
    posture->setRot(&rotation, 0);
}
}