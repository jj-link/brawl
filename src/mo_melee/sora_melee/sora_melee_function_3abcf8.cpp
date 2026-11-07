#include <mt/mt_vector.h>
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
extern "C" {
extern const float lbl_27_rodata_7F64;
void fn_27_1D8370(void*, const Param*);
void* __memcpy(void*, const void*, unsigned long);
void fn_27_3ABCF8(void* object, int resource, int team) {
    Param p;
    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;
    Vec3f position;
    position.m_x = lbl_27_rodata_7F64;
    position.m_y = lbl_27_rodata_7F64;
    position.m_z = lbl_27_rodata_7F64;
    __memcpy(&p.position, &position, sizeof(Vec3f));
    p.facing = lbl_27_rodata_7F64;
    p.parameter = -1;
    p.variant = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved2 = 0;
    p.motion = 0x35f;
    p.reserved3 = 0;
    p.flags.first = 1;
    p.flags.second = 1;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;
    fn_27_1D8370(object, &p);
}
}