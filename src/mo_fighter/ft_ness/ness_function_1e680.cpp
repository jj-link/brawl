#include <so/so_module_accesser.h>

// Common weapon activation prefix; unused flag bits remain unspecified.
struct NessHeadActivationDescriptor {
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
    inline NessHeadActivationDescriptor(unsigned int task, int value, const Vec3f& pos, float lr)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(lr),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), field4C1(0), field4C4(1),
          field4C5(0), field4D0(0) { field4C4 = 0; }
};
struct NessHeadInitializationOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char body[0x1B74];
    const float* parameters;
};
struct NessHeadNormalEnergy {
    unsigned char prefix[5];
    u8 flags;
    unsigned char padding[2];
    Vec2f speed, acceleration, brake, speedLimit, speedMax;
};
// Nontrivial vector copies preserve the common vector helper's result ABI.
struct NessHeadVector : Vec2f {
    NessHeadVector() {}
    NessHeadVector(const NessHeadVector& other) { __memcpy(this, &other, sizeof(*this)); }
    NessHeadVector& operator=(const NessHeadVector& other) {
        __memcpy(this, &other, sizeof(*this));
        return *this;
    }
};
extern "C" {
extern const unsigned char lbl_101_data_9840[], lbl_101_data_3890[];
extern const float lbl_101_rodata_130[6];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const NessHeadActivationDescriptor*);
Vec2f* fn_101_FE5C(Vec2f*, const Vec2f*);
void fn_101_1E954(const Vec2f*, float, Vec2f*);
void fn_8003DC64(Vec2f*, float, Vec2f*);

inline NessHeadVector scaleHeadVector(const Vec2f& input, const float& factor) {
    NessHeadVector result;
    fn_101_1E954(&input, factor, &result);
    return result;
}
void fn_101_1E680(NessHeadInitializationOwner* object, unsigned int taskId, int ownerId,
                   const Vec3f* position, float angle) {
    const float* constants = lbl_101_rodata_130;
    float facing = angle > constants[2] ? constants[0] : constants[1];
    NessHeadActivationDescriptor descriptor(taskId, ownerId, *position, facing);
    fn_27_1D8370(object, &descriptor);
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
    Vec2f direction;
    direction.m_x = constants[2];
    direction.m_y = constants[1];
    fn_8003DC64(&direction, angle, &direction);
    NessHeadVector speed;
    NessHeadVector acceleration;
    NessHeadVector initialSpeed;
    float speedFactor = object->parameters[0];
    initialSpeed = scaleHeadVector(direction, speedFactor);
    speed = initialSpeed;
    NessHeadVector initialAcceleration;
    float accelerationFactor = object->parameters[1];
    initialAcceleration = scaleHeadVector(direction, accelerationFactor);
    acceleration = initialAcceleration;
    soKineticModule* kinetic = &object->accesser->getKineticModule();
    NessHeadNormalEnergy* energy = static_cast<NessHeadNormalEnergy*>(__dynamic_cast(
        kinetic->getEnergy(0), 0, lbl_101_data_9840, lbl_101_data_3890, static_cast<short>(1)));
    kinetic->changeKinetic(2, object->accesser);
    fn_101_FE5C(&energy->speed, &speed);
    fn_101_FE5C(&energy->acceleration, &acceleration);
    NessHeadVector brake;
    brake = scaleHeadVector(speed, constants[4]);
    fn_101_FE5C(&energy->brake, &brake);
    NessHeadVector maximum;
    maximum = scaleHeadVector(speed, constants[4]);
    fn_101_FE5C(&energy->speedMax, &maximum);
    energy->flags |= 0x80;
    soPostureModule* posture = &object->accesser->getPostureModule();
    Vec3f rotation;
    rotation.m_x = constants[5] * (angle * -facing);
    rotation.m_y = constants[2];
    rotation.m_z = constants[2];
    posture->setRot(&rotation, 0);
}
}
