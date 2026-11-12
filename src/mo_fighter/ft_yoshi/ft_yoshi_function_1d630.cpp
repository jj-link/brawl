#pragma opt_propagation off
#pragma scheduling off
#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

struct Param {
    unsigned task, a, b, c;
    int owner, team, f18, f1c;
    Vec3f pos;
    float lr;
    int value, f34, situation, status, f40, motion, f48;
    u8 bit0 : 1;
    u8 bits1 : 3;
    u8 bit4 : 1;
    u8 bits5 : 3;
    u8 bits6 : 2;
    u8 reserved : 6;
    Param(unsigned t, unsigned r, int v, const Vec3f& p, float f)
        : task(t), a(r), b(r), c(r), owner(-1), team(-1), f18(0), f1c(0),
          pos(p), lr(f), value(v), f34(0), situation(2), status(0x80),
          f40(0), motion(0x35f), f48(0), bit0(1), bits1(0),
          bit4(1), bits5(0), bits6(0) {}
};

struct YoshiObject : StageObject {
    unsigned char body[0x1f40];
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
extern const float lbl_95_rodata_168[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const Param*);
void fn_8003DC64(Vec2f*, float, Vec2f*);
void fn_95_DF08(Vec2f*, const Vec2f*);

void fn_95_1D630(YoshiObject* object, unsigned task, unsigned resource, int value,
                 const Vec3f* position, float facing, float angle) {
    const float* constants = lbl_95_rodata_168;
    Param descriptor(task, resource, value, *position, facing);
    fn_27_1D8370(object, &descriptor);

    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);
    soKineticModule& kinetic = object->m_moduleAccesser->getKineticModule();
    kinetic.changeKinetic(2, object->m_moduleAccesser);

    YoshiEnergy* energy = static_cast<YoshiEnergy*>(__dynamic_cast(
        kinetic.getEnergy(0), 0, lbl_95_data_8EA8, lbl_95_data_2C38, static_cast<short>(1)));

    Vec2f direction;
    Vec2f speed;
    Vec2f copy;
    Vec2f zeroAccel;
    Vec2f zeroLimit;
    Vec2f product;

    direction.m_x = constants[0];
    direction.m_y = constants[2];
    fn_8003DC64(&direction, constants[4] * angle, &direction);

    float param0 = object->parameters[0];
    product.m_x = direction.m_x * param0;
    product.m_y = direction.m_y * param0;
    Vec2f::copy(copy, product);
    Vec2f::copy(speed, product);
    speed.m_x *= facing;
    fn_95_DF08(&energy->speed, &speed);

    zeroAccel.m_x = constants[2];
    zeroAccel.m_y = constants[2];
    fn_95_DF08(&energy->acceleration, &zeroAccel);

    zeroLimit.m_x = constants[2];
    zeroLimit.m_y = constants[2];
    fn_95_DF08(&energy->speedLimit, &zeroLimit);

    fn_95_DF08(&energy->brake, &speed);
    fn_95_DF08(&energy->speedMax, &speed);

    energy->flags |= 0x80;
    object->updateNodeSRT();
}
}
