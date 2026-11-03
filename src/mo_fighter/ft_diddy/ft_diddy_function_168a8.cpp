#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on
struct LaunchFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct LaunchInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    LaunchFlags flags;
};
struct LaunchParameters {
    int value;
    float a;
    float b;
};
struct LaunchObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char middle[0x2524];
    LaunchParameters* parameters;
};
extern "C" {
void fn_27_1D8370(void*, const LaunchInitialize*);

void fn_115_168A8(LaunchObject* object, int resource, int team, int parameter,
                  const Vec3f* position, const Vec2f* speed, float facing,
                  float scale, int mode)
{
    LaunchInitialize initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, position, sizeof(Vec3f));
    initialize.facing = facing;
    initialize.parameter = parameter;
    initialize.variant = 0;
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

    object->accesser->getWorkManageModule().setFloat(scale, 0x21000000);
    object->accesser->getWorkManageModule().setFloat((float)object->parameters->value, 0x21000003);
    if (mode != 0) {
        object->accesser->getStatusModule().changeStatusForce(2, object->accesser);
    } else {
        float offset = object->parameters->a;
        offset += scale * object->parameters->b;
        object->accesser->getWorkManageModule().setFloat(offset, 0x21000002);
        object->accesser->getWorkManageModule().setFloat(speed->m_x, 0x21000004);
        object->accesser->getWorkManageModule().setFloat(speed->m_y, 0x21000005);
        object->accesser->getStatusModule().changeStatusForce(1, object->accesser);
    }
}
}
