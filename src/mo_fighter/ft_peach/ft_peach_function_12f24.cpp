#include <memory.h>
#include <types.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;
};

struct PeachFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct PeachInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3 position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    PeachFlags flags;
};

extern "C" {
extern const float lbl_103_rodata_44;
Vec3* fn_103_9594(Vec3*, float, float, float);
void fn_27_1D8370(void*, const PeachInitialize*);

void fn_103_12F24(void* object, int resource, int team, int teamAnother, int parameter) {
    Vec3 position;
    PeachInitialize initialize;
    fn_103_9594(&position, lbl_103_rodata_44, lbl_103_rodata_44, lbl_103_rodata_44);
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = lbl_103_rodata_44;
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
    initialize.teamAnother = teamAnother;
    fn_27_1D8370(object, &initialize);
}
}
