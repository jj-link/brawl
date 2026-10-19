#include <so/so_module_accesser.h>
#pragma force_active on

struct KirbyInitializeObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

struct KirbyInitializeVector {
    float x, y, z;
};

struct KirbyInitializeFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct KirbyInitializeParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    KirbyInitializeVector position;
    float facing;
    int parameter, reserved2, situation, status, reserved3, motion, reserved4;
    KirbyInitializeFlags flags;
};

extern "C" {
extern const float lbl_96_rodata_55C;
void fn_27_1D8370(void*, const KirbyInitializeParam*);

void fn_96_25CDC(KirbyInitializeObject* object, int resource, int team, int value) {
    KirbyInitializeVector position = {
        lbl_96_rodata_55C,
        lbl_96_rodata_55C,
        lbl_96_rodata_55C
    };
    KirbyInitializeParam initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = lbl_96_rodata_55C;
    initialize.parameter = -1;
    initialize.reserved2 = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved3 = 0;
    initialize.motion = 0x35f;
    initialize.reserved4 = 0;
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
    object->accesser->getStatusModule().changeStatusForce(
        value ? 1 : 0, object->accesser);
}
}
