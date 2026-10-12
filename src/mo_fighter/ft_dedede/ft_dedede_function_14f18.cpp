#include <so/so_module_accesser.h>
#include <math.h>

struct DededeLaunchFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct DededeLaunchParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    DededeLaunchFlags flags;
};
struct DededeLaunchObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char middle[0x1e68];
    int* variant;
};
struct DededeLaunchEnergy {
    unsigned char prefix[8];
    Vec2f speed;
};
extern "C" {
extern const float lbl_117_rodata_A8[];
extern const char lbl_117_data_9254[], lbl_117_data_36A8[];
void fn_27_1D8370(void*, const DededeLaunchParam*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_117_15158(Vec2f*, float, float);
}

extern "C" void fn_117_14F18(DededeLaunchObject* object, int resource, int unused,
    int parameter, const Vec3f* position, int reverse, float horizontal, float angle) {
    const float* constants = lbl_117_rodata_A8;
    float facing;
    if (reverse) {
        object->accesser->getWorkManageModule().onFlag(0x22000000);
        angle = constants[4] - angle;
        facing = constants[1];
    } else {
        object->accesser->getWorkManageModule().offFlag(0x22000000);
        facing = constants[0];
    }
    int variant = *object->variant;
    DededeLaunchParam initialize;
    initialize.resource = resource;
    initialize.team = 0xffff;
    initialize.teamOwner = 0xffff;
    initialize.teamAnother = 0xffff;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, position, sizeof(Vec3f));
    initialize.facing = facing;
    initialize.parameter = parameter;
    initialize.variant = variant;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved2 = 0;
    initialize.motion = 0x35f;
    initialize.reserved3 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = 0;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;
    fn_27_1D8370(object, &initialize);
    float vertical;
    float speed = constants[5];
    angle = constants[6] * angle;
    DededeLaunchEnergy* energy = static_cast<DededeLaunchEnergy*>(__dynamic_cast(
        object->accesser->getKineticModule().getEnergy(0), 0,
        lbl_117_data_9254, lbl_117_data_36A8, 1));
    vertical = sin(angle);
    float cosine = cos(angle);
    Vec2f velocity;
    fn_117_15158(&velocity, horizontal * (speed * cosine), speed * vertical);
    energy->speed.m_x = velocity.m_x;
    energy->speed.m_y = velocity.m_y;
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
}
