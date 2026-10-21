#include <memory.h>
#pragma force_active on

struct FtVec3f {
    float x, y, z;
};

struct WarioFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct WarioInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    FtVec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    WarioFlags flags;
};

extern "C" {
extern const float lbl_110_rodata_1C0;
void fn_110_CC98(FtVec3f*, float, float, float);
void fn_27_1D8370(void*, const WarioInitialize*);

void fn_110_1C7D8(void* object, int resource, int team, int parameter) {
    FtVec3f position;
    WarioInitialize initialize;

    fn_110_CC98(&position, lbl_110_rodata_1C0,
                lbl_110_rodata_1C0, lbl_110_rodata_1C0);

    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = lbl_110_rodata_1C0;
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
}
}
