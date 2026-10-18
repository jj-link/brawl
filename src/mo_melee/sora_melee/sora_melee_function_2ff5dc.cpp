#include <so/so_module_accesser.h>
#include <math.h>
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
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};

struct Object {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" {
    extern const float lbl_27_rodata_6534;
    void fn_27_1D8370(void*, const Param*);
}

extern "C" void fn_27_2FF5DC(
    Object* object, int resource, int unused, int parameter, int value)
{
    Vec3f position;
    position.m_x = lbl_27_rodata_6534;
    position.m_y = lbl_27_rodata_6534;
    position.m_z = lbl_27_rodata_6534;

    Param initialize;
    initialize.resource = resource;
    initialize.team = 0xffff;
    initialize.teamOwner = 0xffff;
    initialize.teamAnother = 0xffff;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(Vec3f));
    initialize.facing = lbl_27_rodata_6534;
    initialize.parameter = parameter;
    initialize.variant = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved2 = 0;
    initialize.motion = 0x35f;
    initialize.reserved3 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = 1;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;

    fn_27_1D8370(object, &initialize);
    object->accesser->getWorkManageModule().setInt(value, 0x10000007);
    object->accesser->getWorkManageModule().setFloat(
        lbl_27_rodata_6534, 0x11000001);
    object->accesser->getWorkManageModule().setInt(0, 0x10000006);
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
}
