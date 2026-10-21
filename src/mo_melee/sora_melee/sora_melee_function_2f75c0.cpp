#include <so/stageobject.h>
#pragma force_active on

struct LaunchFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct LaunchParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    LaunchFlags flags;
};

extern "C" {
extern const float lbl_27_rodata_64E4;
void fn_27_1D8370(void*, const LaunchParam*);
}

extern "C" void fn_27_2F75C0(
    StageObject* object, int resource, int team, int another,
    int index, int owner, int parameter)
{
    LaunchParam initialize;
    Vec3f position(
        lbl_27_rodata_64E4,
        lbl_27_rodata_64E4,
        lbl_27_rodata_64E4);

    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(Vec3f));
    initialize.facing = lbl_27_rodata_64E4;
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

    initialize.teamAnother = another;
    initialize.index = index;
    initialize.owner = owner;
    initialize.flags.tenth = 1;

    fn_27_1D8370(object, &initialize);
    object->m_moduleAccesser->getStatusModule().changeStatusForce(
        0, object->m_moduleAccesser);
}
