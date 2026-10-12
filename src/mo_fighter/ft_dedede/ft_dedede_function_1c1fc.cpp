#include <mo_fighter/ft_dedede/ft_dedede_projectile_launch.h>
#include <so/so_module_accesser.h>
#include <math.h>

struct DededeProjectileFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct DededeProjectileInitializeParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    DededeProjectileFlags flags;
};
struct DededeProjectileParameters {
    float speed;
    int variant;
};
struct DededeProjectileObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char middle[0x1f50];
    DededeProjectileParameters* parameters;
};
struct DededeProjectileEnergy {
    unsigned char prefix[8];
    Vec2f speed;
};
extern "C" {
extern const float lbl_117_rodata_F8;
extern const char lbl_117_data_9254[], lbl_117_data_36A8[];
void fn_27_1D8370(void*, const DededeProjectileInitializeParam*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_117_15158(Vec2f*, float, float);
}

extern "C" void fn_117_1C1FC(Weapon* article, unsigned int taskId, unsigned int resourceId,
    int parameter, const Vec3f* position, float facing, float angle) {
    DededeProjectileObject* object = reinterpret_cast<DededeProjectileObject*>(article);
    int variant = object->parameters->variant;
    DededeProjectileInitializeParam initialize;
    initialize.resource = taskId;
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
    float speed = object->parameters->speed;
    angle = lbl_117_rodata_F8 * angle;
    DededeProjectileEnergy* energy = static_cast<DededeProjectileEnergy*>(__dynamic_cast(
        object->accesser->getKineticModule().getEnergy(0), 0,
        lbl_117_data_9254, lbl_117_data_36A8, 1));
    vertical = sin(angle);
    float cosine = cos(angle);
    Vec2f velocity;
    fn_117_15158(&velocity, facing * (speed * cosine), speed * vertical);
    energy->speed.m_x = velocity.m_x;
    energy->speed.m_y = velocity.m_y;
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
}
