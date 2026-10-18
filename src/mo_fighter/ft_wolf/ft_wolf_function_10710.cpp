#include <so/stageobject.h>
#include <memory.h>
#pragma force_active on

struct WolfInitializeFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct WolfInitializeParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    WolfInitializeFlags flags;
};

extern "C" {
extern const float lbl_125_rodata_1C;
void fn_27_1D8370(void*, const WolfInitializeParam*);
void fn_27_311D50(void*, unsigned char, int);

void fn_125_10710(StageObject* object, unsigned int taskId, int unused,
                  int parameter, unsigned char flag, int value, float facing) {
    Vec3f position;
    position.m_x = lbl_125_rodata_1C;
    position.m_y = lbl_125_rodata_1C;
    position.m_z = lbl_125_rodata_1C;

    WolfInitializeParam initialize;
    initialize.resource = taskId;
    initialize.team = 0xffff;
    initialize.teamOwner = 0xffff;
    initialize.teamAnother = 0xffff;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
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
    initialize.flags.ninth = 1;
    fn_27_1D8370(object, &initialize);
    fn_27_311D50(object->m_moduleAccesser, flag, value);
}
}
