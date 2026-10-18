#include <so/so_module_accesser.h>
#include <memory.h>
#pragma force_active on

struct Flags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct Param {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, reserved2, situation, status, reserved3, motion, reserved4;
    Flags flags;
};

struct Object {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char middle[0x20e4 - 0x64];
    float* value;
};

extern "C" {
extern const float lbl_121_rodata_80;
extern const float lbl_121_rodata_78;
Vec3f* fn_121_AC08(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const Param*);

void fn_121_13904(Object* object, int resource, int team, int parameter) {
    Vec3f position;
    fn_121_AC08(&position, lbl_121_rodata_80,
               lbl_121_rodata_80, lbl_121_rodata_80);

    Param initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = lbl_121_rodata_78;
    initialize.parameter = parameter;
    initialize.reserved2 = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved3 = 0;
    initialize.motion = 0x35f;
    initialize.reserved4 = 0;
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

    soModuleAccesser* accesser = object->accesser;
    accesser->getStatusModule().changeStatusForce(0, accesser);
    object->accesser->getWorkManageModule().onFlag(0x12000000);
    object->accesser->getGroundModule().setOffsetY(*object->value, 0);
    accesser = object->accesser;
    accesser->getStatusModule().changeStatusForce(1, accesser);
}
}
